#include <bits/stdc++.h>

using namespace std;
#define MAXN 200005
const bool DEBUG = true;
int ft[MAXN];
int n;

void add(int i,int val){
    for(; i < n+1; i|=i+1) ft[i]+=val;
}

int query(int i){
    int res = 0;
    for(; i > 0; i&=i-1) res+=ft[i-1];
    return res;
}
void solve(){
    cin >> n;
    vector<int> v(n,0);
    fill(ft,ft+n+2,0);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
   // sort(order.begin(),order.end(),[&](int x, int y){ return v[x] < v[y]})
   // vector<int> pos(n,0);//
   // for(int i = 0; i < n; i++){
   //     pos[order[i]] = i;
   // }
   // int matchNum = 1;
   // int req = 0;
    // vector<int> ans(n,0);
    int sum = 0;
    multiset<int> ms;
    for(int i = 0; i < n; i++){
        add(v[i],1);
        if(DEBUG) cout << "QUERY: " << query(v[i]+1) << " v[i]: " << v[i]<<endl;
        if(v[i]==22 && DEBUG){
            for(auto it = ms.begin(); it != ms.end(); ++it){
                cout << *it << " ";
            }
            cout << endl;
        }
        if(query(v[i]+1) > v[i]){
            if(DEBUG) cout << "IN HERE: \n";
            add(v[i],-1);
            cout << sum - ms.size()*(ms.size()+1)/2<<" ";
            continue;
        } 
        auto upb = ms.upper_bound(v[i]);
        //bad scenario n = 6, 4 4 4 4 1 2
        if(upb != ms.end() && query((*upb)+1) > (*upb)){
            if(DEBUG) cout << "next up: " << (*upb) << endl;
            add((*upb),-1);
            sum-=(*upb);
            ms.erase(upb);
        }
        sum+=v[i];
        ms.insert(v[i]);
        // cout << "SUM: " << sum << endl;
        cout << sum - ms.size()*(ms.size()+1)/2 << " ";
    } 
    cout << "\n";
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}