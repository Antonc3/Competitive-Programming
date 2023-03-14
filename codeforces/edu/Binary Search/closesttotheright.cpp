#include <bits/stdc++.h>
using namespace std;

int binarySearch(int val, vector<int> &arr){
    int l = 0, r = arr.size()-1;
    int bi = arr.size()-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] >= val){
            bi = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return bi+1;
}

int main(){
    int n,k;
    cin >> n>>k;
    vector<int> arr(n);
    for(int &x : arr) cin >> x;
    arr.push_back(INT_MAX);
    for(int i =0; i < k; i++){
        int a;
        cin >> a;
        cout << binarySearch(a,arr)<<"\n";
    }
}
