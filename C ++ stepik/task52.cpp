#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
//ax2 + bx + c = 0 
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	double a, b, c;
	cin >> a >> b >> c;
	if(a == 0)
	{
		if(b == 0)
		{
			if(c == 0)
			{
				cout << 3;
			}
			else
			{
				cout << 0;
			}
		}
		else
		{
			if(c == 0)
			{
				cout << 1 << ' ' << 0;
			}
			else
			{
				cout << 1 << ' ' << (-c/b);
			}
		}
	}
	else
	{
		if(b == 0)
		{
			if(c == 0)
			{
				cout << 1 << ' ' << 0;
			}
			else
			{
				if(a > 0 && c < 0 || a < 0 && c > 0)
				{
					cout << 2 << ' ' << -sqrt(-c/a) << ' ' << sqrt(-c/a);
				}
				else
				{
					cout << 0;
				}
			}
		}
		else
		{
			if(c == 0)
			{
				cout << 2 << ' ';
				if((-b/a) < 0)
				{
					cout << (-b/a) << ' ' << 0;
				}
				else
				{
					cout << 0 << ' ' << (-b/a);
				}
			}
			else
			{
				double d = b * b - 4 * a * c;
				if(d == 0)
				{
					cout << 1 << ' ' << (-b/(2*a));
				}
				else if(d > 0)
				{
					double x1 = (-b + sqrt(d))/(2 * a), x2 = (-b - sqrt(d))/(2 * a);
					cout << 2 << ' ';
					if(x1 > x2)
					{
						cout << x2 << ' ' << x1;
					}
					else
					{
						cout << x1 << ' ' << x2;
					}
				}
				else
				{
					cout << 0;
				}
			}
		}
	}
	return 0;
}