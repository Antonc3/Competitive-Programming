#include <bits/stdc++.h>

using namespace std;
#define MAXN 200005
bool DEBUG = false;
int n,c;
void solve(){
    cin >> n >> c;
    vector<pair<int,int>> v;
    for(int i = 1; i <= n; i++){
        int a;
        cin >> a;
        v.push_back({min(a+i,a+n+1-i),a+i});
    }
    sort(v.begin(),v.end());
    vector<long long> pref;
    pref.push_back(0);
    for(int i = 0; i < n; i++){
       pref.push_back(pref.back()+v[i].first); 
    }
    int ans = 0;
    for(int i = 0; i < n; i++){
        int best = 0;
        if(DEBUG) cout << "i:" << i<<endl;
        int l = 0, r = n; 
        while(l <= r){
            int mid = (l+r)/2;
            long long cur = pref[mid];
            int now = mid+1;
            if(mid > i){
                cur-=v[i].first;
                now--;
            }

            if(DEBUG) cout << "cur: " << cur << " mid: " << mid<<endl;
            if(DEBUG) cout << "c-v[sec]: " << c-v[i].second<<endl;
            if(cur > c-v[i].second){
                r = mid-1;
            }
            else{
                l = mid+1;
                best = max(now,best);
            }
        }
        if(DEBUG) cout << "BEST: " << best << endl;
        ans = max(ans,best);
    }
    cout<< ans << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}