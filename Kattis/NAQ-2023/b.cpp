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
ll M = 9302023;
#define MAXN 1000005
int dp[MAXN][2];
int cnt[MAXN][2];
string nums[] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
void solve(){
    string s;
    cin >> s;
    int n = s.length();
    ll ans2 = 1;
    ll minLen = 0;
    int ii = 0;
    while(ii < n){
        vector<int> last;
        int found = -1;
        for(int i =0; i < 10; i++){
            string num = nums[i];
            int k = num.length();
            if(ii+k > n) continue;
            string sub = s.substr(ii,k);
            if(sub.compare(num) == 0){
                found = i;
                break;
            }
        }
        if(found == -1){
            minLen++;
            ii++;
            continue;
        }
        last.push_back(nums[found].length());
        ii += last.back();
        while(found != -1){
            char lastChar = s[ii-1];
            found = -1;
            for(int i =0; i < 10; i++){
                string num = nums[i];
                int k = num.length();
                if(ii+k-1 > n) continue;
                string numsub = num.substr(1);
                string sub = s.substr(ii,k-1);
                if(numsub.compare(sub) == 0){
                    found = i;
                    break;
                }
            }

            last.push_back(nums[found].length());
            ii += last.back()-1;
            if(found == -1) break;
        }
        //dp 0 not choose, 1 is choose
        cnt[0][0] = 1;
        cnt[0][1] = 1;
        dp[0][0] = 0;
        dp[0][1] = last[0]-1;
        int sum = last[0];
        for(int i = 1; i < last.size(); i++){
            sum+=last[i]-1;
            dp[i][0] = max(dp[i-1][1], dp[i-1][0]);
            dp[i][1] = dp[i-1][0] + last[i]-1;
            if(dp[i-1][1] == dp[i-1][0]){
                cnt[i][0] = cnt[i-1][0]+cnt[i-1][1];
            }
            else if(dp[i-1][1] > dp[i-1][0]){
                cnt[i][0] = cnt[i-1][1];
            }
            else{
                cnt[i][0] = cnt[i-1][0];
            }
            cnt[i][1] = cnt[i-1][0];
        }
        ll total = 0;
        int sz = last.size()-1;
        if(dp[sz][0] == dp[sz][1]){
            total = cnt[sz][0]+cnt[sz][1];
        }
        else if(dp[sz][0] < dp[sz][1]){
            total = cnt[sz][1];
        }
        else{
            total = cnt[sz][0];
        }
        minLen += (sum-max(dp[sz][0],dp[sz][1]));

        ans2 = (ans2*total)%M;
    }
    cout << minLen << " " << ans2 << endl;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin.exceptions(cin.failbit);
	int t = 1;
	while(t--){
		solve();
	}
}
