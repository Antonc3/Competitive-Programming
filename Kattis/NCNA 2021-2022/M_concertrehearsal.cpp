#include <bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

int n, p, k;
long long sum[N];

void inp(){
    cin >> n >> p >> k;
    for(int i = 1; i <= n; ++i){
        int x; cin >> x;
        sum[i] = sum[i - 1] + x;
    }
}

vector<pair<int, int> > g[N];
long long f[N][50], nxt[N][50];

void init(){
    for(int i = 1; i <= n; ++i)
        f[i][0] = g[i][0].second, nxt[i][0] = g[i][0].first;
    for(int u = 1; u <= 31; ++u){
        for(int i = 1; i <= n; ++i){
            nxt[i][u] = nxt[nxt[i][u - 1]][u - 1];
            f[i][u] = f[i][u - 1] + f[nxt[i][u - 1]][u - 1];
        }
    }
}

void process(){
    for(int st = 1; st <= n; ++st){
        int l = st, r = n, pos = st;
        while(l <= r){
            int mid = (l + r) / 2;
            if(sum[mid] - sum[st - 1] <= p){
                pos = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        int remain = p - (sum[pos] - sum[st - 1]);
        int w = remain / sum[n];
        remain %= sum[n];
        int e = pos + 1;
        if(e > n){
            e = 1;
            ++w;
        }
        if(e == 1){
            l = 1, r = n;
            while(l <= r){
                int mid = (l + r) / 2;
                if(sum[mid] <= remain){
                    e = mid + 1;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            if(e > n){
                e = 1;
                ++w;
            }
        }
        g[st].push_back({e, w});
    }
    init();
    int st = 1;
    long long res = 0;
    for(int i = 31; i >= 0; --i){
        if((k>>i) & 1){
            res += f[st][i];
            st = nxt[st][i];
        }
    }
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    process();
} 