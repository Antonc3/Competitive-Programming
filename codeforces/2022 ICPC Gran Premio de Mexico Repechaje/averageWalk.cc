#include <bits/stdc++.h>

using namespace std;

int main(){
    int n;
    cin >> n;
    // cout << ((3000%n > 0) ? 1 : 0)<<endl;
    int leftover = (3000%n>0) ? 1: 0;
    cout << min(15, (3000/n)+leftover);
}