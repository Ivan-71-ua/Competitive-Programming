#include <iostream>
#include <queue>
using namespace std;

class State{
	public:
		int pos,steps;
		State(int p,int s){
			pos = p;
			steps = s;
		}
};

int main() {
	int f,s,g,u,d;
	queue<State> q;
	cin>>f>>s>>g>>u>>d;
	bool visited[1000001];
	fill_n(visited,1000001,false);
	visited[s] = true;
	State curr = State(s,0);
	q.push(curr);
	while(!q.empty()){
		curr = q.front();
		q.pop();
		if(curr.pos == g){
			cout<<curr.steps<<endl;
			break;
		}
		if(curr.pos+u<=f && !visited[curr.pos+u]){
			State newState = State(curr.pos+u,curr.steps+1);
			q.push(newState);
			visited[curr.pos+u] = true;
		}
		if(curr.pos-d>=1 && !visited[curr.pos-d]){
			State newState = State(curr.pos-d,curr.steps+1);
			q.push(newState);
			visited[curr.pos-d] = true;
		}
	}
	if(visited[g] == false){
		cout<<"use the stairs"<<endl;
	}
	return 0;
}