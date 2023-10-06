#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
#define MAXN 105
ll M = 1e9+7;

ll pow(ll b, ll e){
    ll res = 1;
    while(e > 0){
        if(e&1) res = res*b%M;
        b = (b*b)%M;
        e/=2;
    }
    return res;
}
vector<ll> fact(MAXN);
vector<ll> invfact(MAXN);
//a choose b
ll choose(ll a, ll b){
    return ((fact[a]*invfact[b])%M*invfact[a-b])%M;
}
void solve(){
    int n,i,j,x,y;
    cin >> n >> i >> j >> x >> y;
    if((i==1&&x==n)|| (j==n &&y==n)){
        cout << "0\n";
        return;
    }
    if(x > y){
        swap(x,y);
        swap(i,j);
        j = n-j+1;
        i = n-i+1;
    }
    //now x < y
    if(x < i){
        cout << "0\n";
        return;
    }
    // case where y is n

    ll ans = 0;
    if(y==n){
        ans = choose(x-1,i-1);
        int numsBetweenij = n-x-1;
        int spotsBetweenij = (j-i-1);
        if(spotsBetweenij > numsBetweenij){
            ans = 0;
        }
        ans = ans*choose(numsBetweenij,spotsBetweenij)%M;
        cout << ans << endl;
        return;
    }
    // where the thing reverse and shit
    for(int k = i+1; k < n; k++){

        if(k == j) continue;
        if(k < j){
            int spotsAvail = j-i-2;
            if(spotsAvail < 0) continue;
            int numbersGreaterThanY = n-y-1;
            if(numbersGreaterThanY > spotsAvail) continue;
            ll tmp = choose(x - 1, i - 1);
            int spotsForkj = j-k-1;
            int numsForkj = n-y-1;
            if(numsForkj < spotsForkj){
                continue;
            }
            tmp = tmp*choose(numsForkj,spotsForkj)%M;
            int numsForik = y-x-1;
            int spotsLeftForik = j-i-2-numbersGreaterThanY;
            if(numsForik < spotsLeftForik) continue;
            tmp = tmp*choose(numsForik,spotsLeftForik)%M;
            ans = (ans+tmp)%M;
            continue;
        }
        int toChooseLeft = x-1;
        int spotsLeft = i-1;
        int usedRight = toChooseLeft-spotsLeft;
        int availRight = n-k-usedRight;
        ll tmp = choose(toChooseLeft, spotsLeft);
        //in between i and j
        int numsForij = (y-x-1);
        int spotsForij = (j-i-1);
        if(numsForij < spotsForij ){
            continue;
        }
        availRight-= (numsForij-spotsForij);
        tmp = tmp*choose(numsForij,spotsForij)%M;

        int numsForjk = (n-y-1);
        int spotsForjk = (k-j-1);
        if(spotsForjk > numsForjk) continue;
        tmp = tmp*choose(numsForjk,spotsForjk)%M;
        availRight-=(numsForjk-spotsForjk);
        if(availRight == 0){
            ans = (ans+tmp)%M;
        }
    }
    cout << ans << endl;
}

int main(){
    invfact[0] = fact[0] = 1;
    for(int i = 1; i < MAXN; i++){
        fact[i] = (fact[i-1]*i)%M;
        invfact[i] = pow(fact[i],M-2);
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}