#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second

bool sortFirst(pair<int,int> a, pair<int,int> b){
    return a.f < b.f;
}
bool sortSecond(pair<int,int> a, pair<int,int> b){
    return a.s < b.s;
}
void solve(){
    int n;
    cin >> n;
    vector<pair<int,int>> problems;
    for(int i =0 ; i < n; i++){
        int a, b;
        cin >> a >> b;
        problems.push_back({a,b});
    }

}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}