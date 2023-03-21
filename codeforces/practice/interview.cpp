#include <bits/stdc++.h>
using namespace std;

bool check(vector<int> &pref, int v){
    //include v
    cout << "? " << v+1 << " ";
    for(int i = 0; i <=v; i++){
        cout << i+1 << " ";
    }
    cout << "\n";
    int response;
    cin >> response;
    if(response > pref[v+1]) return true;
    return false;
}

void solve(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> pref(n+1,0);
    for(int i = 0; i < n; i++){
        cin >> a[i];
        pref[i+1] = pref[i] + a[i];
    }
    int l = 0, r = n-1;
    int best = 0;
    while(l <= r){
        //ask 0 to m
        int m = (l+r)/2;
        if(check(pref,m)){
            best = m;
            r = m-1;
        }
        else{
            l = m+1;
        }
    }
    cout << "! " <<best+1 << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
