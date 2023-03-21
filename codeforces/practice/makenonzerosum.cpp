#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    int onecnt = 0;
    for(int i = 0; i < n; i++){
        if(a[i] != 0) onecnt++;
    }
    if(onecnt&1){
        cout << "-1\n";
        return;
    }
    vector<pair<int,int>> ans;
    for(int i =0 ; i < n;){
        int l1 = i;
        while(l1 < n && a[l1] == 0){
            l1++;
        }
        if(l1 > i){
            ans.push_back({i+1,l1});
        }
        if(l1==n) break;
        int cur = l1+1;
        while(cur < n && a[cur] == 0){
            cur++;
        }
        if(a[cur] == a[l1]){
            if((cur-l1+1)%2 == 1){
                ans.push_back({l1+1,l1+1});
                ans.push_back({l1+2,cur+1});
            }
            else{
                ans.push_back({l1+1,cur+1});
            }
        }
        else{
            if((cur-l1+1)%2 == 0){
                ans.push_back({l1+1,l1+1});
                ans.push_back({l1+2,cur+1});
            }
            else{
                ans.push_back({l1+1,cur+1});
            }
        }
        i = cur+1;
    }
    cout << ans.size()<<"\n";
    for(auto i : ans) cout << i.first << " " << i.second << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
