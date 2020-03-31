/*
boj_5014_스타트링크(난이도 : 골드5)
너비우선탐색을 통해 최단 거리 계산
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

int F, S, G, U, D;
bool visited[1000001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> F >> S >> G >> U >> D;

	queue<ii> qi;
	qi.push({ S,0 });
	int cnt = -1;
	while (!qi.empty()) {
		ii now = qi.front();
		qi.pop();

		if (now.first == G) {
			cnt = now.second;
			break;
		}

		if (visited[now.first]) continue;
		else  visited[now.first] = 1;

		int next = now.first + U;
		if (next <= F) {
			qi.push({ next,now.second + 1 });
		}

		next = now.first - D;
		if (next >= 1) {
			qi.push({ next,now.second + 1 });
		}
	}

	if (cnt != -1) {
		cout << cnt << "\n";
	}
	else {
		cout << "use the stairs\n";
	}

	return 0;
}
