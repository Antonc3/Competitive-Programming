#include <bits/stdc++.h>
using namespace std;
#define MAXN 200005

int dsu[MAXN];
int sz[MAXN];
int xp[MAXN];

int get(int a){
    return (dsu[a] == a) ? a : get(dsu[a]);
}
int getxp(int a){
    return xp[a] + ((dsu[a] == a) ? 0 : getxp(dsu[a]));
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a==b) return;
    if(sz[a] < sz[b]) swap(a,b);
    sz[a]+=sz[b];
    xp[b]-=xp[a];
    dsu[b] = a;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        dsu[i] = i;
        xp[i] = 0;
        sz[i] = 1;
    }
    for(int i = 0; i < m; i++){
        string s;
        int a,b;
        cin >> s; 
        if(s == "join"){
            cin >> a >> b;
            unite(a,b);
        }
        else if(s =="add"){
            cin >> a >> b;
            xp[get(a)]+=b;
        }
        else{
            cin >> a;
            cout << getxp(a) << endl;
        }
    }
}
