#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb(x) push_back(x)
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
#define ALPHABET_SIZE 26
#define MAX_N 1000005

struct trie{
    vector<map<int,int>> S;
    vector<int> cnt;
    int nxt;
    trie(){
        S.resize(5);
        cnt.resize(5,0);
        nxt = 1;
    }
    void build(vector<int> s){
        int i = 0, v =0;
        while(i < s.size()){
            cnt[v]++;
            if(S[v].count(s[i]) == 0){
                S.push_back(map<int,int>());
                cnt.push_back(0);
                v = S[v][s[i++]] = nxt++;
            }
            else{
                v = S[v][s[i++]];
            }
        }
        cnt[v]++;
    }
    int query(vector<int> s){
        int i = 0, v = 0;
        while(i < s.size()){
            if(S[v].count(s[i]) == 0) return 0;
            v = S[v][s[i++]];
        }
        return cnt[v];
    }
};

void solve(){
    int n,q;
    cin >> n >> q;
    vector<string> dict(n);
    vector<string> added(n);
    trie pref;
    trie suff;
    trie prefsuff;
    for(int i = 0; i < n; i++){
        string sf;
        cin >> sf;
        string sb = sf;
        reverse(sb.begin(),sb.end());
        vector<int> p, s, ps;
        for(int i = 0; i < sf.length(); i++){
            p.push_back(sf[i]-'a');
            s.push_back(sb[i]-'a');
            ps.push_back((sf[i]-'a')*30+(sb[i]-'a'));
        }
        pref.build(p);
        suff.build(s);
        prefsuff.build(ps);
    }
    vector<int> ans(q);
    for(int i =0 ; i < q; i++){
        string op, a,b;
        cin >> op >> a >> b;
        int opp = -1;
        reverse(b.begin(),b.end());
        vector<int> p, s, ps;
        for(int i = 0; i < a.length(); i++){
            p.push_back(a[i]-'a');
            s.push_back(b[i]-'a');
            ps.push_back((a[i]-'a')*30+(b[i]-'a'));
        }
        int prefRes = pref.query(p);
        int suffRes = suff.query(s);
        int prefAndSuff = prefsuff.query(ps);
        if(op.compare("AND")==0){
            ans[i] = prefAndSuff;
        }
        else if(op.compare("OR")==0){
            ans[i] = prefRes+suffRes-prefAndSuff;
        }
        else{
            ans[i] = prefRes+suffRes-prefAndSuff-prefAndSuff;
        }
    }
    for(int i : ans) cout << i << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){
		solve();
	}
}
