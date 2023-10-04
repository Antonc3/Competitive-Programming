#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> ans;
    int i = 1;
    while(ans.size() < n){
        int asize = ans.size();
        i++;
        if( i >= 4 &&(i)*3%(ans.back()+ans[asize-2]) == 0){
            continue;
        }
        ans.push_back(i);
    }
    for(int i : ans){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}