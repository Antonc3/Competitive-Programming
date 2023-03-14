#include <bits/stdc++.h>
using namespace std;

int n,k;
vector<int> stalls;

bool check(int val){
    int numarranged = 1;
    int last = stalls[0];
    for(int i = 1;i < n; i++){
        if(stalls[i]-last >= val){
            numarranged++;
            last = stalls[i];
        }
    }
    return numarranged >= k;
}

int main(){
    cin >> n >> k;
    stalls = vector<int>(n);
    for(int &x : stalls) cin >> x;
    sort(stalls.begin(),stalls.end());
    int l = 0, r = 1e9;
    int best = l;
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
