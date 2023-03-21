#include <bits/stdc++.h>
#include <ios>
using namespace std;
 
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n,x;
    cin >> n >> x;
    vector<int> cnt(x+1,0);
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        if(a >= x) continue;
        cnt[a]++;
    }
    for(int i = 1; i < x; i++){
        if(cnt[i] >= i+1){
            cnt[i+1] =cnt[i+1] + (cnt[i]/(i+1));
            cnt[i] = cnt[i]%(i+1);
        }
        if(cnt[i] != 0){
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
}
