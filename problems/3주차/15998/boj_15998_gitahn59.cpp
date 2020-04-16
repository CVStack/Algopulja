/*
boj_15998_카카오머니(난이도 : 골드5)
gcd
각 로그에 대해 미리 gcd를 먼저 구해두고
gcd가 사용되는 경우에만 조건을 검사
예외처리가 복잡한 문제
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

int N;
ll l[300001];
ll r[300001];
ll g;

ll gcd(ll a, ll b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;

	for (int n = 1; n <= N; n++) {
		cin >> l[n] >> r[n];
		if (r[n - 1] + l[n] < 0) {
			g = gcd(g, r[n] - r[n - 1] - l[n]);
		}
	}

	ll money = 0;
	for (int n = 1; n <= N; n++) {
		money += l[n];
		if (money >= 0 && money == r[n]) continue;
		if (money >= 0 && money != r[n]) {
			cout << "-1\n";
			return 0;
		}
		ll temp = abs(money);
		if (temp % g == 0 && r[n] == 0) {
			money = r[n];
			continue;
		}
		ll cnt = (temp / g) + 1;
		if ((cnt - 1) * g - temp >= 0) {
			cout << "-1\n";
			return 0;
		}
		else money = r[n];
	}

	if (g == 0) {
		cout << 787878 << "\n";
	}
	else {
		cout << g << "\n";
	}

	return 0;
}

