#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define F first
#define S second
const bool DEBUG = false;

int abs(int a){
    return (a > 0) ? a : -a;
}
void solve(){
    int n;
    cin >> n;
    vector<pii> v(n);
    for(auto &x : v) cin >> x.F >> x.S;
    sort(v.begin(),v.end());
    map<int,int> mp;
    for(auto x: v){
        if(mp.count(x.S) == 0){
            mp[x.S] = 1;
        }
        else{
            mp[x.S]++;
        }
    }
    reverse(v.begin(),v.end());
    if(DEBUG){
        cout << "\n";
        for(auto i : v){
            cout << i.F << " " <<i.S << "\n";
        }
        cout << "\n";
    }
    int secmax = 0;
    int ans = 2e9;
    for(int i = 0;i < n; i++){
        pii cur = v[i];
        mp[cur.S]--;
        if(mp[cur.S] <= 0) mp.erase(cur.S);
        if(mp.size()==0){
            ans = min(ans,abs(secmax-cur.F));
            break;
        }
        auto it = mp.lower_bound(cur.F);
        if(it == mp.end()) it--;
        int closest = it->F;
        if(DEBUG) cout << "closest: " << closest << endl;
        if(closest <= secmax){
            ans = min(ans,abs(secmax-cur.F)); 
            secmax = max(secmax,cur.S);
            continue;
        }
        if(it != mp.begin()){
            it--;
            if(it->F > secmax && abs(it->F-cur.F) < abs(closest-cur.F)){
                closest = it->F;
            }
        }
        if(DEBUG) cout << "second closest: " << closest<<endl;
        ans = min(ans,abs(closest-cur.F));
        if(DEBUG)cout << "closest: " << closest << endl;
        if(DEBUG)cout << "cur.F: " << cur.F<<endl;
        if(DEBUG)cout << "secmax: " << secmax<<endl;
        if(i > 0) ans = min(ans,abs(secmax-cur.F));
        secmax = max(secmax,cur.S);
        if(DEBUG) cout << "ANS: " <<ans << endl;
    }
    cout << ans << endl;
}
int main(){
    int t;
    cin >>t;
    while(t--){
        solve();
    }
}
