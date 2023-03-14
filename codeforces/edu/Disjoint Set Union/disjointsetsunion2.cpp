#include <bits/stdc++.h>
using namespace std;
#define MAXN 300005

int dsu[MAXN];
int sz[MAXN];
int minimal[MAXN];
int maximal[MAXN];

int get(int a){
    return (dsu[a] == a) ? a : dsu[a] = get(dsu[a]);
}

void unite(int a, int b){
    a = get(a);
    b = get(b);
    if(a==b) return;
    if(sz[a] < sz[b]) swap(a,b);
    dsu[b] = a;
    minimal[a] = min(minimal[a],minimal[b]);
    maximal[a] = max(maximal[a],maximal[b]);
    sz[a]+=sz[b];
    //cout << "size: a: " << sz[a]<<endl;
    
}
int main(){
    iostream::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    for(int i = 0; i <= n; i++){
        dsu[i] = i;
        sz[i] = 1;
        minimal[i] = i;
        maximal[i] = i;
    }
    for(int i = 0; i < m; i++){
        string s;
        int a,b;
        cin >> s;
        if(s == "union"){
            cin >> a >> b;
            unite(a,b);
        }
        else{
            cin >>a;
            a = get(a);
            //cout << "a: " << a << endl;
            cout << minimal[a] << " " << maximal[a] << " " << sz[a] << endl; 
        }
    }
}
