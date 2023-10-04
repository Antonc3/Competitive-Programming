#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const  ll M = 998244353;

ll fastpow(ll a, ll e){
    ll res = 1;
    while(e > 0){
        if(e&1) res = res*a%M;
        a = a*a%M;
        e/=2;
    }
    return res;
}
vector<int> depth;
vector<int> p;
vector<vector<int>> g;
void solve(){
    int n;
    cin >> n;
    depth.resize(n);
    p.resize(n);
    g.resize(n,vector<int>());
    depth[0] = 0;
    int mxDepth = 0;
    for(int i =1 ; i < n; i++){
        cin >> p[i];
        p[i]--;
        depth[i] = depth[p[i]] + 1;
        mxDepth = max(mxDepth,depth[i]);
    }
    if(mxDepth > 3) mxDepth = 3;
    cout << mxDepth << endl;
    cout << flush;
    for(int i = 1; i < n; i++){
        cout << (depth[p[i]])%3+1 << " ";
        cout << flush;
    }
    cout << endl;
    cout << flush;
    // find edges of lowest depth
    int res;
    cin >> res;
    while(res ==0){
        vector<int> colors(n);
        int lowest = n+1;
        for(int i = 1; i <= mxDepth; i++){
            cin >> colors[i];
            if(colors[i] == 1){
                lowest = min(lowest, i);
            }
        }
        if(mxDepth == 3){
            if(lowest == 1 && colors[3]){
                lowest = 3;
            }
        }
        cout << lowest<<endl;
        cout << flush;
        cin >> res;

    }
}

int main(){
    int t;
    t = 1;
    while(t--){
        solve();
    }
}