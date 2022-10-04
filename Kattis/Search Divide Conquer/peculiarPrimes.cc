#include <bits/stdc++.h>

using namespace std;
int n;
int x,y;
// int MAX_INT = 2147483647;

// int binSearch(vector<int> &v, int num){
//     int l = 0, r = v.size();
//     while(l < r){
//         int cur = (l+r)/2;
//         if(v[cur] == num) return cur;
//         if(v[cur] < num) l = cur+1;
//         if(v[cur] > num) r = cur;
//     }
//     return r;
// }
int primes[10];
long long ans[300000],  b;
void find(int min, long long cur){
    if(cur >= x && cur <= y) ans[b++] = cur;
    for(int i = min; i < n; i++){
        if(cur*primes[i] <=y)
            find(i,cur*primes[i]);
    }
}

void solve(){
    for(int i =0; i < n; i++){
        cin >> primes[i];
    }
    
    // int x,y;
    cin >> x >> y;
    // vector<int> ans;
    // vector<int> nums;
    // nums.push_back(1);
    // for(int i = 0; i < n; i++){
    //     int numStartLen = nums.size();
    //     for(int j =0; j < numStartLen; j++){
    //         long long cur = nums[j]*primes[i];
    //         while(cur <= y){
    //             if(cur >= x) ans.push_back((int) cur);
    //             nums.push_back((int) cur);
    //             cur*=primes[i];
    //         }
    //     }
    // }
    // if(x==1) ans.push_back(1);
    b=0;
    find(0,1);
    sort(ans, ans+b);
    if(b == 0) cout << "none";
    for(int i = 0; i < b; i++){
        cout << ans[i];
        if(i != b-1) cout << ",";
    }
    cout << endl;
    // int l = binSearch(nums, x);
    // int r = binSearch(nums, y);
    // if(nums[r] > y && l == r){
    //     cout << "none\n";
    //     return;
    // } 

    // for(int i = l; i < r; i++){
    //     cout << nums[i];
    //     if(i != r-1) cout << ",";
    // }
    // // cout << 'l' << l << 'r' << r<<endl;
    // if(l != r && nums[r]==y) cout << ",";
    // if(nums[r] == y) cout << y;
    // cout << endl;
}

int main(){
    cin >> n;
    while(n){
        solve();
        cin >> n;
    }
}