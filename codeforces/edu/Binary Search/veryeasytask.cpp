#include <bits/stdc++.h>
#include <climits>
using namespace std;

int main(){
    int n,x,y;
    cin >> n >> x >> y;
    if(x > y) swap(x,y);
    int l = 0, r = INT_MAX;
    int best = r;
    while(l <= r){
        int mid = (l+r)/2;
        if(mid/x + (mid-x)/y >= n){
            best = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    cout << best << endl;
}
