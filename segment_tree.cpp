struct seg_tree {
	static const int good_val = 0; // 0 for sum, -inf for max and inf for min
	int n;
	int t[N << 2];
	int put[N << 2];
	seg_tree (int_n) : n(_n) {}
	int merge (int a, int b) { return a + b; }
	void push (int v, int tl, int tr) {
		if (!put[v]) return;
		t[v] += put[v] * (tr - tl + 1);
		if (tl < tr) {
			put[v + v] += put[v];
			put[v + v + 1] += put[v];
		}
		put[v] = 0;
	}
	void upd (int l, int r, int val, int v = 1, int tl = 1, int tr = N - 1) {
		push(v, tl, tr);
		if (r < tl || tr  < l) return;
		if (l <= tl && tr <= r) {
			put[v] += val;
			push(v, tl, tr);
			return;
		}
		int tm = tl + tr >> 1;
		upd(l, r, val, v + v, tl, tm);
		upd(l, r, val, v + v + 1, tm + 1, tr);
		t[v] = merge(t[v + v], t[v + v + 1]);
	}
	int get (int l, int r, int v = 1, int tl = 1, int tr = N - 1) {
		push(v, tl, tr);
		if (r < tl || tr  < l) return good_val;
		if (l <= tl && tr <= r) return t[v];
		int tm = tl + tr >> 1;
		int res = get(l, r, v + v, tl, tm) + get(l, r, v + v + 1, tm + 1, tr);
		t[v] = merge(t[v + v], t[v + v + 1]);
		return res;
	}
};
