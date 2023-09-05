#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    multiset<int> nums;
    for(int i =0; i < n; i++){
        cin >> arr[i];
        nums.insert(arr[i]);
    }
    multiset<int> gaps;
    auto i = nums.begin();
    while(i != nums.end()){
        auto nxt =i;
        ++nxt;
        if(nxt==nums.end()) break;
        gaps.insert(*nxt-*i);
        i = nxt;
    }
    int q;
    cin >> q;
    while(q--){
        int i, x;
        cin >> i >> x;
        i--;
        auto cur = nums.find(arr[i]);
        auto prev = cur, nxt = cur;
        --prev, ++nxt;
        if(cur != nums.begin()){
            gaps.erase(gaps.find(*cur - *prev));
            if(nxt != nums.end()){
                gaps.erase(gaps.find(*nxt-*cur));
                gaps.insert(*nxt-*prev);
            }
        }
        else if(nxt != nums.end()){
            gaps.erase(gaps.find(*nxt-*cur));
        }
        nums.erase(cur);
        nums.insert(x);
        cur = nums.find(x);
        prev = cur, nxt = cur;
        --prev, ++nxt;
        if(cur != nums.begin()){
            gaps.insert(*cur - *prev);
            if(nxt != nums.end()){
                gaps.insert(*nxt-*cur);
                gaps.erase(gaps.find(*nxt-*prev));
            }
        }
        else if(nxt != nums.end()){
            gaps.insert(*nxt-*cur);
        }
        int add = 0;
        if(gaps.size()) add = *gaps.rbegin();
        cout << add+ *nums.rbegin() << " ";
        arr[i] = x;
    }
    cout << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}