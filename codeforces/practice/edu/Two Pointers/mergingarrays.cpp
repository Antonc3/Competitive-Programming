#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    for(auto &x : arr1) cin >> x;
    for(auto &x : arr2) cin >> x;
    vector<int> ans;
    int i1=0, i2=0;
    while(i1 < n || i2 < m){
        if(i1 == n){
            ans.push_back(arr2[i2]);
            i2++;
        }
        else if(i2==m){
            ans.push_back(arr1[i1]);
            i1++;
        }
        else{
            if(arr1[i1] < arr2[i2]){
                ans.push_back(arr1[i1]);
                i1++;
            }
            else{
                ans.push_back(arr2[i2]);
                i2++;
            }
        }
    }
    for(auto i : ans) cout << i << " ";

}

