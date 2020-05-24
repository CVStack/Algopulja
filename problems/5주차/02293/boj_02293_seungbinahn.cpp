/*
boj_2293_동전1(난이도 : 골드5)
bottom up dp
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

int N, K;
int arr[101];
ll mem[10001];

int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;
	for (int n = 1; n <= N; n++)
		cin >> arr[n];

	mem[0] = 1;
	for (int n = 1; n <= N; n++) {
		for (int i = arr[n]; i <= K; i++) {
			mem[i] += mem[i - arr[n]];
		}
	}

	cout << mem[K] << "\n";

	return 0;
}
