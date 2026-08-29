#!/usr/bin/env bash
#
# Points the render zone in README.md at the most recent render.
#
# "Most recent" means:
#   1. a renders/*.png added or modified in the working tree (newest mtime wins), or
#   2. the png from the newest commit that touched renders/*.png -- if that commit
#      added several, the first one alphabetically wins.
#
# Run it by hand before committing a new render, or let the workflows in
# .github/workflows/ run it after a push to main.

set -euo pipefail

cd "$(git rev-parse --show-toplevel)"

readme="README.md"
start='<!-- update-zone -->'
end='<!-- /update-zone -->'

# Renders that are untracked, staged, or modified are newer than anything committed.
pending="$(
  git status --porcelain -- 'renders/*.png' |
    awk '{
      x = substr($0, 1, 1)
      y = substr($0, 2, 1)
      if (x == "D" || y == "D") next
      path = substr($0, 4)
      sub(/.* -> /, "", path)
      print path
    }'
)"

latest=''
if [ -n "$pending" ]; then
  # shellcheck disable=SC2086
  latest="$(ls -1t -- $pending | head -n 1)"
  updated="$(date +%F)"
else
  while IFS= read -r path; do
    { [ -n "$path" ] && [ -f "$path" ]; } || continue
    latest="$path"
    break
  done < <(git log --pretty=format: --name-only --diff-filter=AM -- 'renders/*.png')
  [ -n "$latest" ] && updated="$(git log -1 --format=%ad --date=short -- "$latest")"
fi

if [ -z "$latest" ]; then
  echo "update-latest-render: no image found under renders/*.png" >&2
  exit 1
fi

for marker in "$start" "$end"; do
  if ! grep -qF -- "$marker" "$readme"; then
    echo "update-latest-render: missing '$marker' marker in $readme" >&2
    exit 1
  fi
done

block="$(printf '![Latest Render](%s)\n\n*`%s` -- updated %s*' "$latest" "$latest" "$updated")"

tmp="$(mktemp)"
awk -v start="$start" -v end="$end" -v block="$block" '
  index($0, end)   { skipping = 0; print; next }
  index($0, start) { print; print block; skipping = 1; next }
  !skipping        { print }
' "$readme" > "$tmp"
mv "$tmp" "$readme"

echo "update-latest-render: $readme -> $latest ($updated)"
