#include <bits/stdc++.h>
using namespace std;
static int MOD = 1e9+7;

int calcmod(int a,int m){
    return (a >= 0) ? a%m : calcmod(a+m,m);
}
int main(){
    int a,b;
    int n;
    // cout << calcmod(-1,19);
    cin >> a >> b;
    cin >> n;
    n = (n-1)%6;
    if(n == 0){
        cout << calcmod(a,MOD);
    }
    if(n==1){
        cout << calcmod(b,MOD);
    }
    if(n==2){
        cout << calcmod(b-a,MOD);
    }
    if(n==3){
        cout << calcmod(-a,MOD);
    }
    if(n==4){
        cout << calcmod(-b,MOD);
    }
    if(n==5){
        cout << calcmod(a-b,MOD);
    }
}