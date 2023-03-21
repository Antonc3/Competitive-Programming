#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii ;
typedef long long ll;
#define F first
#define S second

vector<pii> v;
int n,k;

bool check(ll val){
    ll sum = 0;
    for(pii i : v){
        sum+=min(1ll*i.S-i.F+1,max(0ll,val-i.F));
    }
    return sum <=k;
}

int main(){
    cin >> n >> k;
    for(int i = 0;i < n; i++){
        int a,b;
        cin >> a >> b;
        v.push_back({a,b});
    }
    ll l = -2e9, r = 2e9;
    ll best = l;
    while(l <= r){
        int mid = (l+r)/2;
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
