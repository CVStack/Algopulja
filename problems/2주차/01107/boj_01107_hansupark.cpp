#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int n,m;
bool una[10]; //불가능하면 1 

bool check(int n) {
	
	int divide = 1;
	int temp;
	
	0 /1 = 0
	
	if(!n) {
		
		if(!una[n])
			return 1;
		else 
			return 0; 
	}
	   
	while((temp = n / divide)) {
		
		if(una[temp % 10])
			return 0;
		divide *= 10;
	}
	return 1;
}

int int_length(int n) {

	int count = 0;
	int divide = 1;
	
	if(!n)
		return 1;
		
	while (n / divide) {
		count++;
		divide *= 10;
	}
	
	return count;
}

int main()
{
	
//	freopen("input.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	
	cin >> m;
	
	for(int x = 0 ; x < m ; x++) {
		int temp;
		cin >> temp;
		
		una[temp] = 1;	
	}
	
	int min_arr = INT_MAX;
	int result;
	
	for(int x = 0 ; x <= 1000000; x++) {
		
		if(check(x)) {
//			cout << int_length(x) << " "  << abs(x - n) << '\n';
			result = int_length(x) + abs(x - n); //
			if(min_arr > result)
				min_arr = result;
		}
	}
	
	if(min_arr > abs(100 - n))
		cout << abs(100-n) << '\n';
	else
		cout << min_arr << '\n'; 
		
}
