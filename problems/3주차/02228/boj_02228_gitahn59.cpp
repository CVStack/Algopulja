/*
boj_02228_구간 나누기(난이도 : 골드5)
dp
dp를 통해 각 구간에 대해 최댓값을 계산
누적합을 이용해 m=1 일때 값을 빠르게 계산할 수 있음
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
int arr[101];
int acc[101];

int mem[101][101][51];
int FIRST = -32768 * 10000;
int NONE = 32768 * 10000;
int omem[101][101];

int topdown(int a, int b) {
	int& ref = omem[a][b];
	if (ref != FIRST) return ref;
	if (a == b) return ref = arr[a];

	int myMax = acc[b] - acc[a - 1];
	for (int i = a; i <= b - 1; i++) {
		int left = topdown(a, i);
		int right = topdown(i + 1, b);
		myMax = max(myMax, max(left, right));
	}

	return ref = myMax;
}

int topdown(int a, int b, int cnt) {
	int& ref = mem[a][b][cnt];
	if (ref != FIRST) return ref;

	if (cnt == 1) {
		return ref = topdown(a, b);
	}

	int myMax = NONE;
	for (int i = a; i <= b - 2; i++) {
		for (int c = 1; c < cnt; c++) {
			int mid = i - a + 1;
			if (mid % 2 == 1) mid++;
			if (mid / 2 < c) continue;
			mid = b - (i + 2) + 1;
			if (mid % 2 == 1) mid++;
			if (mid / 2 < cnt - c) continue;
			int left = topdown(a, i, c);
			int right = topdown(i + 2, b, cnt - c);
			if (left == NONE || right == NONE) continue;

			if (myMax == NONE) myMax = left + right;
			else myMax = max(myMax, left + right);
		}
	}

	return ref = myMax;
}

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;
	for (int n = 1; n <= N; n++) {
		cin >> arr[n];
		acc[n] = arr[n] + acc[n - 1];
	}

	for (int n = 1; n <= N; n++) {
		for (int i = 1; i <= N; i++) {
			omem[n][i] = FIRST;
			for (int m = 0; m <= M; m++) {
				mem[n][i][m] = FIRST;
			}
		}
	}

	cout << topdown(1, N, M) << "\n";
	return 0;
}

