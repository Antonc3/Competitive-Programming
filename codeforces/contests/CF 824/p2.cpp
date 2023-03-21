#include <bits/stdc++.h>
using namespace std;
#define MAXN 105

int arr[MAXN];

void solve(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    int smal = arr[0];
    int ans = 0;
    for(int i =1; i < n; i++){
        int cur = arr[i];
        if(cur < smal*2) continue;
        int pieces = cur/(smal*2-1);
        if(cur%(smal*2-1) == 0) pieces--;
        ans+=pieces;
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