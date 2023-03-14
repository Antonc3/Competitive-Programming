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

int main(){
    string s;
    cin >> s;
    s+="$";
    vector<pair<pair<int,int>,int>> a;
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
        cout << a[i].second << " ";
        suffix[a[i].second] = i;
    }
    cout << endl;

    int n = s.length();
    vector<int> lcp(n,0);
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
    for(int i = 1; i < n; i++){
        cout << lcp[i] << " ";
    }
    cout << "\n";
}

