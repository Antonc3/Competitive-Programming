#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    set<int> brackets[2];
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        a[i] = (s[i]=='(');
    }
    for(int i = 0; i < n-1; i++){
        if(a[i] == a[i+1]){
            brackets[a[i]].insert(i);
        }
    }
    while(q--){
        int x;
        cin >> x;
        if(n&1){
            cout << "NO\n";
            continue;
        }
        x--;
        if(x > 0){
            if(a[x-1] == a[x]){
                brackets[a[x]].erase(x-1);
            }
            else{
                brackets[a[x-1]].insert(x-1);
            }
        }
        if(x < n-1){
            if(a[x+1] == a[x]){
                brackets[a[x]].erase(x);
            }
            else{
                brackets[a[x+1]].insert(x);
            }
        }
        a[x] = !a[x];
        if(a[0] == 0 || a[n-1] == 1){
            cout << "NO\n";
            continue;
        }
        if(brackets[0].size() && brackets[1].size()){
            int lFirst = (*brackets[1].begin());
            int lLast = (*brackets[1].rbegin());
            int rFirst = (*brackets[0].begin());
            int rLast = (*brackets[0].rbegin());
            if(rFirst < lFirst || lLast > rLast){
                cout << "NO\n";
                continue;
            }
            cout << "YES\n";
        }
        else if(brackets[1].size() || brackets[0].size()){
            cout << "NO\n";
        }
        else{
            cout << "YES\n";
        }
    }
}

int main(){
    solve();
}
