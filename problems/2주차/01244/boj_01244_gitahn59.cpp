/*
boj_01244_스위치 켜고 끄기난이도 : 실버3)
단순 시뮬레이션
*/

#include <iostream>
#include <queue>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <cstring>
#include <stack>
#include <cmath>
#include <set>
#include <bitset>
#include <climits>

#define PRIME 1000000007

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> LL;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<ll> vll;
typedef vector<vi> vvi;
typedef deque<int> di;
typedef pair<int, ii> iii;
typedef set<int> si;

int N;

int main(void)
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	int switch_arr[101];

	for (int i = 1; i <= N; i++) {
		cin >> switch_arr[i];
	}

	int student_num;
	cin >> student_num;

	int gender, num;

	for (int i = 1; i <= student_num; i++) {
		cin >> gender >> num;
		if (gender == 1) {
			for (int j = num; j <= N; j += num) {
				switch_arr[j] = !switch_arr[j];
			}
		}
		else {
			switch_arr[num] = !switch_arr[num];
			int l = num;
			int r = num;
			while (true) {
				l--;
				r++;
				if (l<1 || r >N)
					break;
				if (switch_arr[l] == switch_arr[r]) {
					switch_arr[l] = !switch_arr[l];
					switch_arr[r] = !switch_arr[r];
				}
				else {
					break;
				}
			}
		}
	}

	for (int n = 1; n <= N; n++) {
		cout << switch_arr[n] << " ";
		if (n % 20 == 0) {
			cout << "\n";
		}
	}
	cout << "\n";
}
