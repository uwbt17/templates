struct sg {
	struct node {
		love s, add;
		node* l;
		node* r;
		node() : s(0), add(0), l(nullptr), r(nullptr) {}
	};
	node* root;
	sg () : root(new node()) {}
	void push_ans (node* v, int tl, int tr) {
		if (tl != tr) {
			if (v->l == nullptr) {
				v->l = new node();
				v->r = new node();
			}
		}
		if (!v->add) return;
		v->s += (tr - tl + 1) * v->add;
		if (tl != tr) {
			v->l->add += v->add;
			v->r->add += v->add;
		}
		v->add = 0;
	}
	void upd_ans (int l, int r, int val, node* v, int tl = 1, int tr = 1e9) {
		push_ans(v, tl, tr);
		if (tl >= l && tr <= r) {
			v->add += val;
			push_ans(v, tl, tr);
			return;
		}
		if (tl > r || tr < l) return;
		int tm = (tl + tr) >> 1;
		upd_ans(l, r, val, v->l, tl, tm);
		upd_ans(l, r, val, v->r, tm + 1, tr);
		v->s = v->l->s + v->r->s;
	}
	int get_ans (int pos, node* v, int tl = 1, int tr = 1e9) {
		push_ans(v, tl, tr);
		if (tl == tr) return v->s;
		int tm = (tl + tr) >> 1;
		if (pos <= tm) return get_ans(pos, v->l, tl, tm);
		return get_ans(pos, v->r, tm + 1, tr);
	}
	void upd (int l, int r, int val) {
		upd_ans(l, r, val, root);
	}
	int get (int pos) {
		return get_ans(pos, root);
	}
};
