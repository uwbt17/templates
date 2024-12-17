vector <int> g[N];
int tin[N];
int tout[N];
int up[N][25];
int timer;

void dfs_lca (int v = 1, int parent = 1) {
    tin[v] = ++ timer;
    up[v][0] = parent;
    for (int i = 1; i < 25; i++) { up[v][i] = up[up[v][i - 1]][i - 1]; }
    for (int u : g[v]) { if (u != p) dfs_lca(u, v); }
    tout[v] = timer;
}

bool upper (int u, int v) { return tin[u] <= tin[v] && tin[v] <= tout[u]; }

int lca (int u, int v) {
    if (upper(u, v)) return u;
    if (upper(v, u)) return v;
    for (int i = 24; i >= 0; i--) {
        if (!upper(up[u][i], v)) u = up[u][i];
    }
    return up[u][0];
}
