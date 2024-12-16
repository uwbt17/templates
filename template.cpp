#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#endif
using ll = long long;
using love = int;

#define all(x) (x).begin(), (x).end()
#define pb push_back
#define szof(x) (int)x.size()
#define int ll

template<class T>
void MIN(T& a, T b) { b < a ? a = b : a = a; }
template <class T>
void MAX(T& a, T b) { a < b ? a = b : a = a; }

const int inf = (1ll << 31) - 1;
const int INF = (1ll << 62) - 1 + (1ll << 62);
const int N = 5e5 + 5;
int n, qw, a[N], ql[N], qr[N], qk[N], ans[N];
vector <int> has[N];
vector <int> good[N];
vector <int> pos[N];
set <int> st[6];
int cnt[N];
void solve (int l, int r, vector <int> &cur) {
	if (l > r || !szof(cur)) return;
	int md = l + r >> 1;
	vector <int> curL, curR;
	for (int i = l; i <= r; i ++) has[i].clear();
	for (int i : cur) {
		if (ql[i] <= md && qr[i] > md) has[ql[i]].pb(i), has[qr[i]].pb(i);
		else if (qr[i] > md) curR.pb(i);
		else curL.pb(i);
	}
	for (int i = l; i <= md; i ++) cnt[a[i]] = 0;
	for (int i = md; i >= l; i --) {
		cnt[a[i]] ++;
		for (int k = 2; k <= 5; k ++) {
			st[k].insert(a[i]);
			set <int> nw = st[k];
			for (int c : st[k]) if (cnt[c] * k <= md - i + 1) nw.erase(c);
			swap(st[k], nw);
		}
		for (int c : has[i]) for (int to : st[qk[i]]) good[c].pb(to);
	}
	for (int i = md + 1; i <= r; i ++) cnt[a[i]] = 0;
	for (int i = md + 1; i <= r; i ++) {
		cnt[a[i]] ++;
		for (int k = 2; k <= 5; k ++) {
			st[k].insert(a[i]);
			set <int> nw = st[k];
			for (int c : st[k]) if (cnt[c] * k <= i - md) nw.erase(c);
			swap(st[k], nw);
		}
		for (int c : has[i]) for (int to : st[qk[i]]) good[c].pb(to);
	}
	solve(l, md, curL), solve(md + 1, r, curR);
}
 
void ka () {
	cin >> n >> qw;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	for (int i = 1; i <= qw; i ++) cin >> ql[i] >> qr[i] >> qk[i], ans[i] = inf;
	vector <int> cur;
	for (int i = 1; i <= qw; i ++) cur.pb(i);
	solve(1, n, cur);
	for (int i = 1; i <= n; i ++) pos[a[i]].pb(i);
	for (int i = 1; i <= qw; i ++) {
		for (int c : good[i]) {
			int have = upper_bound(all(pos[c]), qr[i]) - lower_bound(all(pos[c]), ql[i]);
			if (have * qk[i] > qr[i] - ql[i] + 1) MIN(ans[i], c);
		}
	}
	for (int i = 1; i <= qw; i ++) {
		cout << (ans[i] == inf ? -1 : ans[i]) << '\n';
	}
}

const bool uwbt17 = 1;

main() {
  cout.setf(ios::fixed);cout.precision(12);
  ios_base::sync_with_stdio(0); cin.tie(0);
  //freopen("mine.in" , "r", stdin); freopen("mine.out", "w", stdout);
  #ifdef LOCAL
  freopen("input.txt", "r", stdin);
  #endif
  int tc = 1; if (uwbt17) cin >> tc;
  for (int cs = 1; cs <= tc; cs ++) {
		ka();
		if (cs < tc) {
			cout << '\n';
			#ifdef LOCAL
			cout << '\n';
			#endif
		}
	}
  #ifdef LOCAL
  cout << "\n\nTime elapsed: " << double(clock()) / CLOCKS_PER_SEC << " s.";
  #endif
}

