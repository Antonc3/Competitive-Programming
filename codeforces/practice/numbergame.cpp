#include <bits/stdc++.h>
using namespace std;

int cntoddprimefactors(int n){
    while(n%2==0) n/=2;
    int cnt = 0;
    for(int i = 3; i*i <= n; i+=2){
        while(n%i==0){
            n/=i;
            cnt++;
        }
    }
    if(n>1) cnt++;
    return cnt;
}

int nafterodd(int n){
    int cnt = 0;
    while(n%2==0){
        n/=2;
        cnt++;
    }
    return cnt;
}
void solve(){
    int n;
    cin >> n;
    int oddfactors = cntoddprimefactors(n);
    int n2 = nafterodd(n);
    //if oddfactors is even then fastestfinger wins
    //otherwise the other dude wins
    if(n==1){
        cout << "FastestFinger\n";
        return;
    }
    if(n2==0){
        cout << "Ashishgup\n";
        return;
    }
    // 2*some odd thingy
    // 2*3*3, first divides by 3, then second divides by 3 first subtracts 1, they win
    if(n2==1 && oddfactors==1){
        cout << "FastestFinger\n";
        return;
    }
    if(n2==1 && oddfactors > 1){
        cout << "Ashishgup\n";
        return;
    }
    if(n2 > 1 && oddfactors==0){
        cout << "FastestFinger\n";
        return;
    }
    cout << "Ashishgup\n";
}


int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}
