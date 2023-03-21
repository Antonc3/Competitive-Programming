#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<string> a(n);
    for(string &x : a) cin >> x;
    vector<int> avail(n,0);
    vector<int> oddness(n,0);
    map<pair<int,int>,int> mp;
    for(int i = 0; i < n; i++){
        string cur = a[i];
        ll curavail = 0;
        for(int j = 0; j < a[i].length(); j++){
            curavail = curavail |= (1<<(cur[j]-'a'));
            oddness[i] ^= (1<<(cur[j]-'a'));
        }
        avail[i] = curavail;
        if(a[i].length()%2) continue;
        for(int j = 0; j < 26; j++){
            if(curavail&(1<<j)) continue;
            mp[{oddness[i],j}]++;
        }
    }

    int toxor = pow(2,26)-1;
    ll ans = 0;
    for(int c = 0; c < 26; c++){
        toxor = toxor ^= (1<<c);
        vector<int> tocheck;
        for(int i = 0; i < n; i++){
            if(avail[i] & (1<<c)) continue;
            if(a[i].length()%2==0) continue;
            if(mp.find({oddness[i]^toxor,c})!=mp.end()) ans += mp[{oddness[i]^toxor,c}];
        }
        toxor = toxor ^= (1<<c);
    }
    cout << ans <<"\n";
}
