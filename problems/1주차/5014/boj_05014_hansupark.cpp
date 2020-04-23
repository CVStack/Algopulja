#include <iostream>
#include <queue>

using namespace std;

struct q_pair {
	int x,y;
	
	q_pair() {}
	
	q_pair(int x, int y) {
		this->x = x;
		this->y = y;
	}
};

bool arr[2000001];

int f,s,g,u,d;
queue<q_pair> q;
int count = 0;

void push_queue(int n,int count) {
// up down °¢°¢ checkÈÄ push 

	q_pair p;
	p.y = count;

	if(u >= 0 && n + u <= f && !arr[n + u]) {
		p.x = n + u;
		q.push(p);
		arr[n+u] = 1;
	}
	
	if(d >= 0 && n - d >= 1 && !arr[n - d] ) {
		p.x = n - d;
		q.push(p);
		arr[n - d] = 1;
	}
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	q_pair temp;
	
	cin >> f >> s >> g >> u >> d;
	
	arr[s] = 1;
	q.push(q_pair(s,0));
	
	while(!q.empty()) {
			
		temp = q.front();
//		cout << temp.x << " " << temp.y << '\n';
		if(temp.y != count)
			count++;
			
		if(temp.x == g) {
			cout << temp.y << '\n';
			return 0;
		}
		
		push_queue(temp.x, count + 1);
		q.pop();
	}
	
	cout << "use the stairs" << '\n';
		
}
