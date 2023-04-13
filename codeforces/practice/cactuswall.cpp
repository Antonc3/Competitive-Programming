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

int dx[4] = {1,1,-1,-1};
int dy[4] = {1,-1,1,-1};
int bdx[4] = {1,0,-1,0};
int bdy[4] = {0,1,0,-1};
ll INF = 1e18;
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vi> grid(n,vi(m));
    rep(i,0,n){
        string s;
        cin >> s;
        rep(j,0,m){
            if(s[j] == '#') grid[i][j] = 0;
            else grid[i][j] = 1;
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            if(grid[i][j] == 0){
                rep(dir,0,4){
                    int ni = i+bdx[dir];
                    int nj = j+bdy[dir];
                    if(ni >= n || ni < 0 || nj >= m || nj < 0) continue;
                    grid[ni][nj] = -1;
                }
            }
        }
    }
    priority_queue<pair<ll,pii>> pq;
    vector<vector<pll>> dist(n,vector<pll>(m,{INF,INF}));
    rep(i,0,n){
        if(grid[i][0] == -1) continue;
        pq.push({-grid[i][0],{i,0}});
        dist[i][0] = {-1,-1};
    }
    while(!pq.empty()){
        auto cur = pq.top();
        pq.pop();
        int cury = cur.second.first;
        int curx = cur.second.second;
        if(curx==m-1){
            cout << "YES\n";
            while(cury != -1&& curx != -1){
                grid[cury][curx] = 0;
                auto tmp = dist[cury][curx];
                cury = tmp.first;
                curx = tmp.second;
            }
            rep(i,0,n){
                rep(j,0,m){
                    if(grid[i][j] == 0){
                        cout <<"#";
                    }
                    else cout << ".";
                }
                cout << "\n";
            }
            return;
        }
        rep(dir,0,4){
            int ny = cury+dy[dir];
            int nx = curx+dx[dir];
            if(ny >= n || ny < 0 || nx >= m || nx < 0) continue;
            if(grid[ny][nx] == -1) continue;
            if(dist[ny][nx].first != INF) continue;
            dist[ny][nx] = {cury,curx};
            pq.push({cur.first-grid[ny][nx],{ny,nx}});
        }
    }
    cout << "NO\n";
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
