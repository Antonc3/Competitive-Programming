#include <bits/stdc++.h>
using namespace std;
#define MAXN 41

int n, arr[MAXN];

int mod(int a, int m){
    return ((a%m)+m)%m;
}

void solve(){
    cin >> n;
    int mv = 0;
    bool done = false;
    multiset<int> ms;
    for(int i =0; i < n; i++){
        cin >> arr[i];
        ms.insert(arr[i]);
        if(!done &&ms.count(arr[i]) >= n/2){
            cout << -1<<endl;
            done = true;
        }
    }
    if(done) return;
    int ans = 1;
    ms.clear();
    for(int i = 0; i < n; i++){
        int cur = arr[i];
        int same = 0;
        map<int,int> mp;
        // cout << "cur " << cur << "  ";
        for(int j = 0; j < n; j++){
            if(arr[j] == cur) same++;
            if(arr[j] > cur){
                int dif = arr[j]-cur;
                // cout << dif << endl;
                for(int k = 1; k*k <= dif; k++){
                    if(dif%k == 0){
                        mp[k]++;
                        mp[dif/k]++;
                        if(dif/k==k) mp[dif/k]--;
                        // cout << " k " << k << " dif / k " << dif/k << endl;
                    }
                }
            }
        }
        for(auto j : mp){
            // cout << j.first << " "<< j.second << endl;
            if(j.second >= n/2-same){
                ans = max(ans,j.first);
            }
        }
        // cout << " ------- " <<endl;
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