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
};                                                    
