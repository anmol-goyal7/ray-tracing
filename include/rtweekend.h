#pragma once

#include <cmath>
#include <iostream>
#include <memory>

using std::make_shared;
using std::shared_ptr;

const double pi = 3.1415926535897932385;

inline double degrees_to_radius(double degrees) {
    return degrees * pi / 180.0;
}

#include "color.h"
#include "ray.h"
#include "vec3.h"
#include "interval.h"
