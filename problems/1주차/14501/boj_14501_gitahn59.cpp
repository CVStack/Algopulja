/*
boj_03190_뱀(난이도 : 실버1)
deque를 이용하여 뱀의 이동을 시뮬레이션
머리를 미리 계산하고 충돌검사를 해야 함
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

int N, K, L;

typedef struct node {
	int i, j;
	char dir;
}Node;

int arr[102][102];
char path[10001];

Node move(Node& node) {
	Node next = node;

	switch (node.dir) {
	case 'R':
		next.j++;
		break;
	case 'L':
		next.j--;
		break;
	case 'T':
		next.i--;
		break;
	case 'B':
		next.i++;
		break;
	}
	return next;
}

char change(char now, char c) {
	switch (now) {
	case 'R':
		if (c == 'L') return 'T';
		else return 'B';
	case 'L':
		if (c == 'L') return 'B';
		else return 'T';
	case 'T':
		if (c == 'L') return 'L';
		else return 'R';
	case 'B':
		if (c == 'L') return 'R';
		else return 'L';
	}
	return 'T';
}

ll game() {
	deque<Node> dq;
	dq.push_front({ 1,1,'R' });

	int len = 1;
	ll t = 1;
	for (;; t++) {
		Node next = move(dq.front());
		if (t <= 10000 && path[t] != 0) {
			next.dir = change(next.dir, path[t]);
		}

		if (next.i <1 || next.i > N || next.j <1 || next.j > N)
			break;

		if (dq.size() > 1) {
			for (int i = 1; i < dq.size(); i++) {
				if (next.i == dq[i].i && next.j == dq[i].j)
					return t;
			}
		}

		if (arr[next.i][next.j] == 1) {
			arr[next.i][next.j] = 0;
		}
		else {
			dq.pop_back();
		}

		dq.push_front(next);
	}

	return t;
}


int main() {
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> K;

	int a, b;
	for (int k = 1; k <= K; k++) {
		cin >> a >> b;
		arr[a][b] = 1;
	}

	cin >> L;
	int x;
	char str[5];
	for (int l = 1; l <= L; l++) {
		cin >> x >> str;
		path[x] = str[0];
	}

	cout << game() << "\n";

	return 0;
}
