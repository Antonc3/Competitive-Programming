#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> best(n);
    vector<tuple<int,int,int>> events;
    for(int i =0 ; i < n; i++){
        int l,r,a,b;
        cin >> l >> r >> a >> b;
        best[i] = b;
        events.push_back({b,1,i});
        events.push_back({l,-1,i});
    }

    int q;
    cin >> q;
    vector<int> queries(q);
    for(int i = 0; i < q; i++){
        int a;
        cin >> a;
        queries[i] = a;
        events.push_back({a,0,i});
    }
    multiset<int> curBestLol;
    sort(events.begin(),events.end());
    reverse(events.begin(),events.end());
    for(auto [num, type, ind] : events){
        if(type == 1){
            if(curBestLol.size()){
                best[ind] = *curBestLol.rbegin();
            }
            curBestLol.insert(best[ind]);
        }
        else if(type == -1){
            curBestLol.erase(curBestLol.lower_bound(best[ind]));
        }
        else{
            if(curBestLol.size()){
                queries[ind] = max(queries[ind], *curBestLol.rbegin());
            }
        }
    }
    for(int ans : queries){
        cout << ans << " ";
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