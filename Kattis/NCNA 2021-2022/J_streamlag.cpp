#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;

int n;
pair<int, int> a[N];

void inp(){
    cin >> n;
    for(int i = 1; i <= n; ++i)
        cin >> a[i].first >> a[i].second;
}

bool cmp(pair<int, int> a, pair<int, int> b){
    return a.second < b.second;
}

void process(){
    sort(a + 1, a + n + 1, cmp);
    long long res = a[1].first - 1;
    int Max = a[1].first;
    for(int i = 1; i < n; ++i)
        if(Max < a[i + 1].first)
            res += a[i + 1].first - Max - 1, Max = a[i + 1].first;
        else ++Max;
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    process();
}
