#include <bits/stdc++.h>

using namespace std;

int main(){
    double r, s;
    while(cin >> r){
        cin >>s;
        cout << round(sqrt(r*(s+0.16)/0.067))<<endl;
    }
}