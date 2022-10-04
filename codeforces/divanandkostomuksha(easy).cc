#include <bits/stdc++.h>

using namespace std;
const int MAXC = 5000006;


map<int,int> cnt;
int dp[MAXC];

void calc_divisors(int a){
    for(int i = 1; i <=sqrt(a); i++){
        if(a%i == 0){
            if(i*i==a){
                cnt[i]++;
                return;
            }
            cnt[i]++;
            cnt[a/i]++;     
        }
    }
}

void solve(){
    int n;
    cin >> n;
    int mxval = 0;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        calc_divisors(a);
        mxval = max(mxval,a);
    }
    fill(dp, dp+mxval+5, 0);
    int ans = 0;
    for(int i = mxval; i >= 1; i--){
        dp[i] = 1ll *i*cnt[i];
        for(int j = i; j <= mxval; j+=i){
            dp[i] = max(dp[i],dp[j]+i*(cnt[i]-cnt[j]));
        }
        // cout << i << " " << dp[i]<<endl;
        // ans = max(ans, dp[i]);
    }
    cout << dp[1];
}

int main(){
    solve();
}