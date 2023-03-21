#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> a(n);
        int odd = 0;
        int even = 0;
        for(int &x : a){
            cin >> x;
            if(x&1) odd+=x;
            else even+=x;
        }
        if(even > odd ) cout << "YES\n";
        else cout << "NO\n";
    }
}
