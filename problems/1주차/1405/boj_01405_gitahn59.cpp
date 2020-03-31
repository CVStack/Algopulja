/*
boj_01405_미친 로봇(난이도 : 골드5)
간단한 퇴각 검색 문제
주의) 절대/상대 오차가 10^-9이므로 float의 출력의 자리수를 조정해야 함
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

int N;
double prr[5];
int arr[100][100];
int ni[] = { 0,0,0,1,-1 };
int nj[] = { 0,1, -1, 0, 0 };
int path[15];

double mySum = 0;
void dfs(ii now, int cnt) {
	if (cnt == N) {
		double sum = 1;
		for (int n = 1; n <= N; n++) {
			sum *= prr[path[n]];
		}
		mySum += sum;
		return;
	}

	for (int k = 1; k <= 4; k++) {
		int i = now.first + ni[k];
		int j = now.second + nj[k];
		if (arr[i][j] != 1) {
			arr[i][j] = 1;
			path[cnt + 1] = k;
			dfs({ i,j }, cnt + 1);
			arr[i][j] = 0;
		}
	}
}

int main() {
	//freopen("input.txt", "r", stdin);
	//ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	scanf("%d", &N);
	int num;
	for (int i = 1; i <= 4; i++) {
		scanf("%d", &num);
		prr[i] = (double)num / (double)100;
	}

	ii start = { N + 2,N + 2 };
	arr[start.first][start.second] = 1;
	dfs(start, 0);

	printf("%.11lf", mySum);

	return 0;
}
