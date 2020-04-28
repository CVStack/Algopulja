/*
boj_17197_Fence Planning (난이도 : 골드5)
서로소 집합
moo 네트워크 구성 -> 네트워크 마다 팬스 둘레 계산
최솟값 출력
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

int N, M;
int prnt[100001];
ii cow[100001];
ii max_cow[100001];

void init(int size) {
	for (int i = 1; i <= size; i++) {
		prnt[i] = i;
	}
}

int getPrnt(int a) {
	if (a == prnt[a]) return a;
	else return prnt[a] = getPrnt(prnt[a]);
}

bool isSet(int a, int b) {
	a = getPrnt(a);
	b = getPrnt(b);
	return a == b;
}

void merage(int a, int b) {
	a = getPrnt(a);
	b = getPrnt(b);
	if (a < b) {
		prnt[b] = a;
	}
	else {
		prnt[a] = b;
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	int x, y;
	init(N);
	for (int n = 1; n <= N; n++) {
		cin >> x >> y;
		cow[n] = { x,y };
		max_cow[n] = { x,y };
	}

	int a, b;
	for (int m = 1; m <= M; m++) {
		cin >> a >> b;
		if (isSet(a, b)) continue;
		else merage(a, b);
	}

	for (int n = 1; n <= N; n++) {
		int p = getPrnt(n);
		cow[p].first = min(cow[p].first, cow[n].first);
		cow[p].second = min(cow[p].second, cow[n].second);

		max_cow[p].first = max(max_cow[p].first, max_cow[n].first);
		max_cow[p].second = max(max_cow[p].second, max_cow[n].second);
	}

	int myMin = INT_MAX;
	for (int n = 1; n <= N; n++) {
		int p = getPrnt(n);
		int temp = abs(max_cow[p].first - cow[p].first) + abs(max_cow[p].second - cow[p].second);
		temp = temp << 1;
		myMin = min(myMin, temp);
	}

	cout << myMin << "\n";

	return 0;
}
