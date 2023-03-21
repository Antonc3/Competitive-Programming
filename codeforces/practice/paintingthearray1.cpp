#include <bits/stdc++.h>
using namespace std;


int main(){
    int n;
    cin >> n;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++) cin >> a[i];
    a[0] = -1;
    vector<int> nxt(n);
    vector<int> pos(n+1,n+1);
    for(int i = n; i >= 0; i--){
        nxt[i] = pos[a[i]];
        pos[a[i]] = i;
    }
    int x = 0;
    int y = 0;
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        if(a[x]==a[i]){
            cnt+=(a[y]!=a[i]);
            y = i;
        }
        else if(a[y] == a[i]){
            cnt+=(a[x]!=a[i]);
            x = i;
        }
        else if(nxt[x] < nxt[y]){
            cnt+=a[x]!=a[i];
            x = i;
        }
        else{
            cnt+=a[y]!=a[i];
            y = i;
        }
    }
    cout << cnt << endl;
}
