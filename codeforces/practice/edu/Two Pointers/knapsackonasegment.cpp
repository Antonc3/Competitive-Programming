#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n;
    ll s;
    cin >> n >> s;
    vector<ll> weights(n);
    vector<ll> cost(n);
    vector<ll> pref(n+1,0);
    for(auto &x : weights) cin >> x;
    for(int i = 0; i < n; i++){
        cin >> cost[i];
        pref[i+1] = pref[i]+cost[i];
    }
    ll sum = 0;
    ll best = 0;
    int r = 0;
    for(int l = 0; l < n; l++){
        while(r < n && sum + weights[r]<= s){
            sum+=weights[r];
            r++;
        }
        best = max(best,pref[r]-pref[l]);
        sum-=weights[l];
    }
    cout << best << endl;

}
