#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> correct(n);
    vector<int> userinp(n);
    for(int &x : correct) cin >> x;
    for(int &x : userinp) cin >> x;
    for(int i =0 ; i < n; i++){
        if(userinp[i] != correct[i]){
            cout << "LINE: " << i << "\n";
        }
    }

}
