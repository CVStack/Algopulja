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
ll arr[100001];

int main(void)
{
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	int T;
	for (int n = 1; n <= N; n++) {
		cin >> T;
		if (T == 0) {
			cout << "SYJKGW\n";
			continue;
		}
		for (int t = 1; t <= T; t++) {
			cin >> arr[t];
		}
		sort(arr + 1, arr + 1 + T);

		ll mid = (T >> 1) + 1;
		ll pre = arr[1];
		ll cnt = 1;
		LL myMax = { pre,cnt };
		for (int t = 2; t <= T; t++) {
			if (pre == arr[t]) {
				cnt++;
			}
			else {
				if (myMax.second < cnt) {
					myMax = { pre,cnt };
				}
				pre = arr[t];
				cnt = 1;
			}
		}
		if (myMax.second < cnt) {
			myMax = { pre,cnt };
		}

		if (myMax.second >= mid) {
			cout << myMax.first << "\n";
		}
		else {
			cout << "SYJKGW\n";
		}
	}
}

