#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define MAXN 100005

int main(){
    int n,k;
    cin >>n>>k;
    vector<int> arr(n);
    for(auto &x : arr) cin >> x;
    int l = 0;
    ll sum = 0;
    long long ans = 0;
    vector<int> cnt(MAXN,0);
    int unique = 0;
    for(int r = 0; r < n; r++){
        if(cnt[arr[r]] == 0){
            unique++;
        }
        cnt[arr[r]]++;
        while(unique > k && l < r){
            cnt[arr[l]]--;
            if(cnt[arr[l]] == 0) unique--;
            l++;
        }
        if(unique <= k){
            ans+=r-l+1;
        }

    }
    cout << ans<<"\n";
}
