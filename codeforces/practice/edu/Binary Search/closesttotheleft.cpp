#include <bits/stdc++.h>
using namespace std;

int binarySearch(int val, vector<int> &arr){
    int l = 0, r = arr.size()-1;
    int bi = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] <= val){
            bi=mid;
            l = mid+1;
        }
        else{
            r = mid-1;
        }
    }
    return bi;
}

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> arr;
    arr.push_back(INT_MIN);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        arr.push_back(a);
    }
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        cout << binarySearch(a,arr)<<endl;
    }
}
