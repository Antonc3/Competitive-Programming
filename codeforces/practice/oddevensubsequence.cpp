#include <bits/stdc++.h>
using namespace std;

int n,k;
bool check(vector<long long> &a, long long v){
    int ans = 0;
    int cnt = 0;
    //first check for even subsequence
    for(int i = 0; i < n; i++){
        if(cnt){
            ans++;
            cnt = !cnt;
        }
        else{
            if(a[i] <= v){
                ans++;
                cnt = !cnt;
            }
        }
    }
    int ans2 = 1;
    cnt = 0;
    //first check for even subsequence
    for(int i = 1; i < n; i++){
        if(cnt){
            ans2++;
            cnt = !cnt;
        }
        else{
            if(a[i] <= v){
                ans2++;
                cnt = !cnt;
            }
        }
    }
    return (ans >= k) || (ans2 >= k);
}

int main(){
    cin >> n >> k;
    vector<long long> a(n);
    for(long long &x : a) cin >> x;
    long long l = 1, r = 1e9;
    while(l < r){
        int m = (l+r)/2;
        if(check(a,m)){
            r = m;
        }
        else{
            l = m+1;
        }
    }
    cout << l << "\n";
}
