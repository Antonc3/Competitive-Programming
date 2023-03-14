#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define INF 1e9+2

int main(){
    int n;
    cin >> n;
    vector<pair<int,int>> arr;
    
    arr.push_back({-INF,0});
    for(int i =0;i < n; i++){
        int a,b;
        cin >> a>>b;
        arr.push_back({a,b});
    }
    arr.push_back({2*INF,0});
    int ans = 0;
    int last = -(INF);
    for(int i = 1; i <=n; i++){
        // cout << "last: " << last <<"ans: " << ans<<endl;
        if(arr[i].f-last > arr[i].s){
            ans++;
        }
        else if(arr[i].f + arr[i].s < arr[i+1].f){
            ans++;
            last = arr[i].f +arr[i].s;
            continue;
        }
        last = arr[i].f;
    }
    cout << ans;
}
