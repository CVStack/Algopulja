/*
boj_2589_∫∏π∞º∂(≥≠¿Ãµµ : ∞ÒµÂ5)
bfs, bruteforce
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

int N, M;
int arr[51][51];
int ni[] = { 1,-1,0,0 };
int nj[] = { 0,0,1,-1 };
int LAND = 'L';
int WATER = 'W';

int bfs(ii start) {
	int mytime[51][51];
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			mytime[n][m] = INT_MAX;
		}
	}

	queue<ii> q;
	q.push(start);
	mytime[start.first][start.second] = 0;

	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		for (int qs = 1; qs <= qsize; qs++) {
			int n = q.front().first;
			int m = q.front().second;
			q.pop();

			for (int l = 0; l < 4; l++) {
				int i = n + ni[l];
				int j = m + nj[l];
				if (i<1 || i>N || j<1 || j>M) continue;
				if (arr[i][j] == WATER) continue;
				if (mytime[i][j] > t + 1) {
					mytime[i][j] = t + 1;
					q.push({ i,j });
				}
			}
		}
	}
	int myMax = 0;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			if (mytime[n][m] != INT_MAX) {
				myMax = max(myMax, mytime[n][m]);
			}
		}
	}
	return myMax;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	char str[55];

	for (int n = 1; n <= N; n++) {
		cin >> str + 1;
		for (int m = 1; m <= M; m++) {
			arr[n][m] = str[m];
		}
	}

	int rst = 0;
	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			if (arr[n][m] == LAND) {
				rst = max(rst, bfs({ n,m }));
			}
		}
	}

	cout << rst << "\n";

	return 0;
}

