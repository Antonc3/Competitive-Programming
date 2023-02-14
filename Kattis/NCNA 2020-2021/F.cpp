#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int n, k;
vector<pair<int,int> > g[N];
long long temp = 0;

void inp(){
    cin >> n >> k;
    for(int i = 1; i < n; ++i){
        int u, v, c; 
        cin >> u >> v >> c;
        g[u].push_back(make_pair(v, c));
        g[v].push_back(make_pair(u, c));
        temp += c;
    }
}

pair<long long, long long> dp[N];
long long dpi[N];

void dfs(int s, int p){
    for(auto v : g[s]){
        if(v.first!=p){
            dfs(v.first, s);
            if(dp[s].first < dp[v.first].first + v.second)
                dp[s].second = dp[s].first, dp[s].first = dp[v.first].first + v.second;
            else if(dp[s].second < dp[v.first].first + v.second)
                dp[s].second = dp[v.first].first + v.second;
        }
    }
}

void dfsi(int s, int p){
    for(auto v : g[s]){
        if(v.first!=p){
            dpi[v.first] = dpi[s] + v.second;
            if(dp[v.first].first + v.second == dp[s].first)
                dpi[v.first] = max(dpi[v.first], dp[s].second + v.second);
            else dpi[v.first] = max(dpi[v.first], dp[s].first + v.second);
            dfsi(v.first, s);
        }
    }
}

void process(){
    if(k >= 2){
        cout << temp;
        return;
    }
    dfs(1, -1);
    dfsi(1, -1);
    long long res = 0;
    for(int i = 1; i <= n; ++i)
        res = max(res, dp[i].first + dpi[i]);
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    process();
}