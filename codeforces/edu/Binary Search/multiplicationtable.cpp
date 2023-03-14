#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,k;

bool check(ll val){
    //cout << "val: " << val << endl;
    ll sum = 0;
    for(int i = 1; i <= n; i++){
        sum+=min(n,(val-1)/i);
    }
    //cout << "sum: " << sum << endl;
    return sum < k;
}

ll getvalid(ll val){
    bool good = false;
    while(!good){
        for(int i = 1; i <= n; i++){
            if(val%i == 0 && val/i <= n){
                return val;
            }
        }
        val--;
    }
    return val;
}

int main(){
    cin >> n >> k;
    //precompute composite values
    ll l = 0, r = 1e11;
    ll best = 0;
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
    cout << getvalid(best) << "\n";
}
/*
1 2 3 4 5
2 4 6 8 10
3 6 9 12 15
4 8 12 16 20
5 10 15 20 25
*/
