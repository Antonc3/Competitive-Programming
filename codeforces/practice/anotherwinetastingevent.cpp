#include <bits/stdc++.h>
using namespace std;
#define MAXN 1000005
int n;
string s;

int check(){
    //cout << "val: " << val << endl;
    int r = 0;
    int wcount = 0;
    int best = wcount;
    for(int i = 0; i < 2*n-1; i++){
        while(r < 2*n-1 && (r-i < n)){
            if(s[r] == 'W') wcount++;
            r++;
        }
        if(r-i==n){
            best = max(wcount,best);

        }
        //cout << "res: " << res << endl;
        wcount -=(s[i]=='W');
    }
    return best;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n>> s;
    int best = check();
    cout << best << endl;
}
