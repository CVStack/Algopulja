/*
boj_15809_전국시대(난이도 : 실버1)
서로소 집합 
기본 문제
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
int cnt[100001];
bool visited[100001];

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

	int a, b;
	init(N);

	for (int n = 1; n <= N; n++) {
		cin >> cnt[n];
	}

	int o, p, q;
	for (int m = 1; m <= M; m++) {
		cin >> o >> p >> q;
		if (o == 1) {
			p = getPrnt(p);
			q = getPrnt(q);
			int sum = cnt[p] + cnt[q];
			merage(p, q);
			cnt[getPrnt(p)] = sum;
		}
		else {
			p = getPrnt(p);
			q = getPrnt(q);
			int sum = abs(cnt[p] - cnt[q]);
			if (sum == 0) {
				merage(p, 0);
				merage(q, 0);
			}
			else {
				merage(p, q);
				cnt[getPrnt(p)] = sum;
			}
		}
	}

	vi rst;
	for (int n = 1; n <= N; n++) {
		int p = getPrnt(n);
		if (p == 0 || visited[p] == 1) continue;
		visited[p] = 1;
		rst.push_back(cnt[p]);
	}

	sort(rst.begin(), rst.end());
	cout << rst.size() << "\n";
	for (int i : rst) {
		cout << i << " ";
	}
	cout << "\n";

	return 0;
}

