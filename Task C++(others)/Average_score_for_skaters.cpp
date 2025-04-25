#include <iostream>
#include<iomanip>
using namespace std;
int main()
{
	int n, m; // описали змінні n та m
	cin >> n >> m; // прочитали змінні n та m
	int a[n]; // описали масив a[n]
	for(int i = 0; i < m; i++)// для кожного спортсмена
	{
		int s = 0,k = n, mi = 0,ma = 0;
		for(int j = 0; j < n; j++)
		{
			cin >> a[j];
			if(a[j] > a[ma])ma = j;//знаходимо максимальний
			if(a[j] < a[mi]) mi = j; // знаходимо мінімальний
			s = s + a[j];
		}
		// від суми балів віднімаємо максимальні та мінімальні елементи
		for(int j=0; j<n; j++)
		{
			//віднімаємо усі максимальні
			if( a[j] == a[ma] )
			{
			k--;
			s = s - a[j];
			}
			// віднімаємо усі мінімальні
			if(a[j] == a[mi])
			{
			k--;
			s = s - a[j];
			}
		}
		// якщо оцінок не залишилось, то виводимо нуль
		if(k == 0)cout << 0 << ' ';
		else
		{
			double res = 1.0*s/k;// середній бал спортсмена
			// виводимо результат з точністю до сотих
			cout << fixed << setprecision(2) << res << ' ';
		}
	}
}