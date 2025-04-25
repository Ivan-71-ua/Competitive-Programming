#include <bits/stdc++.h>
using namespace std;

class My_class
{
private :
	int *date;
	int Size;
public:
	My_class(int size) {
		cout << "constr " << this << endl;
		this->Size = size;
		this->date = new int[size];
		for (int i = 0; i < size; i++)
		{
			date[i] = i;
		}
	}
	
	My_class(const My_class &other) {
		cout << "copy constr " << this << endl;
		this->Size = other.Size;	
		this->date = new int(other.Size);
		for (int i = 0; i < other.Size; i++)
		{
			this->date[i] = other.date[i];
		}
	}
	~My_class() {
		cout << "deconstr " << this << endl;
		delete[] date;
	}
};
void Pr() {
	My_class A(9);
	My_class B(A);
}
int main() {
	// Pr();
	My_class A(9);
	My_class B(A);
	cout  << "kk";
} 	