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

int N, M;
bool broken[10];
int myMin;
string num;
int len;

int diff(int num) {
	return num > N ? num - N : N - num;
}

void dfs(int now, int cnt) {
	myMin = min(myMin, cnt + diff(now));
	if (cnt == len) return;

	for (int i = 0; i <= 9; i++) {
		if (broken[i]) continue;
		int next;
		if (now == 0) next = i;
		else next = now * 10 + i;
		dfs(next, cnt + 1);
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
	num = to_string(N);
	len = min((signed)num.size() + 1, 6);
	cin >> M;
	int temp;
	for (int m = 1; m <= M; m++) {
		cin >> temp;
		broken[temp] = 1;
	}

	myMin = diff(100);

	for (int i = 0; i <= 9; i++) {
		if (broken[i]) continue;
		int next = i;
		dfs(next, 1);
	}

	cout << myMin << "\n";
}

