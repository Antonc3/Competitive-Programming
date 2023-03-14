#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
const bool DEBUG = false;
struct rel{
    int to;
    char r;
};

vector<rel> adj[MAXN];
int n,m;
int arr[MAXN];
int check[MAXN][2]; //0 is unchecked 2 is good
bool visited[MAXN];
// val is either 0 or 1
bool dfs1(int cur, int val){
    if(DEBUG) cout << " cur: " << cur << " val: " << val << " arr[cur] " << arr[cur]<<endl;
    if(val == 1 && arr[cur] == 0){
        return false;
    } 
    if(val == 0 && arr[cur] == 1) {
        return false;
    }
    if(visited[cur]) return true;
    if(DEBUG) cout << "Passed initial check " << check[cur][val]<<endl;
    if(DEBUG) cout << " starting to search edges at: " << cur << " val: " << val <<endl;
    arr[cur] = val;
    visited[cur] = true;
    if(val==1){
        for(auto &ed : adj[cur]){
            // > < ! =
            if(ed.r == '<'){
                if(!dfs1(ed.to,0)){
                    return false;
                }
            }
            if(ed.r == '='){
                if(!dfs1(ed.to,0)){
                    return false;
                }
            }
            if(ed.r == '!'){
                if(!dfs1(ed.to,1)){
                    return false;
                }
            }
        }
    }
    if(val == 0){
        for(auto &ed : adj[cur]){
            if(ed.r == '>'){
                if(!dfs1(ed.to,1)){
                    return false;
                }
            }
            if(ed.r == '='){
                if(!dfs1(ed.to,1)){
                    return false;
                }
            }
            if(ed.r == '!'){
                if(!dfs1(ed.to,0)){
                    return false;
                }
            }
        } 
    }
    return true;
}
bool dfs(int cur, int val){
    if(DEBUG) cout << " cur: " << cur << " val: " << val << " arr[cur] " << arr[cur]<<endl;
    if(arr[cur] == val&&visited[cur]) return true;
    if(val == 1 && arr[cur] == 0){
        return false;
    } 
    if(val == 0 && arr[cur] == 1) {
        return false;
    }
    if(DEBUG) cout << "Passed initial check " << check[cur][val]<<endl;
    
    if(check[cur][val] != 0) return check[cur][val] == 2;
    if(DEBUG) cout << " starting to search edges at: " << cur << " val: " << val <<endl;
    bool changed = false;
    visited[cur]= true;
    if(arr[cur] == -1){
        changed = true;
        arr[cur] = val;
    }
    if(val==1){
        for(auto &ed : adj[cur]){
            // > < ! =
            if(ed.r == '>'){
                if(!dfs(ed.to,0) && !dfs(ed.to,1)){
                    visited[cur] = false;
                    if(changed) arr[cur] = -1;
                    return false;
                }
            }
            if(ed.r == '<'){
                if(!dfs(ed.to,0)){
                    visited[cur] = false;
                    if(changed) arr[cur] = -1;
                    return false;
                }
            }
            if(ed.r == '='){
                if(!dfs(ed.to,0)){
                    visited[cur] = false;
                    if(changed) arr[cur] = -1;
                    return false;
                }
            }
            if(ed.r == '!'){
                if(!dfs(ed.to,1)){
                    visited[cur] = false;
                    if(changed) arr[cur] = -1;
                    return false;
                }
            }
        }
    }
    if(val == 0){
        for(auto &ed : adj[cur]){
            if(ed.r == '>'){
                if(!dfs(ed.to,1)){
                    visited[cur] = false;
                    if(changed) arr[cur] = -1;
                    return false;
                }
            }
            if(ed.r == '<'){
                if(!dfs(ed.to, 0) && !dfs(ed.to,1)){
                    visited[cur] = false;
                    if(changed) arr[cur] = -1;
                    return false;
                }
            }
            if(ed.r == '='){
                if(!dfs(ed.to,1)){
                    visited[cur] = false;
                    if(changed) arr[cur] = -1;
                    return false;
                }
            }
            if(ed.r == '!'){
                if(!dfs(ed.to,0)){
                    visited[cur] = false;
                    if(changed) arr[cur] = -1;
                    return false;
                }
            }
        } 
    }
    if(changed){
        arr[cur] = -1;
    }
    visited[cur] = false;
    check[cur][val] = 2;
    return true;
}

struct inputData{
    int a,b;
    char r;
};
vector<inputData> checkAgain;


