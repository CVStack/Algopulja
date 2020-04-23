#include <iostream>
#include <vector>

using namespace std;

int N;
vector<pair<int,int>> s;
int Max = 0;

void cal(int current, int index) {
		
	for(int x = index ; x <= N - 1 ; x++) {
		int temp = current;
		
		if(x + (s.at(x)).first <= N) {
//			printf("%d + %d -> temp \n",temp,(s.at(x)).second);
			temp += (s.at(x)).second; // value
			if(Max < temp) {
//				printf("%d -> %d\n",Max,temp);
				Max = temp;
			}
			cal(temp, x + (s.at(x)).first);
		}
	}
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> N;
	for(int x = 0 ; x < N ; x++) {
		int T,P;
		cin >> T >> P;
		s.push_back(make_pair(T,P));
	}
	
	for(int x = 0 ; x < N ; x++)
		cal(0,x);
	
	cout << Max << '\n';	
}
