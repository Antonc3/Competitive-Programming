#include <bits/stdc++.h>
#include <ostream>
using namespace std;

int main(){
    int n,m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    for(auto &x : arr1) cin >> x;
    for(auto &x : arr2) cin >> x;
    int i1 = 0, i2 = 0;
    long long ans = 0;
    while(i1 < n && i2 < m){
        //cout << "i1: " << i1 << " i2: " << i2<<endl;
        //cout << "arr[i1] " << arr1[i1] << " arr[i2] " << arr2[i2] << endl;
        if(arr1[i1] == arr2[i2]){
            long long cnt1 = 1,cnt2 = 1;
            i1++; i2++;
            while(i1 < n && arr1[i1-1] == arr1[i1]){
                cnt1++; i1++;
            }
            while(i2 < m && arr2[i2-1] == arr2[i2]){
                cnt2++; i2++;
            }
            //cout << "arr[i]: " << arr1[i1] << " cnt1: " << cnt1 << " cnt2: " << cnt2<<endl;
            ans+=cnt1*cnt2;
        }
        else if(arr1[i1] < arr2[i2]) i1++;
        else i2++;

    }
    cout << ans << endl;
}
