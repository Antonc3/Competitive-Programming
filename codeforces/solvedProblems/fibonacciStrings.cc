//SHOULD HAVE WROTE A GREEDY SOLUTION LOL
//it worked tho so who is laughing now

#include <bits/stdc++.h>

using namespace std;
#define MAXK 105
#define MAXC 1000000000
#define f first
#define s second
typedef pair<int,int> pii;
int k;
set<pii> st;
long long fib[MAXK];

bool dfs(int f, int lastI){
    // cout << "F: " << f << ", lastI " << lastI << endl;
    if(f==-1) return true;
    long long cur = fib[f];
    // cout << "CUR: " << cur << endl;
    // vector<int> used;
    bool possible = false;
    for(auto found = st.lower_bound({cur,0}); found != st.end();){
        // cout << (*fou/nd).second << endl;
        pii tmp = (*found);
        if(tmp.s == lastI) {
            found++;
            continue;
        }
        st.erase(found);
        st.insert({tmp.f-cur,tmp.s});
        possible = possible || dfs(f-1,tmp.s);
        if(possible) return true;
        st.erase({tmp.f-cur,tmp.s});
        st.insert(tmp);
        found = st.find(tmp);
        found++;
    }
    return possible;
}

void solve(){
    st.clear();
    cin >> k;
    long long total = 0;
    int f = 0;
    long long fSum = 0;
    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        st.insert({a,i});
        total+=a;
        while(f < 46 && total > fSum){
            fSum+=fib[f++];
        }
    }
    if(fSum != total || f>=46){
        cout << "NO\n";
        return;
    }
    if(dfs(f-1,-1)) cout << "YES\n";
    else cout << "NO\n";
}
int main(){
    fib[0] = fib[1] = 1;
    for(int i = 2; i < 55; i++){
        fib[i] = fib[i-1]+fib[i-2];
    }
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}