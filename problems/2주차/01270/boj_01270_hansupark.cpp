#include <iostream>
#include <algorithm>

using namespace std;

int n,m;

long long result[200];
long long arr[100001];
int Count[100000];

int main()
{
//	freopen("test.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	int index;
	long long max_num;
	
	for(int x = 0 ; x < n ; x++) {
		cin >> m;
		index = 0;
		
		if(m > 0) {
			
			for(int y = 0 ; y < m ; y++) {
				cin >> arr[y];
			}
		
			sort(arr,arr+m);
			Count[index] = 1;
			
//			for(int y = 0 ; y < m ; y++) 
//				cout << arr[y] << ' ';
//			cout << '\n';
			int current = 0;
			int z;
			  
			for(z = 1 ; z < m ; z++) {
				
				if(arr[z - 1] != arr[z]) { //�����ȣ�� �޶����� ���
					
					if(Count[index] > current) {
						current = Count[index];
						max_num = arr[z-1];
//						cout << "max : " << max_num << '\n';
//						cout << "current : " << current << '\n';
					}
					 
					index++;
				}
				
				Count[index]++;	
			}
			
			if(Count[index] > current) {
				max_num = arr[z-1];
//				cout << "max : " << max_num << '\n';
//				cout << "current : " << current << '\n';
			}
			
			
		}
		
		sort(Count,Count+index+1); //index�� ������ ���Ҹ� ����Ű�� ������ end�� 1�� ����
		
//		for(int z = 0 ; z <= index ; z++)
//			cout << Count[z] << ' ';
//		cout << '\n';
		
//		cout << "max_num : " << max_num << '\n';
		
		if(Count[index] > (m / 2))
			result[x] = max_num;
		else
			result[x] = -1;
			
		for(int z = 0 ; z <= index ; z++)
			Count[z] = 0; 
	}
	
	for(int x = 0 ; x < n ; x++) {
		if(result[x] == -1) 
			cout << "SYJKGW" << '\n';
		else
			cout << result[x] << '\n'; 
			
	}
	
	
		
}
