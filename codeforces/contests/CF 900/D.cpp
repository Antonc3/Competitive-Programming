#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<int> l(k), r(k);
    set<pair<int,int>> st;
    for(int i = 0; i < k; i++){
        cin >> l[i];
    }
    for(int i = 0; i < k; i++){
        cin >> r[i];
        st.insert({r[i],i});
    }
    vector<int> mm(n+1,0);
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        auto lb = st.lower_bound({x,0});
        int ind = (*lb).second;
        int ll = l[ind];
        int rr = r[ind];
        int a = min(x,ll+rr-x);
        int b = max(x,ll+rr-x);
        mm[a] = mm[a]^1;
    }
    string ans = s;
    int curInd = 0;
    int mod = 0;
    for(int i = 1; i <= n; i++){
        if(i==(l[curInd] + r[curInd]+1)/2){
            i = r[curInd];
            curInd++;
            mod = 0;
            continue;
        }
        mod = mod^mm[i];
        int other = l[curInd]+r[curInd]-i;
        if(mod){
            swap(ans[i-1],ans[other-1]);
        }
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}