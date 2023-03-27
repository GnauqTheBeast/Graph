#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int Max = 1e6 + 5;
//#define int long long

int n, m;
int sz[1005], parent[1005];

struct edge{
    int x, y, w;
};

vector<edge> E;

void init() {
    E.clear();
    cin >> n >> m;
    for(int i = 1; i <= m; i++) {
        int x, y, w; cin >> x >> y >> w;
        E.push_back({x, y, w});
    }
    for(int i = 1; i <= n; i++) {
        sz[i] = 1;
        parent[i] = i;
    }
}

int Find(int u) {
    //return (u == parent[u]) ? u : parent[u] = Find(parent[u]);
    if(u == parent[u])
        return u;
    return parent[u] = Find(parent[u]);
}

bool Union(int u, int v) {
    u = Find(u);
    v = Find(v);
    if(u == v)
        return false;
    if(sz[u] < sz[v]) {
        sz[v] += sz[u];
        parent[u] = v;
    }
    else {
        sz[u] += sz[v];
        parent[v] = u;
    }
    return true;
}

void Krukal() { 
    sort(E.begin(), E.end(), [](edge a, edge b) -> bool {
        return a.w < b.w;
    });
    int k = 0;
    for(edge e : E) {
        if(Union(e.x, e.y)) {
            k += e.w;
        }
    }
    cout << k << '\n';
}

void runCase() {
    init();
    Krukal();
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    int tc = 1; 
    cin >> tc;
    while(tc--) {
        runCase();
    }
}