#include <bits/stdc++.h>
using namespace std;

bool binarySearch(int val, vector<int> &arr){
    int l = 0, r = arr.size();
    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] == val) return true;
        else if(arr[mid] < val){
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return false;
}

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        cout << ((binarySearch(a,arr)) ? "YES" : "NO") <<"\n";
    }
}
