#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> cnt(n+1);
    for(int i =0; i < n; i++){
        cin >> arr[i];
        cnt[arr[i]]++;
    }
    int rem = n;
    int largerthanrem = 0;
    int neglargerthanrem = 0;
    int l = 0, r = n;
    vector<int> ans(n+1);
    while(rem > 0){
        while(cnt[l] == 0) l++;
        while(cnt[r] == 0) r--;
        if(l == r){
            if(n-neglargerthanrem == r){
                ans[r] = rem;
                rem-=cnt[r];
                largerthanrem+=cnt[r];
            }
            else if(largerthanrem == l){
                ans[l] = -rem;
                rem-=cnt[l];
                neglargerthanrem+=cnt[l];
            }
            else{
                cout << "NO\n";
                return;
            }
            break;
        }
        if(largerthanrem == l){
            ans[l] = -rem;
            neglargerthanrem+=cnt[l];
            rem-=cnt[l];
            l++;
        }
        else{
            if(n-neglargerthanrem != r){
                cout << "NO\n";
                return;
            }
            ans[r] = rem;
            largerthanrem+=cnt[r];
            rem-=cnt[r];
            r--;
        }
    }
    cout << "YES\n";
    for(int i =0; i < n; i++){
        cout << ans[arr[i]] << " ";
    }
    cout << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}