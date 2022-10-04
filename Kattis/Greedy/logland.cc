#include <bits/stdc++.h>

using namespace std;
#define MAXN 1000005
int MOD = 1e9+7;
int k;
long long coins[MAXN];
long long aug[MAXN];
// need to make fastpow with log
int lost[MAXN];
// int fastPow2(int num){
//     long long ans = 1;
//     long long mult = 2;
//     while(num>0){
//         if(num%2) ans*=mult;
//         mult*=mult;
//         mult%=MOD;
//         ans%=MOD;
//         num/=2;
//     }
//     return (int) (ans%MOD);
// }

int main(){
    cin >> k;
    fill(aug, aug+k, 0);
    fill(lost, lost+k, 0);
    for(int i = 0; i < k; i++){
        cin >> coins[i];
        aug[i]+=coins[i];
        if(i < k-1){
            aug[i+1]+=aug[i]/2;
            aug[i]%=2;
        }
    }
    //want to grab the biggest coins possible
    //if total value is bigger than 2*biggest coin you can always grab
    // the biggest coin

    for(int i = k-1; i >= 1; i--){
        if(!(aug[i] > coins[i] || coins[i]%2==0)) lost[i] = 1;
        aug[i]-=coins[i];
        aug[i-1]+=aug[i]*2;
    }
    // cout << aug[0] << " " << endl;
    lost[0] = (aug[0]%2!=0);
    // for(int i = k-1; i >= 0; i--){
    //     coins[i]%=2;
    //     if(coins[i]==0) continue;
    //     int j = 1;
    //     long long needed = 2;
    //     long long total = 0;
    //     vector<int> usedCoins(40,0);
    //     while(j <= 35 && i-j >=0){
    //         if(total+coins[i-j] >= needed){
    //             usedCoins[j] += needed-total;
    //             total=needed;
    //             j++;
    //             break;
    //         }
    //         usedCoins[j] = coins[i-j];
    //         total+=coins[i-j];
    //         needed*=2;
    //         total*=2;
    //         j++;
    //     }
    //     if(total < needed) continue;
    //     coins[i] = 0;
    //     for(int ii = 0; ii < 40; ii++){
    //         if(i-ii < 0) break;
    //         coins[i-ii]-=usedCoins[ii];
    //     }
    // }
    long long ans = 0;
    long long mult = 1;
    for(int i = 0; i < k; i++){
        ans+= lost[i]*mult;
        mult*=2;
        mult%=MOD;
        ans%=MOD;
    }
    cout << ans << endl;
}