void solve(){
    cin >> n >> m;
    fill(arr, arr+MAXN, -1);
    bool bad = false;
    for(int i = 0; i< m; i++){
        int a,b,c;
        string s;
        cin >> a >> b >> s >> c;
        if(DEBUG) cout << "INPUT LINE: " << a << " " << b << " " << s << " " << c<<endl;
        if(s.length() == 2){
            if(s[0] == '>'){
                c--;
            }
            else if(s[0] == '<'){
                c++;
            }
            else if (s[0] == '!'){
                if(c==0){
                    s = ">";
                }
                else if(c==2){
                    s = "<";
                }   
            }
        }
        if(s[0] == '='){
            if(c==0){
                if(arr[a] == 1 || arr[b] == 1){
                    bad = true;
                }
                arr[a] = 0;
                arr[b] = 0;
            }
            else if(c==2){
                if(arr[a] == 0 || arr[b] == 0){
                    bad = true;
                }
                arr[a] = 1;
                arr[b] = 1;
            }
            else{
                checkAgain.push_back({a,b,s[0]});
                adj[a].push_back({b,'='});
                adj[b].push_back({a,'='});
            }
        }
        else if(s[0] == '>'){
            if(c >= 2){
                bad = true;
            }
            else if(c==1){
                if(arr[a] == 0 || arr[b] == 0){
                    bad = true;
                }
                arr[a] = arr[b] =1 ;
            }
            else if(c == 0){
                checkAgain.push_back({a,b,s[0]});
                adj[a].push_back({b,'>'});
                adj[b].push_back({a,'>'});
            }
        }
        else if(s[0] == '<'){
            if(c <= 0){
                bad = true;
            }
            else if(c==1){
                if(arr[a] == 1 || arr[b] == 1){
                    bad = true;
                }
                arr[a] = arr[b] = 0;
            }
            else if(c == 2){
                checkAgain.push_back({a,b,s[0]});
                adj[a].push_back({b,'<'});
                adj[b].push_back({a,'<'});
            }
        }
        else if(s[0] == '!'){
            if((arr[a]==1 && arr[b] == 0) || (arr[a] == 0 && arr[b] == 1)){
                bad = true;
            }
            else if(arr[a] == 1||arr[b] ==1){
                arr[a]=1;
                arr[b] = 1;
            }
            else if(arr[a] == 0 || arr[b] == 0){
                arr[a] = 0;
                arr[b] = 0;
            }
            else{
                checkAgain.push_back({a,b,s[0]});
                adj[a].push_back({b,'!'});
                adj[b].push_back({a,'!'});
            }
        }
    }
    for(auto i : checkAgain){
        if(i.r == '='){
            if((arr[i.a] == 1 && arr[i.b] == 1 )|| (arr[i.a] == 0 && arr[i.b] == 0)){
                bad = true;
                break;
            }
        }
        if(i.r == '>'){
            if(arr[i.a] == 0 && arr[i.b] == 0){
                bad = true;
                break;
            }
        }
        if(i.r == '<'){
            if(arr[i.a] == 1 && arr[i.b] == 1){
                bad = true;
                break;
            }
        }
        if(i.r == '!'){
            if((arr[i.a] == 1 && arr[i.b] == 0) || (arr[i.a] == 0 && arr[i.b] == 1)){
                bad = true;
                break;
            }
        }
    }
    if(DEBUG) cout << "Done Processing Input\n";
    if(bad){
        cout << "No\n";
        return;
    }
    if(DEBUG){
        for(int i = 0; i < n; i++){
            cout << arr[i] << " ";
        }
    }
    if(DEBUG) cout << "\n DFSING!\n";
    fill(&check[0][0],&check[0][0]+sizeof(check)/sizeof(check[0][0]),0);
    fill(visited, visited+MAXN, false);
    for(int i = 0; i < n; i++){
        if(arr[i] != -1){
            if(!dfs1(i,arr[i])){
                cout << "No\n";
                return;
            }
        }
    }

    for(auto i : checkAgain){
        if(i.r == '='){
            if((arr[i.a] == 1 && arr[i.b] == 1 )|| (arr[i.a] == 0 && arr[i.b] == 0)){
                bad = true;
                break;
            }
        }
        if(i.r == '>'){
            if(arr[i.a] == 0 && arr[i.b] == 0){
                bad = true;
                break;
            }
        }
        if(i.r == '<'){
            if(arr[i.a] == 1 && arr[i.b] == 1){
                bad = true;
                break;
            }
        }
        if(i.r == '!'){
            if((arr[i.a] == 1 && arr[i.b] == 0) || (arr[i.a] == 0 && arr[i.b] == 1)){
                bad = true;
                break;
            }
        }
    }
    if(bad){
        cout << "No\n";
        return;
    }
    fill(visited, visited+MAXN, false);

    stack<pair<int,int>> q;
    for(int i = 0; i < n; i++){
        if(DEBUG) cout << "STARTING SEARCH AT: " << i<<endl;
        bool res1 = dfs(i,0);
        bool res2 = dfs(i,1);
        if(!res1){
            check[i][0] = 1;
        }
        if(!res2){
            check[i][1] = 1;
        }
        if(!res1 && !res2){
            cout << "No\n";
            return;
        } 
    }
    cout << "Yes\n"; 
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    solve();
}