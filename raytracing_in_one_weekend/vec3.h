#ifndef VEC3_H
#define VEC3_H

#include <cmath> //for std::sqrt 
#include <iostream>

class vec3 
{
  public:
    double e[3]; // think of e[3] as x,y,z directions of a vector where e[0] = x, e[1] = y, e[2] = z.
   
    // Constructors
    vec3() : e{0,0,0} {} //constructing the inital value of vector as 0,0,0 
    vec3(double e0, double e1, double e2) : e{e0, e1, e2} {} // whenever a vec3 is created this array e will carry the value 
    
    // Accessors - These are used as the enforce read only access, calling these functions will not modify the vector
    double x() const { return e[0]; }
    double y() const { return e[1]; }
    double z() const { return e[2]; }

    vec3 operator-() const { return vec3(-e[0], -e[1], -e[2]); } // this defines unary minus for a vector, reverses the value of the vector, completely allowing the vector to bounce back 180 degrees. 
    double operator[](int i) const { return e[i]; } // via this we can read the value of the direction of the vector
    double& operator[](int i) { return e[i]; } // and this function allows us to change the value of the vector

    vec3& operator+=(const vec3& v) {
        e[0] += v.e[0];
        e[1] += v.e[1];
        e[2] += v.e[2];
        return *this;
    } // this is a member function which returns the value of "*this", here this is a pointer and we use "** to dereference it, this += is basically used to change the value of vector

    vec3& operator*=(double t) {
        e[0] *= t;
        e[1] *= t;
        e[2] *= t;
        return *this;
    } // similar to above member function

    vec3& operator/=(double t) {
        return *this *= 1/t;
    } // same

    double length() const {
        return std::sqrt(length_squared());
    } // this is used to return the squared value of the vector, this is used for vector addition  

    double length_squared() const {
        return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
    } // this is also used for vector addition
};

using point3 = vec3; // used for better understanding, vec3 represents the entire vector including direction, color, point in space,
                     // whereas, point3 represents the exact coordinates of the vector, this helps us, not the compiler.



inline std::ostream& operator<<(std::ostream& out, const vec3& v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3& u, const vec3& v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3& u, const vec3& v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3& u, const vec3& v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3& v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3& v, double t) {
    return t * v;
}

inline vec3 operator/(const vec3& v, double t) {
    return (1/t) * v;
}

inline double dot(const vec3& u, const vec3& v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3& u, const vec3& v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(const vec3& v) {
    return v / v.length();
}

#endif
