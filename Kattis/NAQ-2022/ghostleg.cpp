#include <bits/stdc++.h>

using namespace std;
#define MAXN 105

int n,m;
int arr[MAXN];

int main(){
  cin >> n >> m;
  for(int i = 1; i <= n; i++){
    arr[i] = i;
  }
  for(int i = 0; i < m; i++){
    int a;
    cin >> a;
    int tmp = arr[a];
    arr[a] = arr[a+1];
    arr[a+1] = tmp;
  }
  for(int i = 1; i<=n; i++){
    cout << arr[i]<<endl;
  }
}
