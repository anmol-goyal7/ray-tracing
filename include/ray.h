/*
 * ray is a function defined as P(t) = A + tb.
 * A is the ray origin and b is the ray direction, t is a real number which is a ray parameter.
 */
#pragma once
#include "vec3.h"

class ray {
    public:
        ray () {} // this is a default constructor, it does nothing.

        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {}
        /* this is a parameterized constructor which constructs a ray.
         * point3& says that we are defining an origin of the ray which is "A" in the formula
         * similarly we construct the direction with vec3 which is "b"
         */

        const point3& origin() const { return orig; } // return orig when origin is called
        const vec3& direction() const { return dir; } // return dir when direction is called

        point3 at(double t) const { // this is the code translation of the formula "P(t) = A +tb"
            return orig + t*dir;
        }
        
    private:
        point3 orig; //keeping these values private 
        vec3 dir;
};

