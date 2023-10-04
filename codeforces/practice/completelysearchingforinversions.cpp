#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll M = 998244353;

ll dfs(int cur, vector<ll> &inversions,vector<ll> &ones, vector<ll> &zeroes, vector<vector<pair<int,int>>> &g){
    inversions[cur] = 0;
    ones[cur] = 0;
    zeroes[cur] = 0;
    for(auto [to,w] : g[cur]){
        if (w)
        {
            ones[cur] = (ones[cur] + 1)%M;
        }
        else
        {
            inversions[cur] = (inversions[cur] + ones[cur])%M;
            zeroes[cur] = (zeroes[cur] + 1) %M;
        }
        if(inversions[to] == -1){
            dfs(to, inversions, ones, zeroes, g);
        }
        inversions[cur] = (inversions[cur] + inversions[to] + ones[cur] * zeroes[to]) % M;
        ones[cur] = (ones[cur] + ones[to]) % M;
        zeroes[cur] = (zeroes[cur] + zeroes[to]) % M;
    }
    //cout << "cur: " << cur << " inversions[cur] " << inversions[cur] << " ones "  << ones[cur] << " zeroes " << zeroes[cur] << endl;
    return inversions[cur];
}

int main(){
    int n;
    cin >> n;
    vector<vector<pair<int,int>>> g(n);
    for(int i = 0; i < n; i++){
        int s;
        cin >> s;
        while(s--){
            int to, w;
            cin >> to >> w;
            g[i].push_back({--to,w});
        }
    }
    vector<ll> inversions(n,-1), zeroes(n,-1), ones(n,-1);
    cout << dfs(0,inversions,ones,zeroes,g);
}