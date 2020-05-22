#include <iostream>

using namespace std;

int n,m,x,y;

int rank_a[101]; // ���� �ڽ��� ���̸� ��Ÿ�� 
int root[101]; // �ڽ��� �θ� ��Ÿ�� 

void union_set(int r1, int r2) { //root1, root2
	
	if(rank_a[r1] < rank_a[r2]) { //���̰� �ι�° Ʈ���� ũ�� 
		root[r1] = r2;
	}
	
	else if(rank_a[r1] > rank_a[r2]) { //���̰� ù��° Ʈ���� �� ũ�� 
		root[r2] = r1;
	}
	
	else { //���� ��� ������ ���̸� 1 ���� 
		root[r2] = r1;
		rank_a[r1] += 1;
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
		for(int z = x ; z <= y - 1 ; z++) { //�ΰ��� �˻�. 
			r1 = find(z);
			r2 = find(z+1);
			
//			cout << r1 << ' ' << r2 << '\n';
		
			if(r1 != r2) { //���� ���տ� ������ ���� �� 
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
