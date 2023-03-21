#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

int dsu[MAXN];
int sz[MAXN];

int get(int a){
    return (dsu[a] == a) ? a : dsu[a] = get(dsu[a]);
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(sz[a] < sz[b]) swap(a,b);
    sz[a]+=sz[b];
    dsu[b] = a;
}
int main(){
    int n,m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        dsu[i] = i;
        sz[i] = 1;
    }
    for(int i = 0; i < m; i++){
        string s;
        int a,b;
        cin >> s >> a >> b;
        if(s == "union"){
            unite(a,b);
        }
        else{
            cout << ((get(a)==get(b)) ? "YES" : "NO")<< "\n";
        }
    }
}
