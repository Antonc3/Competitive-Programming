#include <bits/stdc++.h>
using namespace std;

int main(){
    double c;
    cin >> c;
    double l = 0.0, r = 1e10;
    double best =  l;
    for(int i = 0; i < 200; i++){
        double mid = (l+r)/2;
        if(mid*mid + sqrt(mid) > c){
            r = mid;
        }
        else{
            l = mid;
            best = mid;
        }
    }
    cout << setprecision(10) << best << endl;
}
