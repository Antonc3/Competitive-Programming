#include <bits/stdc++.h>
using namespace std;

void solve(){
    string s;
    cin >> s;
    int n=s.length();
    int curlen = 0;
    set<pair<int,int>> curSort;
    bool good = true;
    for(int i =0 ; i < n; i++){
        char c = s[i];
        if(c=='+'){
            curlen++;
        }
        else if(c=='-'){
            curlen--;
            if(curSort.size() == 0) continue;
            auto fr = *curSort.rbegin();
            if(fr.first > curlen){
                if(fr.second == 1 && fr.first >= 2){
                    curSort.insert({curlen,1});
                }
                curSort.erase(prev(curSort.end()));
            }
        }
        else if(c=='0'){
            if(curlen <= 1){
                good = false;
                break;
            }
            if(curSort.size() == 0){
                curSort.insert({curlen, 0});
                continue;
            }
            auto fr = *curSort.rbegin();
            if(fr.first == curlen){
                if(fr.second != 0){
                    good = false;
                    break;
                }
            }
            if(fr.first != curlen){
                curSort.insert({curlen, 0});
            }
        }
        else{
            if(curSort.size() == 0){
                curSort.insert({curlen, 1});
                continue;
            }
            auto fr = *curSort.rbegin();
            if (fr.second != 1)
            {
                good = false;
                break;
            }
            if(fr.first != curlen && curlen >= 2){
                 curSort.insert({curlen,1});
            }
        }
    }
    if(good) cout << "YES\n";
    else cout << "NO\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}