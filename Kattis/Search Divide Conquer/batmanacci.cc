#include <bits/stdc++.h>
using namespace std;
          

int main(){
    long long n, k;
    cin >> n >> k;
    long long fib[100005];
    fib[0] = 0;// a
    fib[1] = 1;//n
    for(int i = 2; i < n+2; i++){
        fib[i] = fib[i-2]+fib[i-1];
        if(fib[i] > k){
            while(n>i+2) n-=2;
            break;
        }
    }
    while(n>2){
        // cout << "N: " << n<<endl;
        // cout << fib[n-2] << endl;
        if(k > fib[n-2]){
            k-=fib[n-2];
            n--;
        }
        else{
            n-=2;
        }
    }
    if(n==2) cout << 'A';
    else cout << 'N';
}