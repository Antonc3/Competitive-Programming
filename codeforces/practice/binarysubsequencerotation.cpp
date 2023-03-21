#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    string c;
    int a0 = 0, a1 = 0;
    int b0 = 0, b1 = 0;
    for(int i = 0; i < n; i++){
        if(a[i]=='0') a0++;
        if(b[i]=='0') b0++;
    }
    if(a0 != b0){
        cout << -1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++){
        if(a[i] != b[i]) c+=a[i];
    }
    int ans = 0;
    int one = 0, zero = 0;
    for(int i = 0; i < c.length(); i++){
        if(c[i] == '0'){
            zero++;
            one = max(0,one-1);
            ans = max(zero,ans);
        }
        else{
            one++;
            zero = max(0,zero-1);
            ans = max(one,ans);
        }
    }
    cout << ans << endl;
}
