#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,k,x;
    cin >> n >> k >> x;
    vector<int> used(n+1,0);
    vector<vector<int>> subseq;
    if(x <= n) {
        subseq.push_back({x});
        used[x] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(used[i]>0) continue;
        if(((i^x) > n) || used[i^x]>0){
            continue;
        } 
        subseq.push_back({i,i^x});
        used[i] = 1;
        used[i^x] =1;
    }
    vector<int> cur;
    int s = 0;
    for(int i = 1; i <= n; i++){
        if(!used[i]){
            cur.push_back(i);
            s ^= i;
        } 
    }
    if(subseq.size() > 0 && s==0) subseq.back().insert(subseq.back().begin(),cur.begin(),cur.end());
    else if(s == x) subseq.push_back(cur);
    else{
        cout << "NO\n";
        return;
    }
    
    // cout << "s: " << s << endl;
    if(subseq.size() < k || (subseq.size()-k)%2 != 0){
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    int total = 0;
    for(int i = 0; i < subseq.size(); i++){
        if(i < k-1){
            cout << subseq[i].size()<< " " ;
            total+=subseq[i].size();
            for(auto j : subseq[i]){
                cout << j << " ";
            }
            cout << "\n";
        } 
        else{
            cout << n-total<< " ";
            for(int i1 = i; i1 < subseq.size(); i1++){
                for(auto j : subseq[i1]){
                    cout << j << " ";
                }
            }
            cout << "\n";
            return;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
