#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const bool DEBUG = false;

vector<ll> primeFactor(ll f){
    vector<ll> res;
    ll f2 = f;
    for(int i = 2; i <= sqrt(f); i++){
        while(f2%i == 0){
            res.push_back(i);
            f2/=i;
        }
    }
    if(f2 > 1) res.push_back(f2);
    return res;
}

vector<ll> getFactorsFromPrime(vector<int> &count, vector<ll> &val, int v){
    vector<ll> res;
    vector<int> cnt(count.size(), 0);
    ll tot = 1;
    //if(DEBUG) cout << v << endl;
    for(int i = 0; i < count.size(); i++){
        cnt[i] = v%(count[i]+1);
        v/=(count[i]+1);
        tot*=cnt[i]+1;
    }
    if(DEBUG){
        for(auto i : cnt){
            cout << i << " ";
        }
        cout << endl;
    }
    //if(DEBUG) cout << "TOT: " <<tot << endl;
    for(int i = 0; i < tot; i++){
        int i2 = i;
        ll cur = 1;
        for(int j =0; j < cnt.size(); j++){
            cur*=pow(val[j],i2%(cnt[j]+1));
            i2/=(cnt[j]+1); 
        }
        res.push_back(cur);
    }
    //if(DEBUG) cout << "RES size: " << res.size()<<endl;
    return res;
}

void solve(){
    ll n,m1,m2;
    cin >> n >> m1 >> m2;
    vector<ll> allPrimeFactors = primeFactor(m1); 
    if(DEBUG) cout << "m1primesize " << allPrimeFactors.size()<<endl;
    vector<ll> m2prime = primeFactor(m2); 
    if(DEBUG) cout << " m2 " << m2prime.size()<<endl;
    allPrimeFactors.insert(allPrimeFactors.end(),m2prime.begin(),m2prime.end());
    sort(allPrimeFactors.begin(),allPrimeFactors.end());
    vector<int> count;
    vector<ll> val;
    for(int i = 0; i < allPrimeFactors.size(); i++){
        if(DEBUG) cout << allPrimeFactors[i] << " ";
        if(i == 0 || allPrimeFactors[i] != allPrimeFactors[i-1]){
            count.push_back(1);
            val.push_back(allPrimeFactors[i]);
        }
        else{
            count.back()++;
        }
    }
    if(DEBUG) cout << "\n";
    ll tot = 1;
    for(int i =0; i < count.size(); i++){
        if(DEBUG) cout << "tot: " << tot<<endl;
        tot*=(1+count[i]);
    }
    int ans = 0;

    if(DEBUG) cout << "TOT: " << tot << " count.size() " << count.size()<< "\n";
    vector<ll> allFactors = getFactorsFromPrime(count,val,tot-1);
    sort(allFactors.begin(),allFactors.end());
    int ansPart2 = 0;
    for(int i = 0; i < tot; i++){
        ll cur = 1;
        int i2 = i;
        for(int j =0; j < count.size(); j++){
            cur*=pow(val[j],i2%(count[j]+1));
            i2/=(count[j]+1); 
        }
        if(n*n < cur) continue;
        auto lb = lower_bound(allFactors.begin(), allFactors.end(),ceil(1.0*cur/n));
        for(auto j = lb; j != allFactors.end(); j++){
            if((*j) > n) break;
            if(cur%(*j) == 0 && (cur/(*j)) <= n){
                ans++;
                ansPart2^=(*j);
                if(DEBUG)cout << "j: " << (*j) << " cur: " << cur << endl;
                break;
            }
        }
        // vector<ll> curFactors = getFactorsFromPrime(count,val,i);
        // sort(curFactors.begin(),curFactors.end());
        // ll curVal = curFactors.back();
        // //if(DEBUG) cout << "CURVAL: " << curVal << "\n";
        // for(int j = 0; j < curFactors.size(); j++){
        //     if(curFactors[j] > n) break;
        //     if(curFactors[j] <= n && curVal/curFactors[j] <= n){
        //         //if(DEBUG) cout << "WOT: " << curFactors[j] << " " << curVal/curFactors[j]<<endl;
        //         ansPart2 ^= curFactors[j];
        //         ans++;
        //         break;
        //     }
        // }
    }
    cout << ans << " " << ansPart2<<endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}