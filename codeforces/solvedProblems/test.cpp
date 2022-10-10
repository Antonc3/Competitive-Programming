#include <bits/stdc++.h>
using namespace std;

int main(){
    int a,b,c;
    cin >>a >> b >> c;
    if(a+c < b){
        cout << "-";
        return 0;
    }
    if(a > b+c){
        cout << "+";
        return 0;
    }
    if(a == b  && c == 0){
        cout << "0";
        return 0;
    }
    cout << "?";
}
