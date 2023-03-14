#include <bits/stdc++.h>
#include <climits>
using namespace std;

vector<int> log2s;

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

int query(vector<int> log2s,vector<vector<int>> &sparse, int l, int r){
    int p = log2s[r-l+1];
    int left = sparse[p][l];
    int right = sparse[p][r-(1<<p)+1];
    return min(left,right);
}

int main(){
    string s;

    cin >> s;
    s+=" ";
    int tableheight = log2(s.length())+1;
    vector<pair<pair<int,int>,int>> a;
    for(int i = 0; i < s.size(); i++){
        a.push_back({{s[i],0},i});
    }
    sort(a.begin(),a.end());
    vector<vector<int>> c = vector<vector<int>>(tableheight,vector<int>(s.length()));
    for(int k = 0; 1 << k < s.size(); k++){
        c[k][a[0].second] = 0; 
        for(int i = 1; i < s.size(); i++){
            c[k][a[i].second] = c[k][a[i-1].second];
            if(a[i].first != a[i-1].first){
                c[k][a[i].second]++;
            }
        }
        for(int i = 0; i < s.size(); i++){
            int nextI = (a[i].second+s.size()-(1<<k))%(s.size());
            a[i] = {{c[k][nextI],c[k][a[i].second]},nextI};
        }
        radixSort(a);
    }
    vector<int> suffix(s.length(),0);
    for(int i =0; i < s.size(); i++){
        suffix[a[i].second] = i;
    }

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
    int m;
    cin >> m;
    vector<pair<int,int>> subs;
    for(int i = 0; i < m; i++){
        int a,b;
        cin >> a >> b;
        subs.push_back({a,b});
    }
    //for(int i = 0; i < a.size(); i++){
    //    cout << lcp[i] << " " << a[i].second << " " << s.substr(a[i].second)<<endl;
    //}
    //cout << endl;

    int tableHeight = log2(n)+2;
    vector<vector<int>> sparseTable = vector<vector<int>>(tableHeight,vector<int>(n-1));
    log2s = vector<int>(n+1,0);
    for(int i = 2; i <= n; i++){
        log2s[i] = log2s[i/2]+1;
    }
    for(int i = 0; i < n-1; i++){
        sparseTable[0][i] = lcp[i+1];
    }
    for(int r = 1; r < tableHeight; r++){
        for(int i = 0; i + (1 << r) < n; i++){
            sparseTable[r][i] = min(sparseTable[r-1][i],sparseTable[r-1][i+(1<<(r-1))]);
        }
    }

    //for(int r = 0; r < tableHeight; r++){
    //    for(int i = 0; i + (1 << r) < n; i++){
    //        cout << sparseTable[r][i] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << endl;
    sort(subs.begin(),subs.end(),[&](pair<int,int> a, pair<int,int> b) {
            if(a.first == b.first) return a.second < b.second;
            
            int alen = a.second-a.first+1;
            int blen = b.second-b.first+1;
            //int asuf = suffix[a.first-1];
            //int bsuf = suffix[b.first-1];
            int len = min(blen,alen);
            int k = log2s[len];
            pair<int, int> aa = {c[k][a.first-1], c[k][(a.first-1+len-(1 << k))%n]};
            pair<int, int> bb = {c[k][b.first-1], c[k][(b.first-1+len-(1 << k))%n]};
            if(aa==bb){
            //cout << a.first << " "<< a.second << " b: " << b.first << " " << b.second << endl;
                if(alen==blen) return a.first < b.first;
                return alen < blen;
            }
            else if(aa < bb) return true;
            else return false;
            //return a == b ? 0 : a < b ? -1 : 1;
            ////cout << "asuf: " << asuf << " bsuf: " << bsuf << endl;
            ////cout << a.first << " " << a.second << " and " << b.first << " " << b.second<<endl;
            //int numprefixsame = (asuf < bsuf) ? query(log2s,sparseTable,asuf,bsuf-1) : query(log2s,sparseTable,bsuf,asuf-1);
            ////numprefixsame = 0;
            ////while(numprefixsame+a.first <= a.second && numprefixsame + b.first <= b.second && s[numprefixsame+a.first] == s[numprefixsame+b.first]) numprefixsame++;
            //if(alen <= numprefixsame  && blen <= numprefixsame) return a.first < b.first; 
            //else if(alen <= numprefixsame) return true;
            //else if(blen <= numprefixsame) return false;
            //else return asuf < bsuf; 
        });
    for(auto i : subs){
        cout << i.first << " " << i.second <<endl;
    }
    
}

