#include <bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    for(int &x : arr) if(x==1) x++;
    for(int i = 1; i < n; i++){
        if(arr[i]%arr[i-1] == 0){
            arr[i]++;
        }
    }
    for(int i : arr) cout << i << " ";
    cout << "\n";
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
