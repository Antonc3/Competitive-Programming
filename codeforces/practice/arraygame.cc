#include <bits/stdc++.h>

using namespace std;
void solve(){
    int n;
    cin >> n;
    vector<int> arr;
    vector<int> build;
    for(int i =0 ; i < n; i++){
        int a;
        cin >> a;
        arr.push_back(a); 
    }
    int cntLeft =1;
    int cntRight =1;
    while(cntLeft < n-1 &&arr[cntLeft] < arr[cntLeft+1]){
        cntLeft++;
    }
    while(cntRight <n&& arr[n-cntRight] > arr[n-cntRight-1]){
        cntRight++;
    }
    int pL = 0;
    int pR = n-1;
    int lastNum = 0;
    int i = 0;
    for(;i<n;i++){
        if()
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}