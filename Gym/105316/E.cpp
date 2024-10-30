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

const int BLOCK = 450;


ll fastpow(ll n, ll x) {

	if (x == 0) {
		return 1;
	}
	else {
		ll ret = fastpow(n, x / 2);
		ret = ((ret)*(ret));
		if (x % 2 == 0) {
			return ret;
		}
		else {
			return ((ret ) * (n )) ;
		}
	}
}


ll gcd(ll a, ll b) {
	if (b == 0) {
		return a;
	}
	else {
		return gcd(b, a % b);
	}
}
ll lcm(ll a, ll b) {
	ll val = (a % mod * b % mod) % mod;
	val = (val * fastpow(gcd(a, b), mod - 2)) % mod;
	return val;
}
int Logk(ll n, ll k) {
	if (k == 1) {
		return 1;
	}
	if (n == 0) {
		return 0;
	}
	int count = -1;
	while (n > 0) {
		count++;
		n /= k;
	}
	return count;
}
struct Dsu {
	vector<int> par;

	void init(int n) {
		par.resize(n + 5, 0);
		for (int i = 1; i <= n; i++) par[i] = i;
	}

	int find(int u) {
		if (par[u] == u) return u;
		return par[u] = find(par[u]);
	}

	bool join(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return false;
		par[v] = u;
		return true;
	}
} dsu;
int group[100];

ll a[100005];
void solve() {

	int n;
	cin >> n;
	for (int i = 0; i < 100; i++) {
		group[i] = 0;
	}
	int zero = 0;
	
	
	for (int i = 1; i <= n; i++) {
		ll x;
		cin >> x;
		if (x == 0) {
			zero = 1;
		}
		else {
			group[int(log2(x))]++;
			x = int(log2(x));
			a[i] = x;
		}
		
		
	}
	
	int ans = 0;
	for (int i = 0; i <= 61; i++) {
		ans = max(ans, group[i]);
	}
	ans = max(ans, zero);
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