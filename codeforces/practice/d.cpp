#include <bits/stdc++.h>
using namespace std;

int main(){
    int n,k;
    cin >> n >> k;
    int larl = 0, lars = 1e9;
    int smal = 0, smas = 1e9;
    for(int i =0; i < n; i++){
        int a;
        cin >> a;
        vector<int> digits;
        for(int j = 0; j < k; j++){
            digits.push_back(a%10);
            a/=10;
        }
        sort(digits.begin(),digits.end());
        int a1 = 0;
        int a2 = 0;
        for(int j = 0; j < k; j++){
            int jj = (k-j-1);
            a1 = a1*10 + digits[j];
            a2 = a2*10 + digits[jj];
        }
        larl = max(larl,a1);
        lars = min(lars,a1);       
        smal = max(smal,a2);
        smas = min(smas,a2);
    }
    cout << min(larl-lars,smas-smal);
}