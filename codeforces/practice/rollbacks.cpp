#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;
    vector<int> arr(1e6+5,-1), a(1e6+5,0);
    vector<int> pref(1e6+5,0);
    int r = 0;
    vector<tuple<char,int,int,int,int>> changes;
    while(q--){
        char c;
        cin >> c;
        if(c=='+'){
            int x;
            cin >> x;
            int bef = a[r+1];
            int last = arr[x];
            int lastpref = pref[r+1];
            if(arr[x] > r || arr[x] == -1 || a[arr[x]] != x){
                pref[r+1] = pref[r] + 1;
                arr[x] = r+1;
            }
            else{
                pref[r+1] = pref[r];
            }
            r = r+1;
            a[r] = x;
            changes.push_back({c,x,last,lastpref,bef});
        }
        else if(c=='-'){
            int x;
            cin >> x;
            r = r-x;
            changes.push_back({c,x,0,0,0});
        }
        else if(c=='!'){
            auto [c1,x,last,lastpref,bef] = changes.back();
            if(c1 == '-'){
                r = r+x;
            }
            else{
                pref[r] = lastpref;
                arr[x] = last;
                a[r] = bef;
                r = r-1;
            }
            changes.pop_back(); 
        }
        else{
            cout << pref[r] << "\n";
        }
    }
}