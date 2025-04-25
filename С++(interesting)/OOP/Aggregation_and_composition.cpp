#include<bits/stdc++.h>
using namespace std;
class Cap {
	private:
		string color = "red";
	public:
	string GetCL() {
		return color;
	}
};
class Model {
	public:
	void GetClCap() {
		cout << cap.GetCL();
	}
	private :
		Cap cap;
};

class Human
{
	public:
		void Think() {
			Ad.Think();
		}
		void GetClCapOnHead() {
			cout << cap.GetCL();
		}
	private:
		class Brain {
			public:
			void Think() {
				cout << "I am think!";
			}
		};
		Brain Ad;
		Cap cap;
};

int main(){
	Human Ivan;
	Model Pop;
	Ivan.Think();
	Ivan.GetClCapOnHead();
	cout << endl;
	Pop.GetClCap();
}