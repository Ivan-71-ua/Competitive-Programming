#include <iostream>
using namespace std;
int main() {
   double a, b, c, d, e, f;
   cin >> a >> b >> c >> d >> e >> f;
   
    // One of the left parts is zero except right
   if((a==0 && b==0 && e!=0) || (c==0 && d==0 && f!=0))
   {
      cout << "0";
   }
    // k1 = k2, but b1 != b2
   else if( ((a/b)==(c/d)) && ((e/b)!=(f/d)) && (a!=0 && b!=0 && c!=0 && d!=0))
   {
      cout << "0";
   }
    // k1 = k2 and b1 == b2
   else if(((a/b)==(c/d)) && ((e/b)==(f/d)) && (a!=0 && b!=0 && c!=0 && d!=0))
   {
      cout << "1 " << -(a/b) << " " << (e/b);
   }
    // All coefficients are zero
   else if(a==0 && b==0 && c==0 && d==0 && e==0 && f==0)
   {
      cout << "5";
   }
    // Standart evaluation
   else if((a!=0 && b!=0 && c!=0 && d!=0) || (a==0 && b!=0 && c!=0 && d!=0) || (a!=0 && b==0 && c!=0 && d!=0) || (a!=0 && b!=0 && c==0 && d!=0) || (a!=0 && b!=0 && c!=0 && d==0))
   {
      double x = (f*b-d*e)/(c*b-d*a); 
      double y = (f*a-c*e)/(d*a-c*b);
      if(x==-0) x = 0;
      if(y==-0) y = 0;
      cout << "2 " << x << " " << y;
   }
    // First line of coefficients is zero
   else if(a==0 && b==0 && e==0)
   {
      if(d!=0 && c!=0) cout << "1 " << -(c/d) << " " << (f/d);
      else if(d==0) cout << "3 " << (f/c);
      else if(c==0) cout << "4 " << (f/d);
   }
    // Second line of coefficients is zero
   else if(c==0 && d==0 && f==0)
   {
      if(b!=0 && a!=0) cout << "1 " << -(a/b) << " " << (e/b);
      else if(b==0) cout << "3 " << (e/a);
      else if(a==0) cout << "4 " << (e/b);
   }
    // Cross coefficients 1
   else if(a==0 && d==0)
   {
      double x = f/c;
      double y = e/b;
      if(x==-0) x = 0;
      if(y==-0) y = 0;
      cout << "2 " << x << " " << y;
   }
    // Cross coefficients 2
   else if(c==0 && b==0)
   {
      double x = e/a;
      double y = f/d;
      if(x==-0) x = 0;
      if(y==-0) y = 0;
      cout << "2 " << x << " " << y;
   }
    // Horizontal line
   else if(a==0 && c==0)
   {
      if((e/b)==(f/d))
      {
            cout << "4 " << (e/b);
      }
      else
      {
            cout << "0";
      }
   }
    // Vertical line
   else if(b==0 && d==0)
   {
      if((e/a)==(f/c))
      {
            cout << "3 " << (e/a);
      }
      else
      {
            cout << "0";
      }
   }
   
   return 0;
}