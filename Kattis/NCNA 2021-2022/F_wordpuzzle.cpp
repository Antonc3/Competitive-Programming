#include <bits/stdc++.h>
using namespace std;
string s;
int n;
int ans =0;
const int M = 1e9+7;
void check(string pat){
    vector<vector<int> > dp = vector<vector<int> >(n + 5, vector<int>(52, 0));
    for(int i = 1; i <= n; i++){
        
        for(int j = 1; j <= pat.length(); j++){
            dp[i][j] = dp[i-1][j];
            if(j==1){
                if(s[i-1] == pat[j-1]){
                    dp[i][j] += 1;
                }
            }
            if(s[i-1] == pat[j-1]){
                dp[i][j]+=dp[i-1][j-1];
                dp[i][j] %= M;
            }
            // cout << dp[i][j] << " ";ontests/ncna2
        }
        // cout << endl;
    }
    ans+=dp[n][pat.length()];
    ans%=M;
}


set<string> seen;
int main(){
    cin >> s;
    n = s.length();
    string pattern;
    cin >> pattern;
    int p = pattern.length();
    for(int i= 0; i < p; i++){
        string tocheck = pattern.substr(1) + pattern[0];
        if(seen.find(tocheck) == seen.end()){
            check(tocheck);
            seen.insert(tocheck);
            // cout << tocheck << endl;
        }
        pattern = tocheck;
    }
    cout << ans << endl;
}