#include <bits/stdc++.h>
using namespace std;

int bsub(int x, vector<int> &arr){
    int l = 0, r = arr.size()-1;
    int bi = 0;
    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] <= x){
            l = mid+1;
            bi = mid;
        }
        else{
            r = mid-1;
        }
    }
    return bi;
}

int bslb(int x, vector<int> &arr){
    int l = 0, r = arr.size()-1;
    int bi = r;
    while(l <= r){
        int mid = (l+r)/2;
        if(arr[mid] >= x){
            bi = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    return bi;
}

int main(){
    int n,k;
    cin >> n;
    vector<int> arr;
    arr.push_back(INT_MIN);
    for(int i =0; i<n; i++){
        int a;
        cin >> a;
        arr.push_back(a);
    }
    arr.push_back(INT_MAX);
    sort(arr.begin(),arr.end());
    cin >> k;
    vector<int> ans;
    for(int i =0 ; i< k; i++){
        int l,r;
        cin >> l >> r;
        ans.push_back((bsub(r,arr)-bslb(l,arr)+1));
    }
    for(int x : ans) cout << x << " ";
}
