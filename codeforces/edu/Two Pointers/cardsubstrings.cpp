#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const bool DEBUG = false;
int n,m;
string s;
int cnt[30];
int main(){
    cin >> n >> m;
    string x;
    cin >> s >> x;
    for(int i = 0; i < m; i++){
        cnt[x[i]-'a']++;
    }
    int r= 0;
    ll ans = 0;
    for(int l = 0; l < n; l++){
        while(r < n && cnt[s[r]-'a'] > 0){
            cnt[s[r]-'a']--;
            r++;
        }
        ans+=r-l;
        if(DEBUG) cout << "r: " << r << " l: " << l << endl;
        cnt[s[l]-'a']++;
    }
    cout << ans << endl;
}
