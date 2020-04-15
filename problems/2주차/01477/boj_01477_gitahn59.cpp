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

int N, M, L;
int arr[110];
int dist[110];

bool judge(int gap) {
	int cnt = 0;
	for (int i = 1; i <= N + 1; i++) {
		cnt += dist[i] / gap;
		if (dist[i] % gap == 0) cnt--;
	}
	return cnt <= M;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> L;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}
	arr[0] = 0;
	arr[N + 1] = L;
	sort(arr, arr + 2 + N);
	for (int n = 1; n <= N + 1; n++) {
		dist[n] = arr[n] - arr[n - 1];
	}

	int l, r;
	l = 1; r = 1000;
	while (l < r) {
		int mid = (l + r) >> 1;
		if (judge(mid) == 1) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << l << "\n";
}

