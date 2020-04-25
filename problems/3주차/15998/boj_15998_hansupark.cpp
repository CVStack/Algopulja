#include <iostream>
#include <vector>
#include <cmath>

#define Max_remind 9000000000000000000

using namespace std;

int n;
struct Data{
	long long x,y;
};

long long remind[300000]; //잔액 
vector<Data> v;

long long gcd(long long x, long long y) { // x > y
	
//	cout << x << " " << y << '\n';
	if(!y)
		return x;
	else
		return gcd(y, x%y);
}

long long return_common_divsor() {
		
	Data& z = v.front();
	long long result = z.y - z.x;
	long long i_temp;
	
	for(int x = 1 ; x < v.size() ; x++) {
		Data& temp = v.at(x);
		i_temp = temp.y - temp.x;
		
		if(i_temp > result)
			result = gcd(i_temp , result);
		else
			result = gcd(result , i_temp);
	}
	
	return result;
}

int main()
{
	long long divide;
	 
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
//	freopen("input.txt","r",stdin);
	
	cin >> n;
	long long a,b;
	long long remind_temp,result;
	Data temp;
	
	for(int x = 0 ; x < n ; x++) {
		
		cin >> a >> b; // a < 0 -> 소모 a >= 0 -> 저축 
		remind[x] = b;
		
		if(x == 0)
			remind_temp = 0;
		else 
			remind_temp = remind[x-1];
				
		if(a + remind_temp < 0) {	
			temp.x = remind_temp + a;
			temp.y = b;
//			cout << temp.x << " " << temp.y << '\n';
			
			if(temp.x - temp.y)
				v.push_back(temp);
		}
		else {
			
			if(a + remind_temp != b) {
				cout << -1 << '\n';
				return 0;
			}
				
		}					
	}	
	
	if(v.empty()) {
		cout << 18 << '\n';
		return 0;
	}
	
//	cout << "Min : " << min << '\n';
	divide = return_common_divsor();
//	cout << "max common divsor : " << divide << '\n';
	
	int index = 0;
	for(Data& d_temp : v) {
		long long a = d_temp.x;
		long long b = d_temp.y;
		
		long long n = (b - a) / divide;
//		printf("(%d + %d * %ld = %d) == %ld\n",(int)a,n,divide,(int)(a + n * divide),(int)b);
						
		if(!(-a % divide) && b)
			break;
		
		index++;
	}
	
	if(v.size() == index && divide <= Max_remind) {
		cout << divide << '\n';
		return 0;
	}	
	
	cout << -1 << '\n';
}
