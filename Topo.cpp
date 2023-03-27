#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int Max = 1e6 + 5;
//#define int long long

bool visited[1005];
vector<int> adj[1005];
stack<int> st;
int n, m;

void init() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].push_back(y);
    }
}

void DFS(int u) {
    visited[u] = true;
    for(int v : adj[u]) {
        if(!visited[v]) 
            DFS(v);
    }
    st.push(u);
}

void runCase() {
    init();
    for(int i = 1; i <= n; i++) {
        if(!visited[i]) 
            DFS(i);
    }
    while(!st.empty()) {
        cout << st.top() << ' ';
        st.pop();
    }
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    int tc = 1; 
    //cin >> tc;
    while(tc--) {
        runCase();
    }
}