#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
typedef long long ll;
bool DEBUG = false;
int n;

long long arr[MAXN];
int main(){
  cin >> n;
  if(DEBUG) cout << "read n\n";
  for(int i = 0; i < n; i++){
    cin >> arr[i];
    if(DEBUG) cout << "I: " << i << ", " <<arr[i] <<endl;
  }
  if(DEBUG) cout << "Done reading inputing\n";
  sort(arr, arr+n);
  if(DEBUG) cout << "Done sorting\n";
  long long total = 0;
  for(int i = 0; i < n; i++){
    total+=arr[i];
  }
  long long prevSum = arr[n-1];
  int i = n-1;
  while(i > 0 &&(prevSum)*2 <=total){
    long long sum = 0;
    while(i > 0 && sum < prevSum){
      if(DEBUG) cout << sum << " " << prevSum << " i: " << i << endl;
      i--;
      sum+=arr[i];
    }
    prevSum += sum;
  }
  if(DEBUG) cout << prevSum << " " << total<<endl;
  cout << n-i << endl;
}
