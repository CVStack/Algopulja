#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,x,y;

int rank_a[100001]; // 현재 병력 수를 나타냄 
int root[100001]; // 자신의 부모를 나타냄 

void union_set(int type, int r1, int r2) { //root1, root2
	
	//전쟁
	if(type == 2) {
		if(rank_a[r1] < rank_a[r2]) { //병력수가  두번째 트리가 크면 
			root[r1] = r2;
			rank_a[r2] -= rank_a[r1];  
		}
		
		else if(rank_a[r1] > rank_a[r2]) { //병력수가  첫번째 트리가 더 크면 
			root[r2] = r1;
			rank_a[r1] -= rank_a[r2];
		}
		
		else { //같을 경우 멸망 
			root[r2] = -1;
			root[r1] = -1;
		}
	} 
	else { //동맹일 경우 병사 수를 합친다. 
		root[r1] = r2;
		rank_a[r2] += rank_a[r1];
	}
}

int find(int x) { 
	
	if(!root[x]) //x가 root 일경우 
		return x;

	int temp = x;
	while(root[temp]) {
		temp = root[temp];
	}
	 // 해당원소의 부므롤 루트로 지정.
	return (root[x] = temp); 
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	
	vector<int> v;
	cin >> n >> m;
	
	for(int x = 1 ; x <= n ; x++) {
		cin >> rank_a[x];
	}
	
	int o, p, q;
	for(int x = 0 ; x < m ; x++) {
		cin >> o >> p >> q;
		union_set(o, find(p), find(q));
	}
	
	for(int x = 1 ; x <= n ; x++) {	
		if(!root[x]){
			v.push_back(rank_a[x]);
		}
	}
	
	sort(v.begin(), v.end());
	
	cout << v.size() << '\n';
	for(int x : v) {
		cout << x << ' ';
	}
	cout << '\n';
	
	
}
