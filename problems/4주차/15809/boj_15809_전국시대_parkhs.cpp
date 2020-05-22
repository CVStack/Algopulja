#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,x,y;

int rank_a[100001]; // ���� ���� ���� ��Ÿ�� 
int root[100001]; // �ڽ��� �θ� ��Ÿ�� 

void union_set(int type, int r1, int r2) { //root1, root2
	
	//����
	if(type == 2) {
		if(rank_a[r1] < rank_a[r2]) { //���¼���  �ι�° Ʈ���� ũ�� 
			root[r1] = r2;
			rank_a[r2] -= rank_a[r1];  
		}
		
		else if(rank_a[r1] > rank_a[r2]) { //���¼���  ù��° Ʈ���� �� ũ�� 
			root[r2] = r1;
			rank_a[r1] -= rank_a[r2];
		}
		
		else { //���� ��� ��� 
			root[r2] = -1;
			root[r1] = -1;
		}
	} 
	else { //������ ��� ���� ���� ��ģ��. 
		root[r1] = r2;
		rank_a[r2] += rank_a[r1];
	}
}

int find(int x) { 
	
	if(!root[x]) //x�� root �ϰ�� 
		return x;

	int temp = x;
	while(root[temp]) {
		temp = root[temp];
	}
	 // �ش������ �ιǷ� ��Ʈ�� ����.
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
