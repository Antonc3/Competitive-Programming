#include <bits/stdc++.h>

using namespace std; 
typedef long long ll; 
ll p, q, cnt = 0; 
string S; 
ll A[4]; 

bool check(ll A[]) 
{
    for (ll i = 0; i < 3; ++i) if (A[i] >= A[i+1]) return false; 
    return true; 
}

void fill(ll A[], ll p, ll q, string S, char c) 
{
    ll id1 = -1, id2 = -1; 
    for (ll i = 0; i < 4; ++i) {
        if (S[i] == c) {
            if (id1 == -1) id1 = i; 
            else id2 = i; 
        }
    }
    A[id1] = p; 
    A[id2] = q; 
}

int main() {
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cin >> p >> q >> S; 
    fill(A, p, q, S, 'A'); 
    ll sol = 0; 
    for (ll i = 1; i <= 9; ++i) 
    for (ll j = 1; j <= 9; ++j) {
        if (i == p || i == q || j == p || j == q || i == j) continue; 
        fill(A, i, j, S, 'B'); 
        sol += check(A); 
    }

    if (sol != 1) cout << -1; 
    else {
            for (ll i = 1; i <= 9; ++i) 
            for (ll j = 1; j <= 9; ++j) {
                if (i == p || i == q || j == p || j == q || i == j) continue; 
                    fill(A, i, j, S, 'B'); 
                if (check(A)) {cout << i << " " << j; return 0;}
            }
    } 
}