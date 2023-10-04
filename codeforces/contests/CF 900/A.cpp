#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n, k;
    cin >> n>> k;
    vector<int> a(n);
    int ok = 0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] == k) ok = 1;
    }
    if(ok){
        cout << "YES\n";
    }
    else{
        cout << "NO\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}