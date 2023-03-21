#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> cnt(3,0);
vector<int> initial(3);
vector<int> price(3);
ll r;

bool check(ll val){
    ll rr = r;
    for(int i =0 ; i < 3; i++){
        //cout << "required pieces: " << 1ll*cnt[i]*val << " initial " << initial[i] << " price " << price[i] << endl;
        rr-=max(0ll,(1ll*cnt[i]*val-initial[i])*price[i]);
    }
    //intcout << "val: " << val << " " <<rr << endl;
    return rr >= 0;
}

int main(){

    string s;
    cin >> s;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == 'B') cnt[0]++;
        if(s[i] == 'S') cnt[1]++;
        if(s[i] == 'C') cnt[2]++;
        }
    for(int &x : initial) cin >> x;
    for(int &x : price) cin >> x;
    cin >> r;

    ll l = 0;
    ll r = 1e15;
    ll best = l;
    while(l <= r){
        ll mid = (l+r)/2;
        if(check(mid)){
            best = mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    cout << best << endl;
}
