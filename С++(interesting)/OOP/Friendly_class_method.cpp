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
		Apple(int weight, string color)
		{
			this->color = color;
			this->weight = weight;
		}
		friend void Human ::Take_ap(Apple &ap);
};
int main() {
	Apple D(120, "red");
	Human Ivan;
	Ivan.Take_ap(D);
}
void Human :: Take_ap(Apple &ap) {
	cout << "color: " << ap.color << "weight: " << ap.weight;
} 
