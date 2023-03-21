#include <bits/stdc++.h>

using namespace std;

vector<int> arr(101,0);

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, c;
        cin >> n >> c;
        fill(arr.begin(), arr.end(), 0);
        for(int i= 0; i < n; i++){
            int a;
            cin >> a;
            arr[a]++;
        }
        int cost = 0;
        for(int i =1 ; i < 101; i++){
            if(arr[i] > c) cost+=c;
            else cost +=arr[i];
        }
        cout << cost<<endl;
    }
}