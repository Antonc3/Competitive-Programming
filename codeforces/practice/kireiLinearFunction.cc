#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005
#define f first
#define s second
typedef pair<int,int> pii;
string s;
int w, n, m;

int digits[2][10];
int pref[MAXN];
void solve(){
    cin >> s;
    cin >> w >> m;
    n = s.length();
    int cur = 0;
    fill(&digits[0][0], &digits[0][0]+sizeof(digits)/sizeof(digits[0][0]),-1);
    for(int i = 0; i < w; i++){
        cur += (s[i]-'0');
        cur%=9;
        // cout << "incrementing cur: " <<cur << endl;
    }
    for(int i = w; i <= n; i++){
        //length m shit
        // cout << "cur: " <<cur<< endl;
        if(digits[0][cur] == -1){
            digits[0][cur] = i-w;
        }
        else{
            if(digits[1][cur] == -1) digits[1][cur] = i-w;
        }
        if(i==n) break;
        cur+=(s[i]-'0')+9;
        cur-=(s[i-w]-'0');
        cur%=9;
    }
    // for(int i = 0; i < 9; i++){
    //     cout << i << ": " << digits[0][i] << ", " << digits[1][i]<<endl;
    // }
    pref[0] = 0;
    // cout << "PREFIX: 0, ";
    for(int i = 1; i <= n; i++){
        pref[i] = (pref[i-1]+(s[i-1]-'0'))%9;
        // cout << pref[i] << ", ";
    }
    // cout << endl;
    for(int i = 0; i < m; i++){
        int l, r, k;
        cin >> l >> r >> k;
        l--;
        // cout << pref[l] << ", " << pref[r] << endl;
        int lr9 = (pref[r]-pref[l]+9)%9;
        // cout << "lr9: " << lr9<<endl;
        vector<pii> sols;
        for(int j = 0; j < 9; j++){

            if(digits[0][j] == -1)continue;
            for(int a = 0; a < 9; a++){
                if(digits[0][a] == -1)continue;
                if(j==a){
                    if(digits[1][a]== -1) continue;
                    if(((lr9+1)*a)%9 == k){
                        
                        sols.push_back({digits[0][j],digits[1][j]});
                    }
                    continue;
                }
                if((lr9*j+a)%9==k){
                    // cout << "Checking: " << (lr9*j+a)<<endl;
                    sols.push_back({digits[0][j],digits[0][a]});
                }
            }
        }
        if(sols.size() == 0){
            cout << "-1 -1"<<endl;
            continue;
        }
        sort(sols.begin(),sols.end());
        cout << sols[0].f+1 << " " << sols[0].s+1<<endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}