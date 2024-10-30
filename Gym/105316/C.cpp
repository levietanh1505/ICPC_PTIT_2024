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

void solve() {
	ll n, D;
	cin >> n >> D;
	vector<ll> pos;
	vector<ll> time;
	vector<pair<ll, ll>> a;
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		pos.push_back(x);
	}
	for (int i = 1; i <= n; i++) {
		ll y;
		cin >> y;;
		time.push_back(y);
	}
	for (int i = 1; i <= n; i++) {
		a.push_back({ pos[i - 1],time[i - 1] });
	}
	sort(a.begin(), a.end());
	ll curTime = 0;
	ll timeSum = 0;
	ll ans = 0;
	priority_queue<ll> mypq;
	for (int i = 0; i < a.size(); i++) {
		curTime = a[i].first;
		if (timeSum + a[i].second <= D - curTime) {
			ans++;
			timeSum += a[i].second;
			mypq.push(a[i].second);
		}
		else if(!mypq.empty()) {
			ll top = mypq.top();
			if (top > a[i].second) {
				mypq.pop();
				timeSum -= top;
				timeSum += a[i].second;
				mypq.push(a[i].second);
			}
		}
	}
	cout << ans << endl;
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
