#include <bits/stdc++.h>
using namespace std;

class Human;
class Apple;

class Human {
	public:
		void Take_ap(Apple &ap);
};
class Apple {

private:
	int weight;
	string color;

public:
	static int Count1;
	Apple(int weight, string color)
	{
		this->color = color;
		this->weight = weight;
		Count1++;
		}
		friend void Human ::Take_ap(Apple &ap);
};

int Apple::Count1 = 0;

int main() {
	Apple D(120, "red");
	Apple B(121, "redoy");
	Human Ivan;
	cout << Apple::Count1<< endl;
}
void Human :: Take_ap(Apple &ap) {
	cout << "color: " << ap.color << "weight: " << ap.weight;
} 
