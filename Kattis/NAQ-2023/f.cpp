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

void solve(){
    string s;
    cin >> s;
    int n = s.length();
    int vowels =0, ys = 0;
    string vowel = "aeiou";
    for(char c : s){
        for(char v : vowel){
            if(c==v) vowels++;
        }
        if(c=='y') ys++;
    }
    cout << vowels << " " << vowels+ys<<endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){
		solve();
	}
}
