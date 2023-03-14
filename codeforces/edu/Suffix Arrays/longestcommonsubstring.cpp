#include <bits/stdc++.h>
using namespace std;

void radixSort(vector<pair<pair<int,int>,int>> &a){
    int n = a.size();
    vector<int> buckets(n,0);
    for(int i = 0;i < n; i++){
        buckets[a[i].first.first]++;
    }
    vector<int> start(n,0);
    start[0] = 0;
    for(int i = 1; i < n; i++){
        start[i] = start[i-1] + buckets[i-1];
    }
    vector<pair<pair<int,int>,int>> na(n);
    for(int i = 0; i < n; i++){
        na[start[a[i].first.first]] = a[i];
        start[a[i].first.first]++;
    }
    a = na;
}
void getLCPandSuffixArray(string &s, vector<pair<pair<int,int>,int>> &a, vector<int> &lcp){
    for(int i = 0; i < s.size(); i++){
        a.push_back({{s[i],0},i});
    }
    sort(a.begin(),a.end());
    for(int k = 0; 1 << k < s.size(); k++){
        vector<int> c(s.size()); 
        c[a[0].second] = 0; 
        for(int i = 1; i < s.size(); i++){
            c[a[i].second] = c[a[i-1].second];
            if(a[i].first != a[i-1].first){
                c[a[i].second]++;
            }
        }
        for(int i = 0; i < s.size(); i++){
            int nextI = (a[i].second+s.size()-(1<<k))%(s.size());
            a[i] = {{c[nextI],c[a[i].second]},nextI};
        }
        radixSort(a);
    }
    vector<int> suffix(s.length(),0);
    for(int i =0; i < s.size(); i++){
        suffix[a[i].second] = i;
    }

    int n = s.length();
    int curK = 0;
    for(int i = 0; i < n-1; i++){
        int prevSuffix = a[suffix[i]-1].second;
        for(curK; curK < min(n-prevSuffix, n-i); curK++){
            if(s[i+curK]!=s[prevSuffix+curK]){
                break;
            }
        }
        lcp[suffix[i]] = curK;
        curK = max(0,curK-1);
    }
   // for(int i = 0; i < a.size(); i++){
   //     cout << lcp[i] << " " << a[i].second << " " << s.substr(a[i].second)<<endl;
   // }
}
int main(){
    string s,t;
    cin >> s >> t;
    s+="#"+t+"$";
    vector<pair<pair<int,int>,int>> arr;
    vector<int> lcp(s.length());
    getLCPandSuffixArray(s, arr, lcp);
    int n = arr.size();
    int ans = 0;
    int curlcp = 0;
    for(int i = 0; i < arr.size()-1; i++){
        int cur = arr[i].second;
        int nxt = arr[i+1].second;
        if((cur < n-t.length()-1 && nxt >= n-t.length()-1) || (cur >= n-t.length()-1 && nxt < n-t.length()-1)){
            if(curlcp < lcp[i+1] ){
                curlcp = lcp[i+1];
                ans = nxt;
            }
        }
    }
    cout << s.substr(ans,curlcp) <<endl;
}

