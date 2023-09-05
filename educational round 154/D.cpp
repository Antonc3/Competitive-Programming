#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int &i : arr) cin >> i;
    vector<int> inversions(n,0);
    vector<int> equal(n,0);
    vector<int> nonInversions(n,0);
    for(int i = 1; i < n; i++){
        inversions[i] = inversions[i-1];
        equal[i] = equal[i-1];
        nonInversions[i] = nonInversions[i-1];
        if(arr[i-1] > arr[i]) inversions[i] = inversions[i-1]+ 1;
        else if(arr[i-1] == arr[i]) equal[i] = equal[i-1]+1;
        else nonInversions[i] = nonInversions[i-1]+1;
        //cout << "i: " << equal[i] << " non invert: "<< nonInversions[i] << " inversions: " << inversions[i] << endl;
    }
    vector<int> invertPrefixCost(n,1);
    for(int i = 1; i < n; i++){
        invertPrefixCost[i] = 1+equal[i]+nonInversions[i];
    }
    vector<int> fixSuffix(n,n);
    for(int i = n-1; i >= 0; i--){
        fixSuffix[i] = inversions[n-1]-inversions[i]+equal[n-1]-equal[i];
    }
    int best = fixSuffix[0];
    for(int i = 1; i < n; i++){
        //cout << fixSuffix[i] << " invert " << invertPrefixCost[i-1]<<endl;
        best = min(best,invertPrefixCost[i-1] + fixSuffix[i]);
    }
    cout << best << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}