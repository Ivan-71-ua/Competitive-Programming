#include <iostream>
#include <cmath>


double distance(int x1, int y1, int z1, int x2, int y2, int z2) {
   return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) + pow(z2 - z1, 2));
}

int main() {
   int x1, y1, z1, x2, y2, z2, x3, y3, z3;
   std::cin >> x1 >> y1 >> z1 >> x2 >> y2 >> z2 >> x3 >> y3 >> z3;
   double a = distance(x1, y1, z1, x2, y2, z2);
   double b = distance(x2, y2, z2, x3, y3, z3);
   double c = distance(x3, y3, z3, x1, y1, z1);
   double s = (a + b + c) / 2;
   double triangle_area_value = sqrt(s * (s - a) * (s - b) * (s - c));

   double inradius_value = triangle_area_value / s;
   double circumradius_value = (a * b * c) / (4 * triangle_area_value);
   double ratio = pow(inradius_value, 2) / pow(circumradius_value, 2);

   if (std::abs(ratio) < 0.001) {
      std::cout << "Zero!" << std::endl;
   } else {
      std::cout.precision(3);
      std::cout << std::fixed << ratio << std::endl;
   }
   return 0;
}
