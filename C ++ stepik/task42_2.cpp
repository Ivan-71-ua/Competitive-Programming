#include <iostream>

using namespace std;
int main() 
{
  // put your code here
    int N = 0, a = 0, b = 0, c = 0, counter = 0, max = 1, min = 60000;
    cin >> N;
    a = N;
    cin >> N;
    b = N;
    cin >> N;
    c = N;
  while(N > 0)
    {
      if (a < b && b > c)
      {
        
          counter++;

          if (max <= min && counter >= 2)
          {
  
              min = max;
              max = 1;
          }
          max=1;
      }
        else 
    {
 
        max++;

    }
      cin >> N;
      a = b;
      b = c;
      c = N;
    }       
    if (counter < 2)
    {
        cout << 0;
    }
    else
    {
    cout << min;
    }  
  return 0;
}