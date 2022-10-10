#include <bits/stdc++.h>

using namespace std;

int main(){
    int t;
    long long maxSize = 0;
    for(int i = 1; i < 50; i++){
        cout <<"? " <<  1 <<" " << i+1<<endl;
        long long a;
        cin >> a;
        if(a==-1){
            cout <<"! " << i << endl;
            return 0;
        }
        cout <<"? " << i+1 << " " << 1 << endl;
        long long b;
        cin >> b;
        if(a==b) maxSize = a+b;
        else{
            cout <<"! " <<  a+b << endl;
            return 0;
        }

    }
    cout << "! " << maxSize<<endl;
}
