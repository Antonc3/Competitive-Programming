#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,tests;
    cin >> n >> tests;
    string s;
    cin >> s;
    int arr[n+1];
    arr[0] = 0;
    for(int i = 0; i < n; i++){
        if(s[i] == '+'){
            arr[i+1] = arr[i] + 1;
        }
        else{
            arr[i+1] = arr[i] -1;
        }
    }
    for(int i = 0; i < tests; i++){
        int a,b;
        cin >> a >> b;
        cout << arr[b]-arr[a]<<endl;
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}