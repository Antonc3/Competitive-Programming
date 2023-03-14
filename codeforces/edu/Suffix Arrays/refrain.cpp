#include <bits/stdc++.h>
using namespace std;
#define S second
#define F first
int n,m;
const bool DEBUG = false;
int main(){
    int nn;
    cin >> nn >> m;
    vector<int> arr(nn);
    for(int i = 0; i < nn; i++) cin >> arr[i];
    if(nn == 0) {
        cout << "0\n0\n\n";
        return 0;
    }
    arr.push_back(-1);
    int n = arr.size();
    //cout << arr.size() << endl;
    vector<pair<pair<int,int>,int>> suffixArr;
    for(int i = 0; i < n; i++) suffixArr.push_back({{arr[i],0},i});
    //cout << "suffixArr size: " << suffixArr.size() << endl;
    sort(suffixArr.begin(),suffixArr.end());
    for(int k = 0; (1<<k) < n; k++){
        //cout << "k: " << k << endl;
        vector<int> c(n);
        c[suffixArr[0].S] = 0;
        for(int i = 1; i < n; i++){
            c[suffixArr[i].S] = c[suffixArr[i-1].S];
            if(suffixArr[i].F != suffixArr[i-1].F) c[suffixArr[i].S]++;
        }
        for(int i = 0; i < n; i++){
            int lastI = (suffixArr[i].S+n-(1<<k))%n;
            suffixArr[i] = {{c[lastI],c[suffixArr[i].second]},lastI};
        }
        //radixsort
        //cout << "starting radix!\n";
        vector<int> buckets(n,0);
        for(int i = 0; i < n; i++){
            buckets[suffixArr[i].F.F]++;
        }
        vector<int> strt(n,0);
        for(int i = 1; i < n; i++){
            strt[i] = strt[i-1]+buckets[i-1];
        }
        vector<pair<pair<int,int>,int>> na(n);
        for(int i = 0; i < n; i++){
            na[strt[suffixArr[i].F.F]++]=suffixArr[i];
        }
        suffixArr = na;
    }
    vector<int> suffix(n,0);
    for(int i = 0; i < n; i++) suffix[suffixArr[i].S] = i;
    vector<int> lcp(n);
    int k = 0;
    for(int i = 0; i < n-1; i++){
        int pi = suffix[i];
        int prev = suffixArr[pi-1].second;
        while(arr[i+k]==arr[prev+k])k++;
        lcp[pi] = k;
        k = max(0,k-1);
    }
    if(DEBUG){
        for(int i = 0; i < suffixArr.size(); i++){
            cout << lcp[i] << " " << suffixArr[i].second << " "; 
            for(int j = suffixArr[i].second; j < n; j++) cout << arr[j] << " " ;
            cout << endl;
        }
        cout << "done with lcp!"<<endl;
    }
    stack<pair<long long,long long>> st;
    long long best = nn;
    long long besti = 0;
    long long bestlen = nn;
    lcp.push_back(-1);
    for(int i = 1; i < lcp.size(); i++){
        int cur = lcp[i];
        int earliest = i;
        while(!st.empty() && st.top().F > cur){
            auto p = st.top();
            st.pop();
            long long cnt = i-p.S+1;
            earliest = p.S;
            if(DEBUG) cout << "p: " << p.F << " p.S: " << p.S << " i: " << i << "\n";
            if(1ll*p.F*cnt >= best){
                best = 1ll*p.F *cnt;
                bestlen = p.F;
                besti = suffixArr[p.S].S;
            }
        }
        if(st.empty()||st.top().F < cur) st.push({cur,earliest});
    }
    cout << best << "\n";
    cout << bestlen << "\n";
    //cout << "besti: " << besti<<"\n";
    for(int i = besti; i < besti+bestlen; i++){
        cout << arr[i] << " ";
    }
    cout << "\n";
}
