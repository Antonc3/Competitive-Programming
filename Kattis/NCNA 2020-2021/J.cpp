#include<bits/stdc++.h>

using namespace std;

int n;
double t;
double d, s, f_min, f_max;
double Lmin, Lmax, L;

void inp(){
    cin >> n >> d >> s >> t >> f_min >> f_max;
}

vector<double> store[512];

void process(){
    while(cin >> L){
        Lmin = L - 2 * f_max;
        Lmax = L - 2 * f_min;
        if(s <= Lmax)
            store[1].push_back(s + t*2);
        for(int i = 2; i < (1<<n); ++i){
            if(i&1){
                int bit1 = -1, bit2 = -1;
                for(int u = n - 1; u >= 0; --u)
                    if((i>>u)&1){
                        if(bit1==-1) bit1 = u;
                        else if(bit2==-1) bit2 = u;
                        else break;
                    }
                for(double dist : store[i^(1<<bit1)]){
                    // bit2 to bit1
                    if(bit1 == bit2 + 1 && dist + d * 2 + t * 2 <= Lmax)
                        store[i].push_back(dist + d * 2 + t * 2);
                    double temp = d * (bit1 - bit2);
                    if(dist + sqrt(temp * temp + s*s) * 2 + t * 2 <= Lmax)
                        store[i].push_back(dist + sqrt(temp * temp + s*s) * 2 + t * 2);
                }
            }
        }
        int res = 0;
        for(int i = 0; i < (1<<n); ++i)
            if(((i>>(n-1))&1) && (i&1)){
                for(double dist : store[i])
                    if(Lmin <= dist && dist <= Lmax)
                        ++res;
            }
        for(int i = 0; i < (1<<n); ++i)
            store[i].clear();
        cout << res << '\n';
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    process();
}