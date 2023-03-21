#include <bits/stdc++.h>
using namespace std;
#define MAXN 2005

const bool DEBUG = true;

vector<int> g[MAXN];
int n,m;

int main(){
    cin >> n >> m;
    vector<int> val;
    for(int i = 0; i < n; i++){
        int a;
        cin >> a;
        val.push_back(a);
    }
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        a--; b--;
        g[b].push_back(a);
    }
    vector<int> ans(n);
    for(int i = 0; i < n; i++){
        vector<int> degree(n,0);
        for(int j = 0;j < n; j++){
            for(auto to : g[j]) degree[to]++;
        }
        priority_queue<pair<int,int>> pq;
        for(int j = 0; j < n; j++){
            if(i != j && degree[j] == 0) pq.push({val[j],j});
        }
        for(int j = n; j > 0; j--){
            if(pq.empty() || pq.top().first < j){
                if(degree[i] == 0&&j <=val[i]){
                    ans[i] = j;
                }
                break;
            }
            int cur = pq.top().second;
            pq.pop();
            for(int to : g[cur]){
                degree[to]--;
                if(degree[to]==0 && to != i){
                    pq.push({val[to],to});
                }
            }
        }
    }
    for(int i : ans) cout << i << " ";
    cout << endl;
}
