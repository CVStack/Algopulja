#include <iostream>

using namespace std;

int n;
int arr[100000];
int sta[100000];

bool result[200000];

int sp = -1;
int input_sp = 1;

int main() 
{
	
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n;
	int temp;
	int res_index = 0;
	
//	for(int x = 0 ; x < n ; x++) 
//		input_sta[x] = x + 1;
	
	sta[++sp] = input_sp++;
	result[res_index++] = 0;
//	cout << "+" << '\n';

	int y;	
	for(y = 0 ; y < n ; y++) {
		cin >> temp;
		if(sta[sp] <= temp) {
//			cout << "sp : " << sta[sp] << '\n';
			while(temp != sta[sp]) {
				sta[++sp] = input_sp++;
//				cout << input_sp << '\n';
				result[res_index++] = 0;
//				cout << "+" << '\n';
			}
			result[res_index++] = 1;
//			cout << "-" << '\n';
			sp--;
		}
		
		else
			break;
	}
	
//	cout << '\n';
	
	if(y != n) {
		cout << "NO" << '\n';
	}
	
	else {
		for(int x = 0 ; x < res_index ; x++) {
			if(result[x])
				cout << "-" << '\n';
			else
				cout << "+" << '\n';
		}
	}
}

