#include <bits/stdc++.h>
using namespace std;

struct worker{
    int t, z,y;
};
int m,n;
vector<worker> arr;
vector<int> ans;
bool check(int val){
    int cnt = 0;
    fill(ans.begin(),ans.end(),0);
    for(int i = 0; i < n; i++){
        auto cur = arr[i];
        int cycletotal = cur.z*cur.t+cur.y;
        int cyclecnt = val/cycletotal;
        int left = val%cycletotal;
        int toadd = cyclecnt*cur.z + min(cur.z,left/cur.t);
        if(cnt+toadd>=m){
            ans[i] = m-cnt;
            return true;
        }
        ans[i] = toadd;
        cnt+=toadd;
    }
    return cnt >= m;
}

int main(){
    cin >> m >> n;
    arr = vector<worker>(n);
    ans = vector<int>(n);
    for(auto &x : arr){
        cin >> x.t >> x.z >> x.y;
    }
    int l = 0, r = INT_MAX;
    int best = r;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            best = mid;
            r = mid-1;
        }
        else{
            l = mid+1;
        }
    }
    check(best);
    cout << best << endl;
    for(int i : ans) cout << i << " ";
}
