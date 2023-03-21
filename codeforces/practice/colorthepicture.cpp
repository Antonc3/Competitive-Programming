#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
bool check(int n, int m, vector<int> &a){
    ll nn = n;
    int found3 = false;
    for(int i = 0; i < a.size(); i++){
        ll tosub = a[i]/m;
        if(tosub >= 3) found3 = true;
        if(tosub >= 2) nn-=tosub;
    }
    if(n&1) return nn <= 0 && found3;
    return nn <= 0;
}
 
void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> a(k);
    for(int &x : a) cin >> x;
    if(check(n,m,a) || check(m,n,a)) cout << "YES\n";
    else cout <<"NO\n";
}
 
int main(){
    int t;
    cin >> t;
    while(t--) solve();
}
