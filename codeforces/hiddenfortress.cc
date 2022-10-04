#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000000000

long long arr[4];
int main(){
    cout << "? 1 1 \n"; 
    cin >> arr[0];
    cout << "? " << MAXN << " 1\n";
    cin >> arr[1];
    long long midpt = 1+(arr[0]-arr[1]+MAXN)/2;
    cout << "? " << midpt << " 1 \n";
    cin >> arr[2];
    cout << "?  " << midpt << " " << MAXN <<" \n";
    cin >> arr[3];

    long long a,b,c,d;
    d = MAXN-arr[3];
    b = 1+arr[2];
    a = 1+arr[0]-arr[2];
    c = arr[2]-arr[1]+MAXN;
    cout << "! " << a << " " << b << " " << c << " " << d;
}