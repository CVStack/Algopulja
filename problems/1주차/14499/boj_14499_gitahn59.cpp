/*
boj_14499_주사위 굴리기(난이도 : 골드5)
주사위의 이동을 시뮬레이션
2차원배열을 통해 주사위 면의 이동을 구현
이동 방향에 따라 면을 밀어냄
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

int N, M, X, Y, K;

int arr[22][22];
int od[1001];

int ni[5] = { 0,0,0,-1,1 };
int nj[5] = { 0,1,-1,0,0 };

int dice[4][3] = {
	{0,2,0},
	{4,1,3},
	{0,5,0},
	{0,6,0},
};

int diceNum[7];
void move(int order) {
	int temp[4];
	switch (order) {
	case 1:
		for (int i = 0; i < 3; i++) temp[i] = dice[1][i];
		temp[3] = dice[3][1];
		dice[1][0] = temp[3];
		dice[1][1] = temp[0];
		dice[1][2] = temp[1];
		dice[3][1] = temp[2];
		break;
	case 2:
		for (int i = 0; i < 3; i++) temp[i] = dice[1][i];
		temp[3] = dice[3][1];
		dice[1][0] = temp[1];
		dice[1][1] = temp[2];
		dice[1][2] = temp[3];
		dice[3][1] = temp[0];
		break;
	case 3:
		for (int i = 0; i < 4; i++) temp[i] = dice[i][1];
		dice[0][1] = temp[1];
		dice[1][1] = temp[2];
		dice[2][1] = temp[3];
		dice[3][1] = temp[0];
		break;
	case 4:
		for (int i = 0; i < 4; i++) temp[i] = dice[i][1];
		dice[0][1] = temp[3];
		dice[1][1] = temp[0];
		dice[2][1] = temp[1];
		dice[3][1] = temp[2];
		break;
	}
}

void solve() {
	int h = X + 1;
	int w = Y + 1;

	for (int k = 1; k <= K; k++) {
		//1동 2서 3북 4남
		int i = ni[od[k]] + h;
		int j = nj[od[k]] + w;
		if (i < 1 || i > N || j < 1 || j > M) continue;
		h = i; w = j;
		move(od[k]);
		if (arr[h][w] == 0) {
			arr[h][w] = diceNum[dice[3][1]];
		}
		else {
			diceNum[dice[3][1]] = arr[h][w];
			arr[h][w] = 0;
		}
		cout << diceNum[dice[1][1]] << "\n";
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M >> X >> Y >> K;

	for (int n = 1; n <= N; n++) {
		for (int m = 1; m <= M; m++) {
			cin >> arr[n][m];
		}
	}

	for (int k = 1; k <= K; k++) {
		//1동 2서 3북 4남
		cin >> od[k];
	}

	solve();

	return 0;
}
