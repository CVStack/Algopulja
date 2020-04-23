#include <iostream>

using namespace std;

int N;

int main(void)
{
//	freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	
	int switch_arr[101];
	
	for(int i=1; i<=N; i++){
		cin >> switch_arr[i];
	}
	
	int student_num;
	cin >> student_num;
	
	int gender, num;
	
	for(int i=1; i<=student_num; i++){
		cin >> gender >> num;
	  	if(gender == 1){
	     	for(int j=num; j<=N; j+=num)
	        	switch_arr[j] = !switch_arr[j];
	  	}
	  	else{
	  		
	  		switch_arr[num] = !switch_arr[num];
	     	for(int x = 1 ; num - x >= 1 && num + x <= N ; x++) {
				
				if(switch_arr[num - x] != switch_arr[num + x])
					break;
				switch_arr[num - x] = !switch_arr[num - x];
				switch_arr[num + x] = !switch_arr[num + x]; 
				
			}
	  	}
	     
	}
	
	for(int i = 1 ; i <= N ; i++) {
		cout << switch_arr[i] << ' ';
		if(!(i % 20))    
			cout << '\n';
	}                        
}
