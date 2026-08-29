# Ray Tracing in One Weekend -- C++ Implementation

Completed path tracer built from scratch following Peter Shirley's *Ray Tracing in One Weekend*.

## Latest Render

<!-- update-zone -->
![Latest Render](renders/output.png)

*`renders/output.png` -- updated 2026-08-29*
<!-- /update-zone -->

That block is generated. Commit a new PNG under `renders/` and push to `main`, and
[`latest-render.yml`](.github/workflows/latest-render.yml) rewrites it to show that image. To refresh
it yourself before committing:

```
./scripts/update-latest-render.sh
```

## Features

- Vec3 math library (vector arithmetic, dot/cross product, unit vectors)
- Ray class with origin/direction and parameterized point evaluation
- Camera with configurable FOV, aperture, and focus distance
- Antialiasing via multi-sample averaging
- Diffuse (Lambertian), metal, and dielectric (glass) materials
- Positionable camera with depth-of-field blur
- Final scene: large random sphere field with three featured spheres

## Build

```
cmake -S . -B build
cmake --build build
```

Compiles with `g++ -std=c++17 -O2` through CMake.

## Render

```
./build/raytracer > renders/output.ppm && magick renders/output.ppm renders/output.png
```

Outputs a PPM image and converts it to PNG. The GitHub Actions workflow refreshes `renders/output.png` automatically after rendering-related changes are pushed to `main`, and the README follows it.

## Clean

```
rm -rf build
```
