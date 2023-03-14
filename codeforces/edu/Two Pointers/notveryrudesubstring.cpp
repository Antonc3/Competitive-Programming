#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const bool DEBUG = false;
string s;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n;
    ll m;
    cin >> n >> m;
    cin>> s;
    int r= 0;
    int ans = 0;
    int a = 0;
    int b=0;
    ll cr = 0;
    for(int l = 0; l < n; l++){
        while( r < n && cr+((s[r]=='b') ? a:0)<= m){
            if(s[r] == 'a'){
                a++;
            }
            else if(s[r] == 'b'){
                b++;
                cr+=a;
            }
            r++;
        }
        if(DEBUG) cout << l << " r: " << r << endl;
        ans = max(ans,r-l);
        if(s[l] == 'a'){
            cr-=b;
            a--;
        }
        else if(s[l] == 'b'){
            b--;
        }
    }
    cout << ans << endl;
}
