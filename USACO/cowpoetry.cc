// #include <bits/stdc++.h>
#include <unordered_map>
#include <fstream>
#include <vector>

using namespace std;

#define MAXM 100000
#define MAXN 5005
#define f first
#define s second
long long M = 1e9+7;

pair<long long,long long> words[MAXN];

vector<long long> rr[MAXN];

long long rEndNum[MAXN] = {0};

unordered_map<char,int> rhymes;
int n,m,k;

long long cnt[MAXN] = {0};


long long exp(int base, int power){
   if(power == 0) return 1;
   if(power == 1) return (base + M) % M;
   long long ans = exp(base,power/2);
   ans = (ans * ans + M) % M;
   if(power%2 == 1) ans = (ans*base + M) % M;
   return (ans + M) % M;
}

int main(){
	// freopen("poetry.in","r",stdin);
	// freopen("poetry.out","w",stdout);
	ifstream cin ("poetry.in");
	ofstream cout ("poetry.out");
	cin >> n >> m >> k;
	for(int i = 0; i < n; i++){
		long long a,b;cin >> a >> b;
		words[i] = {a,b};
		rr[b].push_back(a);
	}
	cnt[0] = 1;
	for(int i =0; i <= k; i++){
		for(int j = 0; j < n; j++){
			if(words[j].f + i > k) continue;
			if(words[j].f+i == k){
				rEndNum[words[j].s] = (rEndNum[words[j].s] + cnt[i]+M)%M;
			}
			else{
				cnt[words[j].f + i] = (cnt[words[j].f + i] + cnt[i]+M)%M;
			}
		}
	}
	//
	for(int i = 0; i < m; i++){
		char c;
		cin >> c;
		if(rhymes.find(c) == rhymes.end()){
			rhymes[c]= 1;
		}
		else{
			rhymes[c]++;
		}
	}
	long long ans = 1;

	for(auto r : rhymes){
		long long cur =0;
		// if(rhyme[i] == 0) continue;
		for(int j =0; j <= n; j++){
			// cout << "LASTRHYME, rhyme[i]" << rEndNum[j] << ", " << rhyme[i] << endl;
			cur=(cur+M+ exp(rEndNum[j],r.s))%M;
		}
		if(cur == 0) continue;
		ans = (M+ans* cur)%M;
		// ans %= M;
		// cout << ans<<endl;
	}
	cout << ans;
}