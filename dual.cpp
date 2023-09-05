#include <bits/stdc++.h>
using namespace std;
void ask(int a, int b, int &k, vector<int> &arr,vector<pair<int,int>> &ans){
    k++;
    arr[a] = arr[a] + arr[b];
    ans.emplace_back(a+1,b+1);
}
void solve(){
    int n;
    cin >> n;
    vector<int> arr(n);
    int maxInd = 0;
    int minInd = 0;
    int posCount = 0, negCount = 0;
    for(int i =0; i < n; i++){
        cin >> arr[i];
        if(arr[i] > arr[maxInd]){
            maxInd = i;
        }
        if(arr[i] < arr[minInd]){
            minInd = i;
        }
        posCount += (arr[i] > 0);
        negCount += (arr[i] < 0);
    }
    if(n==1){
        cout << "0\n";
        return;
    }
    int k =0;
    vector<pair<int,int>> ans;
    if(negCount == 0 || (posCount != 0 && (posCount > n/2+2 || (posCount >= n/2-2 && arr[maxInd] > -arr[minInd])))){
        while(arr[maxInd]  < -arr[minInd]){
            ask(maxInd,maxInd,k,arr,ans);
        }
        for(int i = 1; i < n; i++){
            if(i==maxInd) continue;
            while(arr[i] < arr[maxInd]){
                ask(i,maxInd,k,arr,ans);
            }
            maxInd = i;
        }
        cout << k << endl;
        for(auto i : ans){
            cout << i.first << " " << i.second << endl;
        }
    }
    else{
        while(arr[maxInd]  > -arr[minInd]){
            ask(minInd,minInd,k,arr,ans);
        }
        for(int i = n-2; i >= 0; i--){
            if(i==minInd) continue;
            while(arr[i] > arr[minInd]){
                ask(i,minInd,k,arr,ans);
            }
            minInd = i;
        }
        cout << k << endl;
        for(auto i : ans){
            cout << i.first << " " << i.second << endl;
        }
    }
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}