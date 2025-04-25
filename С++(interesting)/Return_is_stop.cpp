#include <iostream>
using namespace std;

int main()
{
	int symbolCount;
	char sybol;
	int lineType;
	int index = 0;
	cout << "Enter the number of characters per line" << endl;
	cin >> symbolCount;
	cout << "Enter the symbol" << endl;
	cin >> sybol;
	cout << "Select line type:" << endl
	<< "1 - vertical line" << endl
	<< "2 - horizontal line" << endl;
	cin >> lineType;
	if (lineType!=1 && lineType!=2 )
	{
		cout << "Incorrect line type!" << endl;
		return 0;
	}
	while (index < symbolCount)
	{
		if (lineType == 1)
		{
			cout << sybol << endl;
		}
		if (lineType == 2)
		{
			cout << sybol;
		}
		index++;
	}
	cout << endl << endl;
}