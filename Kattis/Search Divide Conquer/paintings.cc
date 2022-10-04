#include <bits/stdc++.h>

using namespace std;

int n;
string colors[12];
vector<vector<bool>> v;
vector<bool> used;
vector<int> curpath;
vector<int> bestpath;
int arrang;
void recurse(){
    // cout << "recurse callsed!\n";
    // for(int i : curpath){
    //     cout << i << " ";
    // }
    // cout << endl;
    if(curpath.size() == n){
        if(bestpath.empty()) bestpath = curpath;
        arrang++;
        return;
    }
    for(int i =0; i < n; i++){
        if(!used[i]){
            if(!curpath.empty() && !v[curpath.back()][i]) continue;
            used[i] = true;
            curpath.push_back(i);
            recurse();
            curpath.pop_back();
            used[i] = false;
        }
    }
}

void solve(){
    cin >> n;
    v.clear();
    used.clear();
    v.resize(n, vector<bool>(n,true));
    used.resize(n, false);
    bestpath.clear();
    unordered_map<string,int> mp;
    for(int i = 0; i < n; i++){
        cin >> colors[i];
        mp[colors[i]] = i;
    }
    int m;
    cin >> m;
    for(int i = 0; i < m; i++){
        string a,b;
        cin >> a >> b;
        v[mp[a]][mp[b]] = false;
        v[mp[b]][mp[a]] = false;
    }
    // for(int i =0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout<<v[i][j]<< " ";
    //     }
    //     cout << endl;
    // }
    arrang = 0;
    recurse();
    cout << arrang<<endl;
    for(auto i : bestpath){
        cout << colors[i] << " ";
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