#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a) cin >> x;
    vector<int> b(n,0);
    for(int i = 0; i < n; i++){
        int x = a[i];
        while(x > 0){
            b[i]++;
            x/=2;
        }
    }
    for(int i = 0; i < n-2; i++){
        if(b[i] == b[i+1] && b[i+1] == b[i+2]){
            cout << "1\n";
            return 0;
        }
    }
    int best = 1e9;
    for(int m = 1; m < n; m++){
        int lowcur = 0;
        for(int i = m-1; i >= 0; i--){
            lowcur = lowcur ^ a[i];
            int cur = 0;
            for(int j = m; j < n; j++){
                cur = cur ^ a[j];
                if(cur < lowcur){
                    best = min(best,j-m+m-1-i);
                }
            }
        }
    }
    if(best == 1e9){
        cout << -1<<"\n";
    }
    else cout << best << "\n";
}
