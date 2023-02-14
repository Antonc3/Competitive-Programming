#include <bits/stdc++.h>

using namespace std;

int main(){
    string n; cin >> n;
    vector<int> num(4);
    for(int i = 0; i < 4; i++){
        num[i] = n[i]-'0';
    }

    for(int i = 3; i >= 0; i--){
        for(int j = 0; j < 4; j++){
            // cout << "num[j] " << num[j] << " j " << j << " i " << i<<endl;
            if(num[j] >= (1 << i)){
                cout << "*";
                num[j]-=(1 << i);
            }
            else{
                cout << ".";
            }
            if(j < 3) cout << " ";
            if(j==1) cout << "  ";
        }
        cout << "\n";
    }
}