#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vector<int> times(n);
    for(auto &x : times) cin >> x;
    vector<int> degreeIn(n,0);
    vector<int> degreeOut(n,0);
    vector<vector<int>> g(n);
    for(int i =0; i < m; i++){
        int a,b;
        cin >> a >> b;
        --a; --b;
        degreeOut[a]++;
        degreeIn[b]++;
        g[a].push_back(b);
    }
    //
    vector<pair<ll,int>> A(n);
    queue<int> q;
    for(int i = 0; i < n; i++){
        A[i] = {0, i};
        if(degreeIn[i]==0){
            A[i] = {0,i};
            q.push(i);
        }
    }
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        int curTime = times[cur];
        for(auto i : g[cur]){
            int nxtTime = times[i];
            int toAdd = nxtTime-curTime;
            //cout << " nxttime: " << nxtTime << " curtime: " << curTime << endl;
            if(nxtTime < curTime){
                toAdd = k+toAdd;
            }
            ll nt = A[cur].first+toAdd;
            //cout << "cur: " << cur << " i: " << i << " toAdd: " << toAdd << " nt: " << nt << endl;
            if(nt > A[i].first){
                A[i] = {nt,A[cur].second};
            }
            degreeIn[i]--;
            if(degreeIn[i]==0){
                q.push(i);
            }
        }
    }
    multiset<ll> ms;
    multiset<pair<ll,ll>> msstart;
    for(int i = 0; i < n; i++){
        if(degreeOut[i] == 0){
            //cout << "timestart: " << times[A[i].second] << " timeend: " << times[A[i].second]+A[i].first<<endl;
            msstart.insert({times[A[i].second],times[A[i].second]+A[i].first});
            ms.insert(times[A[i].second]+A[i].first);
        }
    }

    ll best = 1ll*k*n;
    while(msstart.size()){
        pair<ll,ll> f = *msstart.begin();
        ll e = *ms.rbegin();
        best = min(best,e-f.first);
        ms.erase(ms.lower_bound(f.second));
        ms.insert(f.second+k);
        msstart.erase(msstart.begin());
    }
    cout << best << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}