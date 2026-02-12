#ifndef CIRCLE_H
#define CIRCLE_H

#include "vec3.h"
#include "color.h"
#include "ray.h"

bool hit_sphere(const point3& center, double radius, const ray& r);
color ray_color(const ray& r);

#endif

