#include <iostream>
#include "vec3.h"

int main() {
  Vec3 a(1,2,3);
  Vec3 b(4,5,6);

  Vec3 c = a + b;

  std::cout << c.x() << " "
            << c.y() << " "
            << c.z() << std::endl;

}
