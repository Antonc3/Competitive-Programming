#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b){
    if(a==0) return b;
    return gcd(b%a,a);
}

struct gcdstack{
    vector<ll> S;
    vector<ll> gcdS;
    void push(ll val){
        S.push_back(val);
        if(gcdS.empty()){
            gcdS.push_back(val);
        }
        else{
            gcdS.push_back(gcd(gcdS.back(),val));
        }
    }
    ll getgcd(){
        if(S.empty()) return LLONG_MAX;
        return gcdS.back();
    }
    ll pop(){
        ll val = S.back();
        S.pop_back();
        gcdS.pop_back();
        return val;
    }
    int size(){
        return S.size();
    }
    void clear(){
        S.clear();
        gcdS.clear();
    }
};
gcdstack s1, s2;
ll getgcd(){
    if(!s1.size()) return s2.getgcd();
    if(!s2.size()) return s1.getgcd();
    return gcd(s1.getgcd(),s2.getgcd());
}
bool good(){
    return (s1.size()|| s2.size()) && getgcd() == 1;
}
void remove(){
    if(!s1.size())
        while(s2.size())
            s1.push(s2.pop());
    s1.pop();
}
void clear(){
    s1.clear();
    s2.clear();
}

int main(){
    int n;
    cin >> n;
    vector<ll> arr(n);
    for(auto &x: arr) cin >> x;
    int r = 0;
    int ans = 1e9;
    for(int l = 0; l < n; l++){
        if(r <= l){
            clear();
            r =l;
        }
        //cout << "l: " << l << " r: " << r << endl;
        while(r < n && !good()){
            s2.push(arr[r]);
            r++;
        }
        if(good()){
            ans = min(ans, s1.size() + s2.size());
        }
        if(s1.size() || s2.size()){
            remove();
        }
    }
    if(ans == 1e9) cout << -1 << endl;
    else cout << ans << "\n";
}
