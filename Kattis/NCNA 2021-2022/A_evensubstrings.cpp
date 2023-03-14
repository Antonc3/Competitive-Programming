#include <bits/stdc++.h>

using namespace std; 
typedef long long ll; 
string S; 
int n, q; 

struct node {
    int val;
    ll c[64]; 
} ST[800005];

node BASE; 

void merge(node &cur, node L, node R, ll valLeft) 
{
    cur.val = L.val ^ R.val; 
    for (int i = 0; i < 64; ++i) {
        cur.c[i] = 0;
    }
    for (int i = 0; i < 64; ++i) {
        cur.c[i] += L.c[i]; 
        cur.c[valLeft ^ i] += R.c[i]; 
    }
}

void build(int id, int L, int R) 
{
    if (L == R) 
    {
        for (int i = 0; i < 64; ++i) ST[id].c[i] = 0; 
        ST[id].c[(1LL << ((S[L] - 'a')))] = 1; 
        ST[id].val = (1LL << (S[L] - 'a'));
        return; 
    }
    int mid = (L+R) >> 1; 
    build(id << 1, L, mid); 
    build(id << 1 | 1, mid + 1, R); 
    merge(ST[id], ST[id << 1], ST[id << 1 | 1], ST[id << 1].val); 
}

void upd(int id, int L, int R, int d, char x) 
{
    if (L == R) 
    {
        ST[id].c[(1LL << ((S[L] - 'a')))] = 0; 
        S[L] = x; 
        ST[id].c[(1LL << ((S[L] - 'a')))] = 1; 
        ST[id].val = (1LL << ((S[L] - 'a'))) ;
        return; 
    }
    int mid = (L+R) >> 1; 
    if (d <= mid) upd(id << 1, L, mid, d, x); 
    else upd(id << 1 | 1, mid + 1, R, d, x); 
    merge(ST[id], ST[id << 1], ST[id << 1 | 1], ST[id << 1].val); 
}

node get(int id, int L, int R, int u, int v) {
    if (v < L || R < u) return BASE; 
    if (u <= L && R <= v) return ST[id]; 
    int mid = (L+R) >> 1; 
    node toReturn; 
    node toLeft =  get(id << 1, L, mid, u, v);
    node toRight = get(id << 1 | 1, mid + 1, R, u, v);
    merge(toReturn, toLeft, toRight, toLeft.val); 
    return toReturn; 
}

void xuly() 
{
    build(1, 1, n); 
    cin >> q; 
    while (q--) {
        int c, x, y; 
        char a; 
        cin >> c; 
        if (c == 1) {
            cin >> x >> y; 
            node C = get(1, 1, n, x, y); 
            ll res = C.c[0]; 
            for (int i = 0; i < 64; ++i) res += (C.c[i] - 1) * C.c[i] / 2; 
            cout << res << '\n'; 
        }
        else if (c == 2) {
            cin >> x >> a; 
            upd(1, 1, n, x, a); 
        }
    }
}

void nhap() 
{
    cin >> S; 
    n = S.size(); 
    S = ' ' + S; 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    nhap(); 
    xuly(); 
}