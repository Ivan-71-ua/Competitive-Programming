#include<bits/stdc++.h>
using namespace std;


class Image
{
	public:
	void GetImageInf() {
		for (int i = 0; i < LENGTH; i++)
		{
			cout << pixsel->GetInfo() << endl;
		}
		
	}

	private:
	class Pixel
	{
		public:
		Pixel(int r,int g,int b) {
			this->r = r;
			this->g = g;
			this->b = b;
		}
		string GetInfo() {
			return to_string(r) + " " + to_string(g) + " " + to_string(b);
		}
		private:
			int r;
			int g;
			int b;
	};
	static const int LENGTH = 5;
	Pixel pixsel[5] {
		Pixel(3, 4, 6),
		Pixel(1, 0, 9),
		Pixel(0, 99, 65),
		Pixel(33, 41, 64),
		Pixel(35, 47, 60)
	};
};
int main(){
	Image lac;
	lac.GetImageInf();
}