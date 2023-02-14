#include <bits/stdc++.h>
using namespace std;

bool arr[1299721];
vector<int> primes;

int main(){
    int n = 1299721;
    for(int i = 2; i < n; i++) arr[i] = true;
    for(int i = 2; i < n; i++){
        if(arr[i]){
            primes.push_back(i);
            for(int j=i; j <n; j+=i){
                arr[j] = false;
            }
        }
    }
    int l,r;
    cin >> l >> r;
    l--;
    r--;
    string pattern;
    cin >> pattern;
    int ans = 0;
    for(int i = l; i <= r; i++){
        string cur = to_string(primes[i]);
        bool good = false;
        for(int j = 0; j < cur.length(); j++){
            for(int k = 0; k < pattern.length(); k++){
                if(cur[j+k] != pattern[k]){
                    break;
                }
                else{
                    if(k==pattern.length()-1) good = true;
                }
            }
            if(good){
                ans++;
                break;
            }
        }
    }
    cout << ans << endl;
}