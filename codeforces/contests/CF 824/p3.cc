#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> forward(26, -1);
    vector<int> back(26,-1);
    vector<bool> used(false);
    //if it doesnt form a loop, greedily add it
    bool mat[26][26];

    for(int i = 0; i < n; i++){
        char cur = s[i];
        if(back[cur-'a']!=-1) continue;
        for(int j = 0; j < 26; j++){
            // cout << "on letter: " << (char) (j+'a')<<endl;
            if(j == cur-'a') continue;
            if(forward[j] == -1){
                // char a = 'a'+j;
                bool ok = true;
                int cur1 = j;
                int len = 1;
                // cout << "Starting loop detection\n";
                while(cur1 != -1){
                    // cout << "cur: " << cur1 << endl;
                    if(back[cur1] == (cur-'a')){
                        ok = false;
                        break;
                    }
                    cur1 = back[cur1];
                    len++;
                }
                if(!ok && len != 25) continue;
                back[cur-'a'] = j;
                forward[j] = cur-'a';
                break;
            }
        }
    }
    string ans = "";
    for(int i = 0; i < n; i++){
        ans+= (back[s[i]-'a']+'a');
    }
    cout << ans << endl;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}