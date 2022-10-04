#include <bits/stdc++.h>
using namespace std;
#define MAXN 505
#define MAXC 10005
#define f first
#define s second
typedef pair<int,int> pii;
typedef pair<int,pair<int,int>> piii;
int n,c;
//storage size, download size, index
vector<piii> apps;

struct Customcomp {
    bool operator() (piii const& a, piii const& b) const {
        if(a.f==b.f) return a.s.f > b.s.f;
        return a.f < b.f;
    }
};

int main(){
    cin >> n >> c;
    for(int i =1; i <= n; i++){
        int a,b;
        cin >> a >> b;
        apps.push_back({b,{a,i}});
    }
    sort(apps.begin(),apps.end());

    //download size, storage size, index
    set<piii,Customcomp> s;
    int usedDiskSpace = 0;
    for(int i = 0; i < n; i++){
        // cout << "USEDDISKSPACE: " << usedDiskSpace<<endl;
        piii cur = apps[i];
        // cout <<"LOOKING AT: " << cur.s.s<<" STORAGE: " << cur.f << " DOWNLOAD: " << cur.s.f<<endl;
        if(usedDiskSpace+cur.f > c)continue;
        // auto lb = s.lower_bound({cur.s,{0,0}});
        int spaceUsed = 0;
        s.insert({cur.s.f,{cur.f,cur.s.s}});
        auto it = s.find({cur.s.f,{cur.f,cur.s.s}});
        usedDiskSpace+=cur.f;
        // cout <<"INSERTING s.size: "<< s.size()<< endl;
        for(auto j = s.rbegin(); j != s.rend(); j++){
            piii a = (*j);
            // cout << "SPACEUSED: " << spaceUsed<<endl;
            // cout << "A: " << a.s.s << " STORAGE: " << a.s.f << " DOWNLOAD: " << a.f<<endl;
            if(spaceUsed+max(a.f,a.s.f) > c){
                s.erase(it);
                usedDiskSpace-=cur.f;
                // cout << "erased: " << cur.s.s<<endl;
                break;
            }
            spaceUsed+=a.s.f;
        }
    }
    cout << s.size()<<endl;
    for(auto i = s.rbegin(); i != s.rend(); i++){
        cout << (*i).s.s<< " ";
    }
    cout << endl;
}