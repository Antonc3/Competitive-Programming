#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll M = 1e9+7;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    vector<ll> pow2(n+1,1);
    for(int i = 1; i <= n; i++) pow2[i] = pow2[i-1]*2%M;
    ll ans = 0;
    for(int &x : a) cin >> x;
    for(int i = 0; i < n-1; i++){
        int l = i-1;
        int r = i+1;
        for(int j = i+1; j < n; j++){
            int diff = a[j]-a[i];
            while(l >= 0 && a[i]-a[l] <= diff) l--;
            while(r < n && a[r]-a[j] < diff) r++;
            ans = (ans + pow2[l + 1] * pow2[n - r]) % M;
        }
    }
    cout << ans << endl;
}

int main(){
    solve();
}