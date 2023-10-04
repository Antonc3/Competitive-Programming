#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct LCA {
    vector<int> height, euler, first, segtree;
    vector<bool> visited;
    int n;

    LCA(vector<vector<int>> &adj, int root = 0) {
        n = adj.size();
        height.resize(n);
        first.resize(n);
        euler.reserve(n * 2);
        visited.assign(n, false);
        dfs(adj, root);
        int m = euler.size();
        segtree.resize(m * 4);
        build(1, 0, m - 1);
    }

    void dfs(vector<vector<int>> &adj, int node, int h = 0) {
        visited[node] = true;
        height[node] = h;
        first[node] = euler.size();
        euler.push_back(node);
        for (auto to : adj[node]) {
            if (!visited[to]) {
                dfs(adj, to, h + 1);
                euler.push_back(node);
            }
        }
    }

    void build(int node, int b, int e) {
        if (b == e) {
            segtree[node] = euler[b];
        } else {
            int mid = (b + e) / 2;
            build(node << 1, b, mid);
            build(node << 1 | 1, mid + 1, e);
            int l = segtree[node << 1], r = segtree[node << 1 | 1];
            segtree[node] = (height[l] < height[r]) ? l : r;
        }
    }

    int query(int node, int b, int e, int L, int R) {
        if (b > R || e < L)
            return -1;
        if (b >= L && e <= R)
            return segtree[node];
        int mid = (b + e) >> 1;

        int left = query(node << 1, b, mid, L, R);
        int right = query(node << 1 | 1, mid + 1, e, L, R);
        if (left == -1) return right;
        if (right == -1) return left;
        return height[left] < height[right] ? left : right;
    }

    int lca(int u, int v) {
        int left = first[u], right = first[v];
        if (left > right)
            swap(left, right);
        return query(1, 0, euler.size() - 1, left, right);
    }
};

vector<vector<int>> adj;
int n;
vector<vector<int>> cnt;
vector<int> a;

void dfs(int cur, int par){
    for(int i = 0; i < 31; i++){
        cnt[cur][i] = (a[i]>>i & 1);
    }
    for(int to : adj[cur]){
        if(to == cur) continue;
        dfs(to,cur);
        for (int i = 0; i < 31; i++)
        {
            cnt[cur][i] += cnt[to][i]; 
        }
    }
}

void solve(){
    cin >> n;
    cnt.resize(n,vector<int>(31));
    a.resize(n);
    for(int i = 0; i < n; i++){
        adj.clear();
        for(int j = 0; j < 31; j++){
            cnt[i][j] = 0;
        }
    }
    for(int &x : a) cin >> x;
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        u--;
        v--;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    LCA lca(adj);
    int q;
    cin >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        x--;
        y--;
        int clca =lca.lca(x,y);
        vector<int> curcnt(31);
        for(int i = 0; i < 31; i++){
            curcnt[i] = cnt[x][i]+cnt[y][i]-2*cnt[clca][i];
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}