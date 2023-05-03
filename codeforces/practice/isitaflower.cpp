#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;

int dfs(int cur, vi &visited, vector<vi> &adj){
    visited[cur] = true;
    int cnt = 1;
    for(auto to : adj[cur]){
        if(visited[to]) continue;
        cnt+=dfs(to,visited,adj);
    }
    return cnt;
}

void solve(){
    int n,m;
    cin >> n >> m;
    vector<vi> adj(n+1);
    vi degree(n+1,0);
    rep(i,0,m){
        int a,b;
        cin >> a >> b;
        a--; b--;
        adj[a].pb(b);
        adj[b].pb(a);
        degree[a]++;
        degree[b]++;
    }
    int sqrtn = sqrt(n);
    if(sqrtn*sqrtn != n){
        cout << "NO\n";
        return;
    }
    if(m != n+sqrtn){
        cout << "NO\n";
        return;
    }
    int cnt2 = 0;
    int cnt4 = 0;
    int cnt4start = -1;
    rep(i,0,n){
        if(degree[i] == 2) cnt2++;
        else if(degree[i] == 4) cnt4++, cnt4start = i;
        else{
            cout << "NO\n";
            return;
        }
    }
    if(cnt2 != n-sqrtn && cnt4 != sqrtn){
        cout <<"NO\n";
        return;
    }
    vi visited(n+1,0);
    if(dfs(0,visited,adj) != n){
        cout <<"NO\n";
        return;
    }
    vector<vi> adj2(n+1);
    rep(i,0,n){
        while(degree[i] > 2){
            bool found = true;
            for(auto j = adj[i].begin(); j != adj[i].end(); j++){
                int to = *j;;
                if(degree[to] > 2){
                    found = false;
                    //remove
                    for(auto k = adj[to].begin(); k !=adj[to].end(); k++){
                        if((*k)==i) {
                            adj[to].erase(k);
                            break;
                        }
                    }
                    adj[i].erase(j);
                    degree[to]--;
                    degree[i]--;
                    adj2[i].pb(to);
                    adj2[to].pb(i);
                    break;
                }
            }
            if(found){
                cout <<"NO\n";
                return;
            }
        }
    }
    visited = vi(n+1,0);
    if(dfs(cnt4start,visited,adj2) != sqrtn){
        cout <<"NO\n";
        return;
    }
    visited = vi(n+1,0);
    int cnt = 0;
    rep(i,0,n){
        if(visited[i]) continue;
        cnt++;
        if(dfs(i,visited,adj) != sqrtn){
            cout <<"NO\n";
            return;
        }
    }
    if(cnt != sqrtn) {
        cout << "NO\n";
        return;
    }
    cout <<"YES\n";
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	cin >> t;
	while(t--){
		solve();
	}
}
