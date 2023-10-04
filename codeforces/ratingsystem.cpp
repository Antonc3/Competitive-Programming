#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >>x;
    
    vector<ll> addToEnd(n+1);
    ll negsum = 0;
    for(int i = n-1; i >= 0; i--){
        if (i != n - 1)
        {
            addToEnd[i] = addToEnd[i+1];
        }
        if(a[i] < 0){
            negsum-=a[i];
        }
        else{
            if(negsum > a[i]){
                negsum-=a[i];
            }
            else{
                ll rem = a[i]-negsum;
                negsum = 0;
                addToEnd[i]+=rem;
            }
        }
    }
    ll mx = 0;
    ll mxK = 0;
    ll curSum = 0;
    for(int i = 0; i < n; i++){
        ll total = curSum + addToEnd[i];
        if(total > mx){
            mx = total;
            mxK = curSum;
        }
        curSum+=a[i];
    }
    cout << mxK << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}