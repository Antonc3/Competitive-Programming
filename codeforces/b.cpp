#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int a,b;
        cin >> a >> b;
        if(a >= b){
            cout << "YES\n";
            continue;
        }

        if(a <=3){
            if(b > 3 || a==1){
                cout << "NO\n";
            }
            else{
                cout << "YES\n";
            }
            continue;
        }
        else{
            cout << "YES\n";
            continue;
        }
    }
}