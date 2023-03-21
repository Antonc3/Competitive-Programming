#include <bits/stdc++.h>
#include <climits>
#include <cmath>
using namespace std;
typedef long long ll;
vector<int> clothes[4];
vector<int> len(4);
int best;
vector<int> bestclothes(4,0);
const bool DEBUG = false;

void check(int cur){
    if(DEBUG)cout << "checking cur: " << cur<< endl;
    vector<int> ind(4,0);
    for(int curi = 0; curi < len[cur]; curi++){
        ind[cur] = curi;
        int curmax = 0;
        for(int i = 0; i < 4; i++){
            if(i==cur) continue;
            while(ind[i] < len[i] && clothes[i][ind[i]] < clothes[cur][curi]){
                ind[i]++;
            }
            if(ind[i] == len[i]) return;
            curmax = max(curmax,abs(clothes[i][ind[i]]-clothes[cur][curi]));
        }
        if(DEBUG) cout << "curmnax: " << curmax<< " best: " << best<<endl;
        if(DEBUG) for(int i : ind) cout << i << " ";
        if(DEBUG) cout << endl;
        if(curmax < best){
            if(DEBUG) cout << "FOUND BEST!\n";
            for(int i = 0; i < 4; i++){
                bestclothes[i] = clothes[i][ind[i]];
            }
            best = curmax;
        }

    }
}

int main(){
    int n;
    ll s;
    for(int i = 0; i < 4; i++){
        int n;
        cin >> n;
        len[i] = n;
        clothes[i] = vector<int>(n);
        for(auto &x : clothes[i]) cin >> x;
        sort(clothes[i].begin(),clothes[i].end());
    }
    best = INT_MAX;
    for(int i = 0; i < 4; i++){
        check(i);
    }
    for(int i = 0; i < 4; i++){
        cout <<bestclothes[i]<<" ";
    }
    cout << endl;
}
