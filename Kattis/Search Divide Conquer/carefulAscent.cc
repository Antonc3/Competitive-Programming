#include <bits/stdc++.h>

using namespace std;


long long x,y,n;
long long ly[105];
long long uy[105];
double mult[105];

int main(){
    cin >> x >> y >> n;
    long long inShield = 0;
    double total = 0;
    for(int i = 0; i < n; i++){
        cin >> ly[i] >> uy[i] >> mult[i];
        inShield += uy[i]-ly[i];
        total += (uy[i]-ly[i])*mult[i];
    }
    total+=(y-inShield);
    double ans = (double) x/total;
    cout << setprecision(10) <<ans;
}