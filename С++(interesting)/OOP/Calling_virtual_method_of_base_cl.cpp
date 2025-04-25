
#include <bits/stdc++.h>

using namespace std;


class Message{
private:
	string msg;
public:
	Message(string msg) {
		this->msg = msg;
	}
	virtual string Get_msg() {
		return msg;
	}
};

class BraketMSG : public Message{
public:
	BraketMSG(string msg) : Message(msg) {
	}
	string Get_msg() override {
		return "[ " + ::Message::Get_msg() + "]";
	}
};

class Printer {
public:
	void Print_msg(Message *val) {
		cout << val->Get_msg() << endl;
	}
};

int main() {
	Printer p;
	BraketMSG m ("hi");
	p.Print_msg(&m);
}