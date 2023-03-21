#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
typedef pair<pii,int> piii;
#define F first
#define S second

void solve(){
    int n;
    cin >> n;
    vector<piii> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i].F.F >> arr[i].F.S;
        if(arr[i].F.F < arr[i].F.S) swap(arr[i].F.F,arr[i].F.S);
        arr[i].S = i;
    }
    sort(arr.begin(),arr.end());
    // F > S for all i
    vector<int> ans(n);
    //in ascending order for arr.f.f
    pii best = {1e9,-1};
    vector<pii> toinsert;
    //want to find first element strictly smaller than arr[i].F.S
    for(int i = 0; i < n; i++){
        
        //cout << arr[i].F.F << " " << arr[i].F.S<<endl;
        if(best.F < arr[i].F.S) ans[arr[i].S] = best.S+1;
        else ans[arr[i].S] = -1;

        toinsert.push_back({arr[i].F.S,arr[i].S});
        if(i < n && arr[i].F.F != arr[i+1].F.F){
            for(auto i : toinsert){
                if(best.F > i.F){
                    best = i;
                }
            }
            toinsert.clear();
        }
    }
    for(int i : ans) cout << i << " ";
    cout << endl;
}

int main(){
    int t;
    cin >>t;
    while(t--){
        solve();
    }
}
