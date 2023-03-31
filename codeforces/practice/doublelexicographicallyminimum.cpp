#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    vector<int> ans(n);
    int r = n-1;
    int l = 0;
    vector<int> cnt(26,0);
    rep(i,0,n){
        cnt[s[i]-'a']++;
    }
    int last = -1;
    rep(i,0,26){
        if(cnt[i]==0) continue;
        while(cnt[i] >= 2 && (last == -1 || r-l == cnt[i])){
            ans[l++] = i+'a'; 
            ans[r--] = i+'a'; 
            cnt[i]-=2;
        }
        if( last != -1){
            //cout << "WOW!\n";
            //cout << l << " " << i+'a' << " " << r << " " << last+'a'<<endl;
            ans[l++] = i+'a';
            ans[r--] = last+'a';
            cnt[last]--;
            cnt[i]--;
            break;
        }
        if(cnt[i]>=1){
            //cout << "HERE!\n";
            last = i;
        }
    }
    rep(i,0,26){
        while(cnt[i] > 0){
            ans[l++] = i+'a';
            cnt[i]--;
        }
    }
    rep(i,0,n) cout << (char) ans[i];
    cout << '\n';
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while(t--){
		solve();
	}
}
