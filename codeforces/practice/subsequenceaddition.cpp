#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(),a.end());
    if(a[0] != 1){
        cout << "NO\n";
        return;
    }
    long long sum = 1;
    for(int i = 1; i < n; i++){
        if(a[i] > sum){
            cout << "NO\n";
            return;
        }
        sum+=a[i];
    }
    cout << "YES\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
