#include <iostream>
#include <queue>
#include <set>
#include <stack>
#include <utility>
#include <tuple>
#include <iomanip>
#include <map>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
#include <unordered_map>
#define ll long long
#define inf 100000000000000007
#define mod 1000000007

using namespace std;
int locker[1005][1005];
void solve() {
	int n, q;
	cin >> n >> q;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 1000; j++) {
			locker[i][j] = 0;
		}
	}
	vector < pair<int, pair<int, int> > > query(q+1);
	for (int i = 1; i <= q; i++) {
		cin >> query[i].first >> query[i].second.first >> query[i].second.second;
		locker[query[i].first][query[i].second.first]++;
		locker[query[i].first][query[i].second.second + 1]--;
	}
	bool have = false;
	int lock = -1;
	set<int> pos;
	int count = 0;
	for (int i = 1; i <= n; i++) {
		bool choose = false;
		for (int j = 1; j <= 1000; j++) {
			locker[i][j] += locker[i][j - 1];
			if (locker[i][j] > 1) {
				if (!choose) {
					count++;
				}
				if (locker[i][j] > 2) {
					cout << "NO\n";
					return;
				}
				have = true;
				choose = true;
				lock = i;
				pos.insert(j);
			}
		}
		
	}
	if (count > 1) {
		cout << "NO\n";
		return;
	}
	if (!have) {
		cout << "YES\n";
	}
	else {
		bool can = false;
		for (int i = 1; i <= q; i++) {
			if (query[i].first == lock) {
				int L = *pos.begin();
				auto it = pos.end();
				it--;
				int R = *it;
				if (query[i].second.first <= L && query[i].second.second >= R) {
					can = true;
					break;
				}
			}
		}
		if (can) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}