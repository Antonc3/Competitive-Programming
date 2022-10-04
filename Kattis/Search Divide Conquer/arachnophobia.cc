#include <bits/stdc++.h>
using namespace std;
#define MAXN 100005

int n,m,t;
int start,fin;
int k;
vector<pair<int,int>> roads[MAXN];
long long spider[MAXN];

vector<int> dist;


//can we get there without going to any intersectiosn with a spider of mindist
bool djikstra(long long minDist){
    if(spider[start]<minDist || spider[fin] < minDist) return false;
    priority_queue<pair<int,int>> pq;
    dist.clear();
    dist.resize(n, -1);
    dist[start] = 0;
    pq.push({0,start});
    while(!pq.empty()){
        pair<int,int> cur = pq.top();
        pq.pop();
        if(dist[cur.second] != -1 && dist[cur.second] < -cur.first) continue;
        if(cur.second == fin) return true;
        for(auto edge : roads[cur.second]){
            //check if we can ues intersection
            if(spider[edge.first] < minDist)continue;
            //check if we are using too much time
            if(dist[cur.second] + edge.second > t) continue;
            //check if we are already visiting the edge with a better time
            if(dist[edge.first] > 0 && dist[edge.first] < dist[cur.second] + edge.second) continue;
            dist[edge.first] = dist[cur.second] + edge.second;
            pq.push({-(dist[cur.second] + edge.second), edge.first});
        }
    }
    return (dist[fin] != -1 && dist[fin]<=t);
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
    fill(spider, spider+n, 100000000000);
    // for(int i = 0; i < n; i++) cout<< spider[i] << " ";
    // cout << endl;
    priority_queue<pair<long long,int>> pq;

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

    long long l = 0, r = 100000000000;
    long long best = 0;
    while( l <= r){
        // cout << "l: " << l << " r: " << r<<endl;
        long long mid = (l+r)/2;
        bool good = djikstra(mid);
        // cout << "GOOD: " << good<<endl;
        if(good){
            l=mid+1;
            best = max(best,mid);
        }
        else{
            r = mid-1;
        }
    }
    // cout << "LR: " <<l << " " <<r << endl;
    cout << best<<endl;
}