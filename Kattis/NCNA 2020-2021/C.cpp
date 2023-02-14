#include <bits/stdc++.h>

using namespace std;
#define M 998244353

long long n;
int t;
unordered_map<long long,long long> m;
long long recurse(long long num){
    if(num < 0){
        return 0;
    }
    if(m.count(num)!=0){
        return m[num];
    }
    long long ret = 0;
    for(int i = 0; i <= t; i++){
        if(i%2==num%2){
            ret += recurse((num-i)/2);
            ret%=M;
        }
    }
    m.insert({num,ret});
    return ret;
}

int main(){
    cin >> n >> t;
    m.insert({0,1});
    cout << recurse(n);
}