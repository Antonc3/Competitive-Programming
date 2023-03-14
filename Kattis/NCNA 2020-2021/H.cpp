#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int cnt = 0;
double tf, tr;
double s;
double temp[N];

void process(){
    while(cin >> s){
        temp[++cnt] = s;
        if(s==0){
            cout << 0 << '\n';
        }
        else if(0 < s && s < 1){
            cout << 1 << '\n';
        }
        else{
            int i = (int)floor(s);
            double a = i, b = a + tf, c = a + tr;
            if(s <= b)
                cout << i << '\n';
            else if(s >= c)
                cout << i + 1 << '\n';
            else{
                for(int j = cnt - 1; j >= 1; --j){
                    if(temp[j] < b){
                        cout << i << '\n';
                        break;
                    }
                    if(temp[j] > c){
                        cout << i + 1 << '\n';
                        break;
                    }
                }
            }
        }
    }
}

void inp(){
    cin >> tf >> tr;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    process();
}