#include <bits/stdc++.h>
#include <exception>
using namespace std;

void Foo(int n) {
	if (n == 0) {
		throw runtime_error("Num is ()");
	}
	if(n < 0) {
		throw "Number is < 0";
	}
	if(n == 1) {
		throw 1;
	}
	cout << "Number " << n << endl;
}

int main()
{
	try {
		Foo(-9);
	}
	catch (exception &ex){
		cout << ex.what();
	}
	catch (const char *ex) {
		cout << ex;
	}
	catch(...) {
		cout << "Something is wrong!!!";
	}
}