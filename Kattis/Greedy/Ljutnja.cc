#include <bits/stdc++.h>

using namespace std;
#define MAXN 100005
long long kids[MAXN];

int main(){
    long long m;
    long long n;
    cin >> m >> n;
    for(int i =0; i < n; i++){
        cin >> kids[i];
    }
    sort(kids, kids+n);
    long long usedCandies = 0;
    int children = 1;
    for(int i = n-1; i >= 1; i--){
        if(usedCandies+((kids[i]-kids[i-1])*children) >= m) break;
        usedCandies += (kids[i]-kids[i-1])*children;
        // cout << "usedCandies " << usedCandies << " children " << children+1 << endl;
        children++;
    }
    long long ans = 0;
    for(int i = 0; i < n-children; i++){
        ans += kids[i]*kids[i];
    }
    // cout << "CHILDREN: " << children<<endl;
    long long left = m-usedCandies;
    long long morechild = left%children;
    long long lesschild = children-morechild;
    // cout << "morechild: " << morechild << " lesschild: " <<lesschild<<endl;
    // cout << "used cancides: " << usedCandies << "LEFT: " << left<<endl;
    long long lcc = max(0ll,(kids[n-children]-(left)/children));
    long long mcc = max(0ll,(kids[n-children]-((left)/children)-1));
    // cout << "ans: " << ans << " lcc " << lcc << "mcc " << mcc<<endl;
    ans += lesschild*lcc*lcc;
    ans += morechild*mcc*mcc;
    //we have c children at hunger of child[n-children]
    // we have m-usedCandies candies left
    //  children[i]-((m-usedCandies)/children)  for left-(left/children)
    cout << ans;
}   