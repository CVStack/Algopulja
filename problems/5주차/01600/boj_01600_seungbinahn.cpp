/*
boj_1600_말이 되고픈 원숭이(난이도 : 골드5)
일반적인 bfs
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
#include <climits>

#define PRIME 1000000007
#define mp make_pair

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

int K, W, H;
int arr[201][201];
int ni[] = { 1,-1,0,0 };
int nj[] = { 0,0,1,-1 };
int hi[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
int hj[] = { -2, -1, 1, 2, -2, -1, 1, 2 };

int mytime[31][201][201];

typedef struct node {
	int k, h, w;
}Node;

int bfs() {
	queue<Node> q;
	q.push({ 0,1,1 });
	mytime[0][1][1] = 0;

	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		for (int qs = 1; qs <= qsize; qs++) {
			Node now = q.front();
			q.pop();
			if (now.w == W && now.h == H) return t;

			for (int l = 0; l < 4; l++) {
				int i = now.h + ni[l];
				int j = now.w + nj[l];
				if (i<1 || i>H || j<1 || j>W) continue;
				if (arr[i][j] == 1) continue;
				if (mytime[now.k][i][j] > t) {
					mytime[now.k][i][j] = t;
					q.push({ now.k,i,j });
				}
			}

			if (now.k == K) continue;
			for (int l = 0; l < 8; l++) {
				int i = now.h + hi[l];
				int j = now.w + hj[l];
				if (i<1 || i>H || j<1 || j>W) continue;
				if (arr[i][j] == 1) continue;
				if (mytime[now.k + 1][i][j] > t) {
					mytime[now.k + 1][i][j] = t;
					q.push({ now.k + 1,i,j });
				}
			}
		}
	}

	return -1;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> K >> W >> H;

	for (int h = 1; h <= H; h++) {
		for (int w = 1; w <= W; w++) {
			cin >> arr[h][w];
			for (int k = 0; k <= K; k++)
				mytime[k][h][w] = INT_MAX;
		}
	}

	cout << bfs() << "\n";

	return 0;
}

