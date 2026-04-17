# Ray Tracing in One Weekend -- C++ Implementation

Building a path tracer from scratch following Peter Shirley's *Ray Tracing in One Weekend* book series.

## Latest Render

<!-- update-zone -->
![Latest Render](renders/latest.png)
<!-- /update-zone -->

## Implemented So Far

- Vec3 math library (vector arithmetic, dot/cross product, unit vectors)
- Ray class with origin/direction and parameterized point evaluation
- Color output with PPM image format
- Image rendering pipeline with progress reporting
- Gradient background (sky) based on ray direction

## Build

```
make
```

Compiles with `g++ -std=c++17 -O2`.

## Render

```
make render
```

Outputs to `renders/latest.ppm` and converts to `renders/latest.png` (requires ImageMagick `convert`).

## Clean

```
make clean
```
