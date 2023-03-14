#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
#define F first
#define S second
typedef pair<int,int> pii;

bool DEBUG = false;
int n;
map<char,int> m1 {{'w',0},{'i',1},{'n',2}};
map<int,char> m2 {{0,'w'},{1,'i'},{2,'n'}};
vector<int> extras[3][3];//[has][needs]
bool need[MAXN];
void solve(){
    cin >> n;
    fill(need,need+n+1,true);
    int misplaced = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        vector<int> cnt(3,0);
        vector<int> missing {0,1,2};
        for(int j = 0; j < 3; j++){
            cnt[m1[s[j]]]++;
            need[m1[s[j]]] = false;
            for(int x = 0; x < missing.size();x++){
                if(missing[x]==m1[s[j]]){
                    missing.erase(missing.begin()+x);
                }
            }
        }
        for(int j = 0; j < 3; j++){
            while(cnt[j] > 1){
                extras[j][missing.back()].push_back(i);
                cnt[j]--;
                missing.pop_back();
                misplaced++;
            }
        }
    }
    if(DEBUG) cout << "DONE PROCESSING INPUT,  MISPLACED: " << misplaced<<endl;
    vector<pair<pii,pii>> moves;//i, val, j, val
    while(misplaced){
        int i = 0;
        bool found = false;
        while(!found){
            if(extras[i/3][i%3].size()){
                break;
            }
            i++;
        }
        int x = i%3, y = i/3;
        if(extras[x][y].size()){
            moves.push_back({{extras[y][x].back(),y},{extras[x][y].back(),x}});
            extras[y][x].pop_back();
            extras[x][y].pop_back();
            misplaced-=2;
            continue;
        }
        int other = 3-x-y;
        moves.push_back({{extras[y][x].back(),y},{extras[x][other].back(),x}});
        extras[y][x].pop_back();
        extras[y][other].push_back(extras[x][other].back());
        extras[x][other].pop_back();
        misplaced--;
    }
    cout << moves.size()<<"\n";
    for(auto i : moves){
        cout << i.F.F+1 << " " << m2[i.F.S] << " " << i.S.F+1 << " " << m2[i.S.S]<<"\n";
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    } 
}