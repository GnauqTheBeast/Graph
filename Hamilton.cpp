#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9 + 7;
const int Max = 1e6 + 5;
//#define int long long

int n, start;
int a[200][200];
bool visited[1005];
int x[1005];

void result() {
    for(int i = 1; i <= n; i++)
        cout << x[i] << ' ';
    cout << start << '\n';
}

void Hamilton(int k) {
    for(int j = 1; j <= n; j++) {
        if(a[x[k - 1]][j]) {
            if(k == n + 1 && j == start) {
                result();
            }
            else if(!visited[j]) {
                x[k] = j;
                visited[j] = true;
                Hamilton(k + 1);
                visited[j] = false;
            }
        }
    }
}

void runCase() {    
    cin >> n >> start;
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            cin >> a[i][j];
    x[1] = start;
    visited[start] = true;
    Hamilton(2);
}

signed main() {
    cin.tie(0) -> sync_with_stdio(0);

    int tc = 1; 
    //cin >> tc;
    while(tc--) {
        runCase();
        cout << '\n';
    }
}