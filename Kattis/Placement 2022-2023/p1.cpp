#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define MAXN 20005

int n, m;
int head[MAXN];
int knight[MAXN];

bool solve(){
 cin >> n >> m; 

 if(n == 0){
   return false;
 }
 for(int i = 0; i < n; i++){
   cin >> head[i];
 }
 for(int i = 0; i < m; i++){
   cin >> knight[i];
 }
 sort(head, head+n);
 sort(knight, knight+m);
 int ki = 0;
 int totalGold = 0;
 for(int i = 0; i < n; i++){
  while(ki < m && knight[ki] < head[i]) ki++; 
  if(ki >= m || knight[ki] < head[i] ){
    cout << "Loowater is doomed!\n";
    return true;
  }
  totalGold+=knight[ki]; 
  ki++;
 }
 cout << totalGold << endl;
 return true;
}


int main() {
 while(solve()){
 }
}
