/*
boj_01874_스택 수열(난이도 : 실버3)
스택을 이용해 시뮬레이션
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
#include <tuple>

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

int arr[100001];
bool dist[100001];
int N;

void solve() {
	stack<int> s;
	vi result;
	int now = 1;
	for (int n = 1; n <= N; n++) {
		s.push(n);
		result.push_back(1);
		while (!s.empty() && s.top() == arr[now]) {
			s.pop();
			now++;
			result.push_back(0);
		}
	}

	if (now > N) {
		for (int i : result) {
			if (i == 1) cout << "+\n";
			else cout << "-\n";
		}
	}
	else {
		cout << "NO\n";
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
	}
	solve();

	return 0;
}

