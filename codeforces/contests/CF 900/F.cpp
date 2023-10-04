#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
set<pair<int,int>> getPrime(int x){
    set<pair<int,int>> res;
    for(int i = 2; i*i <= x; i++){
        if(i*i==x) {
            res.insert({i,2});
            x=1;
            break;
        }
        int cnt = 0;
        while(x%i==0 && x > 0){
            x/=i;
            cnt++;
        }
        res.insert({i,cnt});
    }
    if(x != 1){
        res.insert({x,1});
    }
    return res;
}
void solve(){
    int n, q;
    cin >> n >> q;
    set<pair<int,int>> curFactors;
    curFactors = getPrime(n);
    vector<int> xs;
    ll cn = n;
    while(q--){
        int k;
        cin >> k;
        if(k == 2){
            curFactors = getPrime(n);
            cn = n;
            xs.clear();
            continue;
        }
        int x;
        cin >> x;
        xs.push_back(x);
        set<pair<int,int>> xFactors = getPrime(x);
        ll totalFactors = 1;
        for(pair<int,int> xf : xFactors ){
            auto lb = curFactors.lower_bound({xf.first,0});
            if(lb==curFactors.end()){
                curFactors.insert(xf);
                continue;
            }
            if((*lb).first == xf.first){
                int cnt = (*lb).second;
                curFactors.erase(lb);
                curFactors.insert({xf.first,xf.second+cnt});
            }
            else{
                curFactors.insert(xf);
                continue;
            }
        }
        for(auto cf : curFactors){
            totalFactors = totalFactors*(cf.second+1);
        }
        ll curRem = n;
        for(int i : xs){
            curRem = (curRem*i)%totalFactors;
        }
        if(curRem == 0){
            cout <<"YES\n";
        }
        else{
            cout <<"NO\n";
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