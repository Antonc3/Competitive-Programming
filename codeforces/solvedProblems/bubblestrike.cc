#include <bits/stdc++.h>

using namespace std;

int n;
double p;

bool check(int test){
    double p1 = (double) (3*(test*(n-test)*(n-test-1)))/ ((double) n) / ((double) n -2.0) /((double) n -1.0);
    double p2 = (double) (3*(test*(test-1)*(n-test)))/ ((double) n) / ((double) n -2.0) /((double) n -1.0);
    double p3 = (double) ((test*(test-1)*(test-2)))/ ((double) n) / ((double) n -2.0) /((double) n -1.0);
    // cout << p1 << " "<< p2 << " "<<p3<<endl;
    double a = p1*0.5+p2+p3;
    // cout << " test " << test << " a " << a << endl
    return (a >= p);
}


int main(){

    cin >> n >> p;
    if(p == 1.0){
        cout << n-1<<endl;
        return 0;
    }
    for(int i =0; i <= n; i++){
        if(check(i)){
            cout << i << endl;
            break;
        }
    }
}
