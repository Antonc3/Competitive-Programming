#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n,k;
        cin >> n >> k;
        vector<int> ans(n,-10);
        int MAXVAL = 1000;

        int pos = n-1;
        while(k > 0){
            if(k > pos){
                ans[pos] = 1000; 
                k-=pos+1;
                pos--;
                continue;
            }
            ans[pos] = 10*k-1;
            k = 0;
        }
        for(int i : ans) cout << i << " ";
        cout << "\n";
    }
}
