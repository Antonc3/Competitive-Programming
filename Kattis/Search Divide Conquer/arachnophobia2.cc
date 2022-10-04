#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

int n,m,t;
int start,fin;
int k;
vector<pair<int,int>> roads[MAXN];
long long spider[MAXN];
bool visited[MAXN];
long long bestPath = 0;

vector<int> dist;


//can we get there without going to any intersectiosn with a spider of mindist
// bool djikstra(long long minDist){
//     priority_queue<pair<int,int>> pq;
//     dist.clear();
//     dist.resize(n, -1);
//     dist[start] = 0;
//     pq.push({0,start});
//     while(!pq.empty()){
//         pair<int,int> cur = pq.top();
//         pq.pop();
//         if(dist[cur.second] != -1 && -cur.first > dist[cur.second]) continue;
//         if(cur.second == fin) return true;
//         for(auto edge : roads[cur.second]){
//             if(spider[edge.first] < minDist)continue;
//             if(-cur.first + edge.second > t) continue;
//             if(dist[edge.first] > 0 && dist[edge.first] < -cur.first + edge.second) continue;
//             dist[edge.first] = (-cur.first) + edge.second;
//             pq.push({-(-cur.first + edge.second), edge.first});
//         }
//     }
//     return false;
// }

long long dfs(int node, int dist,long long spiderDist){
    cout << "CUR NODE: " << node<< " DIST: " << dist << " spider " << spiderDist<<endl;
    if(dist > t) return INT_MAX-1; 
    if(node == fin) return spiderDist;

    long  long msd = 0;
    for(auto i : roads[node]){
        if(visited[i.first]) continue;
        if(min(spiderDist, spider[i.first]) < bestPath) continue;
        visited[i.first] = true;
        msd = max(msd, dfs(i.first , i.second+dist, min(spiderDist, spider[i.first])));
        bestPath = max(bestPath, dfs(i.first , i.second+dist, min(spiderDist, spider[i.first])));

        visited[i.first] = false;
    }
    return msd;
}

int main(){
    cin >> n >> m >> t;
    for(int i = 0; i < m; i++){
        int a,b,d;
        cin >> a >> b >> d;
        roads[a].push_back({b,d});
        roads[b].push_back({a,d});
    }
    cin >> start >> fin;
    cin >> k;
    fill(spider, spider+n, INT_MAX-1);
    // for(int i = 0; i < n; i++) cout<< spider[i] << " ";
    // cout << endl;
    priority_queue<pair<int,int>> pq;

    for(int i = 0; i < k; i++){
        int a;
        cin >> a;
        spider[a] = 0;
        pq.push({0,a});
    }
    while(!pq.empty()){
        pair<int,int> cur = pq.top();
        // cout << "setting spider dist: " << cur.first << " " << cur.second << endl;
        pq.pop();
        if(spider[cur.second] < -cur.first) continue;
        for(auto edge : roads[cur.second]){
            // cout << "EDGE DIST: " <<edge.second<<endl;
            if(spider[cur.second] + edge.second < spider[edge.first]){
                pq.push({-(spider[cur.second]+edge.second),edge.first});
                spider[edge.first] = spider[cur.second]+edge.second;
            }
        }
    }
    // for(int i =0 ; i < n; i++){
    //     cout << spider[i] << " ";
    // }
    // cout << endl;
    fill(visited, visited+n, false);
    
    cout << dfs(start, 0, spider[start]);
    // long long l = 0, r = 100000000000;
    // long long best = 0;
    // while( l < r){
    //     // cout << "l: " << l << " r: " << r<<endl;
    //     long long mid = (l+r)/2;
    //     bool good = djikstra(mid);
    //     // cout << "GOOD: " << good<<endl;
    //     if(good){
    //         l=mid+1;
    //         best = mid;
    //     }
    //     else{
    //         r = mid-1;
    //     }
    // }
    // cout << best<<endl;
}