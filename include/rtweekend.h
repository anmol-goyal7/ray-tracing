#pragma once

#include <cstdlib>
#include <cmath>
#include <iostream>
#include <memory>

using std::make_shared;
using std::shared_ptr;

const double pi = 3.1415926535897932385;

inline double degrees_to_radians(double degrees) {
    return degrees * pi / 180.0;
}

#include "random.h"
#include "ray.h"
#include "color.h"
#include "vec3.h"
#include "interval.h"
