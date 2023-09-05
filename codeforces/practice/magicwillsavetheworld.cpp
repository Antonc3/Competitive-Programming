#include <bits/stdc++.h>
using namespace std;

void solve(){
    int w,f;
    cin >> w >> f;
    int n;
    cin >> n;
    vector<int> possible(n*10000+5);
    possible[0] = 1;
    int total = 0;
    for(int i =0; i < n; i++){
        int s;
        cin >> s;
        total+=s;
        for(int j = n*10000; j >= s; j--){
            possible[j] |= possible[j-s];
        }
    }
    int best = 1<<30;
    for(int i =0; i <= total; i++){
        if(!possible[i]) continue;
        int secw = i/w + (i%w > 0);
        int secf = (total-i)/f + ((total-i)%f > 0);
        best = min(best,max(secw,secf));
    }
    cout << best << endl; 
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}