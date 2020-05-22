#include <iostream>

using namespace std;

int n,m,x,y;

int rank_a[101]; // 현재 자신의 높이를 나타냄 
int root[101]; // 자신의 부모를 나타냄 

void union_set(int r1, int r2) { //root1, root2
	
	if(rank_a[r1] < rank_a[r2]) { //높이가 두번째 트리가 크면 
		root[r1] = r2;
	}
	
	else if(rank_a[r1] > rank_a[r2]) { //높이가 첫번째 트리가 더 크면 
		root[r2] = r1;
	}
	
	else { //같을 경우 한쪽의 높이를 1 증가 
		root[r2] = r1;
		rank_a[r1] += 1;
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

int count_root() {
	int count = 0;
	
	for(int x = 1 ; x <= n ; x++) {
		if(!root[x])
			count++;
	}
	
	return count;
} 
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
//	freopen("input.txt","r",stdin);
	
	cin >> n;
	cin >> m;
	
	for(int t = 0 ; t < m ; t++) {
		
		cin >> x >> y;
		int r1, r2;
		for(int z = x ; z <= y - 1 ; z++) { //두개씩 검사. 
			r1 = find(z);
			r2 = find(z+1);
			
//			cout << r1 << ' ' << r2 << '\n';
		
			if(r1 != r2) { //같은 집합에 속하지 않을 때 
				union_set(r1,r2); 
			}	
		}
		 
	}
	
//	for(int t = 1 ; t <= n ; t++) {
//		cout << root[t] << ' ';
//	}
//	cout << '\n';
	
	cout << count_root() << '\n';
}
