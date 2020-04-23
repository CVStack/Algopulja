#include <iostream>
#include <algorithm>

using namespace std;

int n,m,l;
int arr[1000];
int sub[1000];
int Max;

int return_need_num(int length) { //사이즈가 커지면 parametric search? 
	
	int result = 0;
	 
	for(int x = 0 ; x <= n ; x++) { //n 1000
		if(length < sub[x]) {
			result += sub[x] / length;
			
			if(!(sub[x] % length))
				result--;
		}
	}
	
	return result;
}

int main()
{
	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> l;
	
	arr[0] = 0;	
	for(int x = 1 ; x <= n ; x++)
		cin >> arr[x];
	arr[n+1] = l;	
	sort(arr,arr+n+1);
		
//	for(int x = 0 ; x <= n+1 ; x++)
//		cout << arr[x] << ' ';
//	cout << '\n';
	
//	cout << "sort " << '\n';
	for(int x = 1 ; x <= n+1 ; x++)
		sub[x-1] = arr[x] - arr[x-1]; //차를 저장해줌.
	
//	sort(sub,sub+n+1); //n * lgn
	
//	for(int x = 0 ; x <= n ; x++)
//		cout << sub[x] << ' ';
//	cout << '\n';
	
//	cout << "Max : " << Max << '\n';
	int index;
	int left = 1 , right = 1000;

	while(left < right) { // 1000  
		
//		cout << "left : " << left << " right : " << right << '\n';
		index = (left + right) / 2;
		int result = return_need_num(index); // n 
//		cout << index << " : " << result << '\n';
		
		if(result > m) {
			left = index+1;
		}
		
		else if(result <= m) {
			right = index;
		}
	}			 		
	cout << left << '\n';
}
