#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll sqrt1(ll a){
    ll l = 0, r = min(2000000000ll,a);
    while(l <= r){
        ll mid = (l+r)/2;
        if(mid*mid==a) return mid;
        if(mid*mid < a){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return -1;
}

void solve(){
    int n;
    cin >> n;
    map<ll,ll> cnt;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(cnt.count(a) > 0){
            cnt[a]++;
        }
        else{
            cnt[a] = 1;
        }
    }
    int q;
    
    cin >> q;
    while(q--){
        ll x, y;
        cin >> x >> y;
        ll b = -x;
        ll c = y;
        ll determinant = b*b-4*c;
        if(determinant < 0){
            cout << "0 ";
            continue;
        }
        if(determinant == 0){
            ll occ = cnt[x/2];
            if (x & 1)
            {
                cout << "0 ";
                continue;
            }
            cout << (occ*(occ-1))/2 << " ";
        }
        else{
            ll sqrtans = sqrt1(determinant);
            if(sqrtans==-1 || (sqrtans+b)&1){
                cout << "0 ";
                continue;
            }
            ll ans1 = (-b+sqrtans)/2;
            ll ans2 = (-b-sqrtans)/2;
            ll sol = cnt[ans1]*cnt[ans2];
            cout << sol << " ";
        }
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