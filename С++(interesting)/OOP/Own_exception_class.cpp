#include <bits/stdc++.h>
#include <exception>
using namespace std;

class MyExeption: public exception {
public:
	MyExeption(string msg, int datasate){
		this->msg = msg;
		this->dataState = datasate;
	}
	int Get_Date() { return dataState; }

private:
	string msg;
	int dataState;
};

void Foo(int n) {
	if(n < 0) {
		throw MyExeption("Number is < ()", 777);
	}
	if(n == 1) {
		throw 1;
	}
	cout << n;
}

int main()
{
	try
	{
		Foo(1);
	}
	catch(MyExeption &ex)
	{
		cout << ex.what() << ex.Get_Date() << '\n';
	}
	catch(int ex) {
		cout << ex;
	}
}