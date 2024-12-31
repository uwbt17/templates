#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "algo/debug.h"
#else
#define deb(...) 42
#endif
using ll = long long;
using love = int;

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define szof(x) (int)x.size()
#define int ll

template<class T>
void MIN(T& a, T b) { b < a ? a = b : a = a; }
template <class T>
void MAX(T& a, T b) { a < b ? a = b : a = a; }

const int inf = (1ll << 31) - 1;
const int INF = (1ll << 62) - 1 + (1ll << 62);
const int mod = 1e9 + 7;
const int SQ = 320;
const int N = 5e5 + 5;

void ka () {
	
}

const bool uwbt17 = 1;

love main() {
	cout.setf(ios::fixed);cout.precision(12);
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	//freopen("peacefulsets.in" , "r", stdin); freopen("peacefulsets.out", "w", stdout);
	
	#ifdef LOCAL
	int num; cin >> num;
	if (num == 1) freopen("1.txt", "r", stdin);
	else if (num == 2) freopen("2.txt", "r", stdin);
	else if (num == 3) freopen("3.txt", "r", stdin);
	#endif
	
	int tc = 1;
	if (uwbt17) cin >> tc;
	
	for (int cs = 1; cs <= tc; cs ++) {
		//cout << "Case " << cs << ":\n";
		ka();
		if (cs < tc) {
			cout << '\n';
			#ifdef LOCAL
			//cout << '\n';
			#endif
		}
	}
	
	#ifdef LOCAL
	cout << "\n\n" << 1.0 * clock() / CLOCKS_PER_SEC << " s.";
	#endif
}
