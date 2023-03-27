#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int Max = 1e6 + 5;
//#define int long long

int n, m; 
set<int> adj[1005];

void init() {
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int x, y; cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
}

void euler_cycle(int u) {
    vector<int> EC;
    stack<int> st;
    st.push(u);
    while(!st.empty()) {
        int x = st.top();
        if(adj[x].size() != 0) { 
            int y = *adj[x].begin();
            st.push(y);
            adj[x].erase(y);
            adj[y].erase(x);
        }
        else {
            EC.push_back(x);
            st.pop();
        }
    }
    for(int x : EC)     
        cout << x << ' ';
} 

void runCase() {
    init();
    euler_cycle(1);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    int tc = 1; 
    //cin >> tc;
    while(tc--) {
        runCase();
    }
}