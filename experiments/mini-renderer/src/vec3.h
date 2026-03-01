#pragma once

class Vec3
{
public:
    double e[3];
    
    //constructors
    Vec3() : e{0,0,0} {}
    Vec3(double e0, double e1, double e2) : e{e0, e1, e2} {}

    //accessors
    double x() const {return e[0];}
    double y() const {return e[1];}
    double z() const {return e[2];}

    //binary subtraction
    Vec3 operator-(const Vec3& other) const {
      return Vec3(
          e[0] - other.e[0],
          e[1] - other.e[1],
          e[2] - other.e[2]
        );
    }
    
    //unary sum 
    Vec3 operator+(const Vec3& other) const {
      return Vec3(
          e[0] + other.e[0],
          e[1] + other.e[1],
          e[2] + other.e[2]
          );
    } 
    Vec3 operator*(const Vec3& other) const {             
      return Vec3(                                            
          e[0] * other.e[0],                              
          e[1] * other.e[1],                              
          e[2] * other.e[2]                               
          );                                              
  
    }
    Vec3 operator/(double t) const {
      return Vec3(
          e[0]/t,
          e[1]/t,
          e[2]
          )
    }
};

inline double dot(const Vec3& a, const Vec3& b) {
       return a.e[0] * b.e[0] +
              a.e[1] * b.e[1] +
              a.e[2] * b.e[2]; 
     }

double length_squared() const { 
  return e[0]*e[0]+
         e[1]*e[1]+
         e[2]*e[2];
} 

double length() const {
  return std::sqrt(length_squared());
}

inline Vec3 unit_vector(const Vec3& v ) {
  return v / v.length();
}

