/*
boj_01194_���� ��������, ����.(���̵� : ���1)
bfs, bitmask
Ű�� ���� ���θ� bitmask�� �����ϴ� bfs
Ű�� 6�� �̹Ƿ� 1<<6 ���� ���
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

typedef struct node {
	int h, w, key;
}Node;


int N, M;
int EMPTY = '.';
int WALL = '#';
int GOAL = '1';
ii start;
int ni[] = { 1,-1,0,0 };
int nj[] = { 0,0,1,-1 };

int time[51][51][(1 << 6) + 1];
int arr[51][51];

int bfs() {
	queue<Node> q;
	q.push({ start.first,start.second, 0 });
	time[start.first][start.second][0] = 0;
	for (int t = 0; !q.empty(); t++) {
		int qsize = q.size();
		for (int qs = 1; qs <= qsize; qs++) {
			Node now = q.front();
			q.pop();

			for (int k = 0; k < 4; k++) {
				int i = now.h + ni[k];
				int j = now.w + nj[k];
				if (i<1 || i>N || j<1 || j>M) continue;
				if (arr[i][j] == WALL) continue;
				if ('a' <= arr[i][j] && arr[i][j] <= 'f') {
					int to = (1 << (arr[i][j] - 'a'));
					int myKey = now.key;
					if (!(now.key & to)) myKey += to;

					if (time[i][j][myKey] > t + 1) {
						q.push({ i,j,myKey });
						time[i][j][myKey] = t + 1;
					}

				}
				else if ('A' <= arr[i][j] && arr[i][j] <= 'F') {
					int need = arr[i][j] - 'A';
					if (now.key & 1 << need) {
						if (time[i][j][now.key] > t + 1) {
							q.push({ i,j, now.key });
							time[i][j][now.key] = t + 1;
						}
					}
				}
				else if (arr[i][j] == EMPTY && time[i][j][now.key] > t + 1) {
					q.push({ i,j, now.key });
					time[i][j][now.key] = t + 1;
				}
				else if (arr[i][j] == GOAL) return t + 1;
			}
		}
	}

	return -1;
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
			if (arr[n][m] == '0') {
				arr[n][m] = EMPTY;
				start = { n,m };
			}
			for (int k = 0; k <= (1 << 6); k++) {
				time[n][m][k] = INT_MAX;
			}
		}
	}

	cout << bfs() << "\n";

	return 0;
}

