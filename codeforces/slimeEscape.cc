#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

int n, k;
long long slimes[MAXN];

void solve(){
    cin >> n >> k;
    k--;
    for(int i = 0; i < n; i++){
        cin >> slimes[i];
    }
    int r = k+1;
    int l = k-1;
    long long health = slimes[k];

    long long lMin = 0, lSum = 0;
    int il = l;
    bool useLeft = true;

    long long rMin = 0, rSum = 0;
    int ir = r;
    bool useRight = true;
    while( l >= 0 && r < n){
        // cout << "L: " << l << ", r: " << r << endl;
        if(useLeft){
            // cout << "CHECKING LEFT" <<endl;
            lMin = 0;
            lSum = 0;
            for(il = l; il >= 0; il--){
                lSum+=slimes[il];
                lMin=min(lSum,lMin);
                if(lSum > 0){
                    il--;
                    break;
                }
            }
            // cout << "HEALtH: " << health << endl;
            // cout << "LMIN: " << lMin << ", lSum: " << lSum<<endl;
            if(health+lMin >= 0){
                useLeft = true;
                health+=lSum;
                l = il;
                lMin = -9999999999999;
                lSum = 0;
            }
            else{
                useLeft = false;
            }
            if(health+rMin >= 0){
                useRight = true;
                health+=rSum;
                r = ir;
                rSum = 0;
            }
        }
        if(useRight){
            // cout << "CHECKING RIGHT"<<endl;
            rMin = 0;
            rSum = 0;
            for(ir = r; ir <n; ir++){
                rSum+=slimes[ir];
                rMin=min(rSum,rMin);
                if(rSum > 0){
                    ir++;
                    break;
                }
            }
            // cout << "HEALtH: " << health << endl;
            // cout << "LMIN: " << rMin << ", lSum: " << rSum<<endl;
            if(health+rMin >= 0){
                useRight = true;
                health+=rSum;
                r = ir;
                rMin = -99999999999999;
                rSum = 0;
            }
            else{
                useRight = false;
            }
            if(health+lMin >= 0){
                useLeft = true;
                health+=lSum;
                l = il;
                lSum = 0;
            }
        }
        
        if(!useLeft && !useRight){
            cout << "NO\n";
            return;
        }  
    }
    cout << "YES\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}