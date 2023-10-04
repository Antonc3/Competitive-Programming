#include <bits/stdc++.h>
using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<int> compressed;
    int ans = 0;
    int x = 0;
    while(x < n){
        if(a[x] == 0){
            int count = 0;
            while(x< n &&a[x] == 0){
                count++;
                x++;
            }
            ans+=(max(0,count-2));
            if (count >= 2 && (x != n && x - count != 0))
            {
                compressed.push_back(0);
            }
            if(count >= 2 && (x == n || x - count == 0)){
                ans++;
            }
            compressed.push_back(0);
        }
        else{
            int mx = 1;
            while(x < n && a[x] > 0){
                mx = max(a[x],mx);
                x++;
            }
            compressed.push_back(mx);
        }
    }
    int clen = compressed.size();
    x = 0;
    while(x < clen){
        if(compressed[x] == 0){
            int nxt = x+1;
            if(nxt >= clen){
                ans++;
                break;
            }
            if(compressed[nxt] == 2){
                x= nxt+2;
                ans++;
            }
            else if(compressed[nxt] == 1){
                x = nxt+1;
                ans++;
            }
            else{
                ans++;
                x=nxt;
            }
        }
        else{
            ans++;
            x+=2;
        }
    }
    cout << ans << endl;
    //
}

int main(){
    solve();
}