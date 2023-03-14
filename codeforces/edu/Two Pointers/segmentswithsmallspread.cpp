#include <bits/stdc++.h>
#include <climits>
using namespace std;
typedef long long ll;
#define MAXN 100005

struct maxminstack{
    vector<ll> minS = {LLONG_MAX};
    vector<ll> maxS = {LLONG_MIN};
    vector<ll> S;
    void push(ll val){
        minS.push_back(min(minS.back(),val));
        maxS.push_back(max(maxS.back(),val));
        S.push_back(val);
    }
    ll pop(){
        ll res = S.back();
        minS.pop_back();
        maxS.pop_back();
        S.pop_back();
        return res;
    }
    ll getMin(){
        return minS.back();
    }
    ll getMax(){
        return maxS.back();
    }
    int size(){
        return S.size();
    }
};

maxminstack sl, sr;
ll getmin(){
    return min(sl.getMin(),sr.getMin());
}
ll getmax(){
    return max(sl.getMax(),sr.getMax());
}
bool empty(){
    return sl.size() == 0 && sr.size() == 0;
};
int main(){
    int n;
    ll k;
    cin >>n>>k;
    vector<ll> arr(n);
    for(auto &x : arr) cin >> x;
    ll ans = 0;
    for(int r = 0; r< n; r++){
        sr.push(arr[r]);
        while(!empty() && getmax()-getmin() > k){
            if(!sl.size())
                while(sr.size())
                    sl.push(sr.pop());
            sl.pop();
        }
        ans+=sl.size()+sr.size();
    } 
    cout << ans<<"\n";
}
