#include <iostream>
#include <cmath>

void uh(int s, int s1, int s2, int s3) {
   
   if (s < s1 + s2 + s3) {
      std::cout << "Out" << std::endl;
   } else if (s1 * s2 * s3 == 0) {
      std::cout << "On" << std::endl;
   } else {
      std::cout << "In" << std::endl;
   }
}

int main() {
	int x1, y1, x2, y2, x3, y3, x, y;
   std::cin >> x1 >> y1;
   std::cin >> x2 >> y2;
   std::cin >> x3 >> y3;
   std::cin >> x >> y;
    int s = abs((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
    int s1 = abs((x1 - x) * (y2 - y) - (y1 - y) * (x2 - x));
    int s2 = abs((x1 - x) * (y3 - y) - (y1 - y) * (x3 - x));
    int s3 = abs((x2 - x) * (y3 - y) - (y2 - y) * (x3 - x));
	uh(s,s1,s2,s3);
}
