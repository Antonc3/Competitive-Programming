#include <bits/stdc++.h>
using namespace std;

string p, t;
vector<int> arr;
bool check(int val){
    int l = 0;
    for(int i =0; i < p.length(); i++){
        if(arr[i] <= val) continue;
        if(p[i] != t[l]) continue;
        l++;
        if(l>=t.length()) return true;
    }
    return false;
}
int main(){
    cin >> p >> t;
    arr = vector<int>(p.length());
    for(int i = 0; i < p.length(); i++){
        int a; 
        cin >> a;
        arr[a-1] = i+1;
    }
    int l = 0, r = p.length();
    int best = l;
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid)){
            l = mid+1;
            best = mid;
        }
        else{
            r = mid-1;
        }
    }
    cout << best << endl;
}
