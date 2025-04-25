#include <bits/stdc++.h>
using namespace std;

class My_class
{
private:
	int *date;
	int Size;
public:
	My_class(int size) {
		this->Size = size;
		this->date = new int[size];
		for (int i = 0; i < size; i++)
		{
			date[i] = i;
		}
		cout << "constr " << this << endl;
	}
	My_class(const My_class &other) {
		this->Size = other.Size;
		this->date = new int[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->date[i] = other.date[i];
		}
		cout << "copy " << this << endl;
	}
	My_class & operator = (const My_class &other) {
		cout << "start operator =\n";
		this->Size = other.Size;
		if(this->date != nullptr) {
			delete[] this->date;
		}
		this->date = new int[other.Size];
		for (int i = 0; i < other.Size; i++)
		{
			this->date[i] = other.date[i];
		}
		return *this;
	}
	~My_class() {
		cout << "deconstr " << this << endl;
		delete[] date;
	}
};

int main() {
	My_class A(9);
	My_class B = A;
	My_class V(8), C(7), D(1);
	V = C = D;
}