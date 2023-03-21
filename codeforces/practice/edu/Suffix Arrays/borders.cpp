#include <bits/stdc++.h>

using namespace std;

void radixsort(vector<pair<pair<int, int>, int>> &a) {
  int n = a.size();
  vector<int> buckets(n, 0);
  for (int i = 0; i < n; i++) {
    buckets[a[i].first.first]++;
  }
  vector<int> strt(n, 0);
  for (int i = 1; i < n; i++) {
    strt[i] = strt[i - 1] + buckets[i - 1];
  }
  vector<pair<pair<int, int>, int>> na(n);
  for (int i = 0; i < n; i++) {
    na[strt[a[i].first.first]] = a[i];
    strt[a[i].first.first]++;
  }
  a = na;
}

void getSuffixArray(string s, vector < pair<pair<int, int>, int>> &sa) {
  int n = s.length();
  for (int i = 0; i < n; i++) {
    sa.push_back({{s[i], 0}, i});
  }
  sort(sa.begin(), sa.end());
  for (int k = 0; (1 << k) < n; k++) {
    vector<int> c(n);
    c[sa[0].second] = 0;
    for (int i = 1; i < n; i++) {
      c[sa[i].second] = c[sa[i-1].second];
      if (sa[i].first != sa[i - 1].first)
          c[sa[i].second]++;
    }
    for (int i = 0; i < n; i++) {
      int nextI = (sa[i].second- (1 << k) + n) % n;
      sa[i] = {{c[nextI], c[sa[i].second]}, nextI};
    }
    radixsort(sa);
  }
}

void getlcp(string &s, vector<int> &lcp,vector<pair<pair<int,int>,int>> &sa){
    int n = sa.size();
    lcp = vector<int>(n,0);
    vector<int> suff(n,0);
    for(int i = 0; i < n; i++){
        suff[sa[i].second] = i;
    }
    int k = 0;
    for(int i = 0; i < n-1; i++){
        int prevSuff = sa[suff[i]-1].second;
        //cout << "i: " << i << " prevsuff: " << prevSuff<<endl;
        while(i + k < n && prevSuff + k < n && s[i+k] == s[prevSuff+k]) k++;
        //cout << "suff i and k " << suff[i] << " " << k << endl;
        lcp[suff[i]] = k;
        k = max(0,k-1);
    }
}


int main() {
    string s;
    cin >> s;
    //s = "";
    //for(int i = 0; i < 400000; i++) s += "a";
    s += " ";
    vector<pair<pair<int,int>,int>> sa;
    getSuffixArray(s,sa);
    vector<int> lcp;
    getlcp(s,lcp,sa);
    //for(int i = 0; i < sa.size(); i++){
    //    cout << lcp[i] << " " << sa[i].second << " " << s.substr(sa[i].second) << endl;
    //}
    //cout << "done with lcp!"<<endl;
    vector<pair<int,int>> stck;
    int n = s.length();
    long long ans = (1ll*n-1ll)*(1ll*n)/2ll;
    lcp.push_back(0);
    for(int i = 0; i <= n; i++){
        int cnt = 0;
        //cout << "at i " << i << endl;
        while(!stck.empty() && stck.back().first > lcp[i]){
            int fir = stck.back().first;
            int diff = fir-lcp[i];
            int val = stck.back().second;
            stck.pop_back();
            if(!stck.empty()&&stck.back().first > lcp[i]){
                diff = fir-stck.back().first;
            }
            //cout << "stck first: " << fir<< " val: " << val << " ans: " << ans << " diff: " << diff << endl;
            cnt+=val;
            ans+= (1ll*diff*cnt*(cnt+1))/2;
        }
        if(!stck.empty() && stck.back().first == lcp[i]){
            int val = stck.back().second;
            stck.pop_back();
            stck.push_back({lcp[i],cnt+val+1});
        }
        else{
            stck.push_back({lcp[i],cnt+1});
        }
    }
    //int cnt = 0;
    ////cout << "at end: " << endl;
    //while(!stck.empty()){
    //    int fir = stck.back().first;
    //    int diff = fir;
    //    int val = stck.back().second;
    //    stck.pop_back();
    //    if(!stck.empty()){
    //        diff = fir-stck.back().first;
    //    }
    //    //cout << "stck first: " << fir<< " val: " << val << " ans: " << ans <<endl;
    //    cnt+=val;
    //    ans+=1ll*diff*((1ll*cnt)*(1ll*cnt+1ll)/2ll);
    //}
    cout << ans << endl;


}
