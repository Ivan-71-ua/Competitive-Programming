#include <bits/stdc++.h>
using namespace std;
#define ll long long

class PC {
public:
	enum PCState
	{
		OFF = 0,
		ON = 1,
		SLEEP = 2
	};
	void Set_State(PCState State) {
		this->State = State;
	}
	PCState Get_State() {
		return State;
	}
private:
	PCState State;
};


int main() {
	PC My;
	My.Set_State(PC::PCState::SLEEP);
	switch (My.Get_State())
	{
	case PC::PCState::ON:
		cout << "WKL";
		break;
	
	case PC::PCState::OFF:
		cout << "WUKL";
		break;
	
	case PC::PCState::SLEEP:
		cout << "Sleep";
		break;
	}
}