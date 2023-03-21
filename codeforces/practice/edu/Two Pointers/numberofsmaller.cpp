#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    for(auto &x : arr1) cin >> x;
    for(auto &x : arr2) cin >> x;
    int i1 = 0;
    for(int i = 0; i < m; i++){
        while(i1 < n && arr1[i1] < arr2[i]){
            i1++;
        }
        cout << i1 << " ";
    }
}
