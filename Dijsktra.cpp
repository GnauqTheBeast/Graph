#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int Max = 1e6 + 5;
#define int long long
typedef pair<int, int>  ii;

int n, m, s;
vector<ii> adj[1005];

void init() {
    cin >> n >> m >> s;
    for(int i = 1; i <= m; i++) {
        int x, y, w; cin >> x >> y >> w;
        adj[x].push_back({y, w});
        adj[y].push_back({x, w});
    }
}

void dijkstra(int s) {
    vector<int> dist(n + 1, 1e9);
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    dist[s] = 0;
    pq.push({0, s});
    while(!pq.empty()) {
        ii x = pq.top(); pq.pop();
        int d = x.first, u = x.second;
        if(d > dist[u]) continue;

        for(auto v : adj[u]) {
            int w = v.second, y = v.first;
            if(dist[u] + w < dist[y]) {
                dist[y] = dist[u] + w;
                pq.push({dist[y], y});
            }
        }
    }
    for(int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
}

void runCase() {
    init();
    dijkstra(s);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    int tc = 1; 
    //cin >> tc;
    while(tc--) {
        runCase();
    }
}