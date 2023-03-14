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
    int n = s.size();
    vector<pair<pair<int,int>,int>> a;
    for(int i = 0; i < n; i++){
        a.push_back({{s[i],0},i});
    }
    sort(a.begin(),a.end());
    for(int k = 0; 1 << k < n; k++){
        vector<int> c(s.size()); 
        c[a[0].second] = 0; 
        for(int i = 1; i < n; i++){
            c[a[i].second] = c[a[i-1].second];
            if(a[i].first != a[i-1].first){
                c[a[i].second]++;
            }
        }
        for(int i = 0; i < n; i++){
            int nextI = (a[i].second+s.size()-(1<<k))%(s.size());
            a[i] = {{c[nextI],c[a[i].second]},nextI};
        }
        radixSort(a);
    }
    vector<int> sorted(n);
    for(int i = 0; i < n; i++){
        sorted[i] = a[i].second;
    }
    int q;
    cin >> q;
    s +=s;
    while(q--){
        string pat;
        cin >> pat;
        if(pat.size() > n){
            cout << "No\n";
            continue;
        }
        int l = 0, r = n-1; 

        int res =-1;
        int count = 0;
        while( l <= r){
            int mid = (l+r)/2;
            // cout << s.substr(sorted[mid],pat.size()) << " " << pat << endl;
            // cout << l << " " << r << endl;
            res =s.compare(sorted[mid],pat.size(),pat);
            if(res == 0){
                cout << "Yes\n";
                break;
            }
            else if(res > 0){
                r = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        if(res != 0){
            cout << "No\n";
        }
    }

}