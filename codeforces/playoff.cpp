#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    string s;
    cin >> n;
    cin >> s;
    int k = count(s.begin(), s.end(), '1');
    for (int x = 1 << k; x <= (1 << n) - (1 << (n - k)) + 1; ++x)
        cout << x << ' ';
}


int main(){
    int t = 1;
    while(t--){
        solve();
    }
}