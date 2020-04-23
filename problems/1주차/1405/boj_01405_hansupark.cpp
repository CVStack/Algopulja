#include <iostream>

using namespace std;

int N;
int arr[14];
bool visit[29][29];
double pro[4];
double result = 0.0;

void DFS(int x , int y, int n) { // 0 : E, 1 : W, 2 :  S, 3 :  N 

	if(n == N) {
		double temp = 1.0;
		for(int x = 0 ; x < N ; x++) {
//			cout << arr[x] << ' ';
			temp *= pro[arr[x]];	
		}
//		cout << '\n';
		result += temp;
		return;
	}
	
	// East
	if(pro[0] && !visit[x + 1][y]) {
		arr[n] = 0;
		visit[x + 1][y] = 1;
		DFS(x + 1 , y , n + 1);
		visit[x + 1][y] = 0;
	}
	
	//West
	if(pro[1] && !visit[x - 1][y]) {
		arr[n] = 1;
		visit[x - 1][y] = 1;
		DFS(x - 1 , y , n + 1);
		visit[x - 1][y] = 0;
	}
	
	//South
	if(pro[2] && !visit[x][y + 1]) {
		arr[n] = 2;
		visit[x][y + 1] = 1;
		DFS(x, y + 1, n + 1);
		visit[x][y + 1] = 0;
	}
	
	//North
	if(pro[3] && !visit[x][y - 1]) {
		arr[n] = 3;
		visit[x][y - 1] = 1;
		DFS(x, y - 1, n + 1);
		visit[x][y - 1] = 0;
	}
}

int main()
{
	double temp;
	cin >> N;
	
	for(int x = 0 ; x < 4 ; x++) {
		cin >> temp;
		pro[x] = temp / 100;
	}
	visit[14][14] = 1;	
	DFS(14,14,0);	
	
	cout << fixed;
	cout.precision(10);
	cout << result << '\n';
}
