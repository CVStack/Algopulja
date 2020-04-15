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
vii room[4] = {
	{{-1,0},{1,0},{0,-1},{0,1}},
	{},
	{{-1,0},{1,0}},
	{{0,-1},{0,1}},
};

int arr[8][8];
int visited[8][8][1 << 7][1 << 7];

void rotate(int h, int w, int& rc, int& cc) {
	if (rc & 1 << h) {
		rc -= 1 << h;
	}
	else {
		rc += 1 << h;
	}

	if (cc & 1 << w) {
		cc -= 1 << w;
	}
	else
		cc += 1 << w;
}

bool canMove(int h, int w, int from, int to) {
	if (from == 0) {//A
		if (to == 0) return true;
		else if (to == 2 && h != 0) return true;
		else if (to == 3 && w != 0) return true;
	}
	else if (from == 2) {
		if (to == 0) return true;
		else if (to == 2 && h != 0) return true;
	}
	else if (from == 3) {
		if (to == 0) return true;
		else if (to == 3 && w != 0) return true;
	}
	return false;
}

int getType(int h, int w, int rc, int cc) {
	int temp = arr[h][w];
	if (temp <= 1) return temp;
	if (rc & 1 << h) {
		if (arr[h][w] == 2) temp = 3;
		else temp = 2;
	}
	if (cc & 1 << w) {
		if (temp == 2) temp = 3;
		else temp = 2;
	}
	return temp;
}

int bfs() {
	queue<tuple<int, int, int, int>> q;
	q.push({ 1,1,0,0 });
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		for (int i = 1; i <= qsize; i++) {
			auto now = q.front();
			q.pop();

			int h = get<0>(now);
			int w = get<1>(now);
			int rc = get<2>(now);
			int cc = get<3>(now);

			if (h == N && w == M) {
				return t;
			}

			if (visited[h][w][rc][cc] == 1) continue;
			else visited[h][w][rc][cc] = 1;

			int type = getType(h, w, rc, cc);
			for (ii n : room[type]) {
				int i = h + n.first;
				int j = w + n.second;
				if (i<1 || i>N || j<1 || j>M) continue;
				if (canMove(n.first, n.second, type, getType(i, j, rc, cc))) {
					q.push({ i,j,rc,cc });
				}
			}

			int nrc = rc;
			int ncc = cc;
			rotate(h, w, nrc, ncc);
			q.push({ h,w,nrc,ncc });
		}
	}

	return -1;

}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	char str[15];
	for (int n = 1; n <= N; n++) {
		cin >> str + 1;
		for (int m = 1; m <= M; m++) {
			arr[n][m] = str[m] - 'A';
		}
	}

	cout << bfs() << "\n";

	return 0;
}

