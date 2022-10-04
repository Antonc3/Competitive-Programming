#include <bits/stdc++.h>

using namespace std;

int time_[100005];
int pos[100005];

int main(){
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i =0 ; i < n; i++){
            cin >> pos[i];
        }
        for(int i =0 ; i < n; i++){
            cin >> time_[i];
        }
        int minp = pos[0]-time_[0];
        int maxp = pos[0]+time_[0];
        for(int i =0 ; i < n; i++){
            minp = min(minp,pos[i]-time_[i]);
            maxp = max(maxp,pos[i]+time_[i]);
        }
        cout << (maxp+minp)/2;
        if((maxp+minp)%2) cout << ".5";
        cout << endl;
    }
}