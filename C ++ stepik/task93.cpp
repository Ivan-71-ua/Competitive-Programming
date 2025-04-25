#include <iostream>
#include <vector>

using namespace std;

//Check the condition
bool promising(const vector<int>& field, int queen_num, int pos) {
   for (int j = 0; j < queen_num; ++j) {
        // check whether a queen intersects with others
      if (field[j] == pos || j - field[j] == queen_num - pos || j + field[j] == queen_num + pos) {
            return false;
      }
   }

   return true;
}
//Backtrack algorithm
void queens(vector<int>& field, int queen_num, int& cnt) {
    // All queens are placed
   if (queen_num == field.size()) {
      ++cnt;
   }
   else {
        // Trying to put a queen into a column
      for (int i = 0; i < field.size(); ++i) {
            // Check whether a queen is not under attack
            if (promising(field, queen_num, i)) {
               field[queen_num] = i;
               queens(field, queen_num + 1, cnt);
            }
      }
   }
}

int main() {
   const int first_queen = 0;
   int n;
    // our chess board
   vector<int> v;
   int cnt = 0;

   cin >> n;
   v = vector<int>(n);
   queens(v, first_queen, cnt);
   cout << cnt;

   return 0;
}