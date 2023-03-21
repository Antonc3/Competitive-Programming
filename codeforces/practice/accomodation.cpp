#include <bits/stdc++.h>
using namespace std;

int getmin(vector<int> &row){
    int n = row.size();
    int cnt = row[n-1];
    int twobedroom = 0;
    int twobedroomcap = n/4;
    vector<int> used(n,0);
    queue<int> numlights[3];
    for(int i = 0; i < n-1; i++){
        int nlights = row[i] + row[i+1];
        cnt+=row[i];
        numlights[nlights].push(i);
    }
    while(twobedroom < twobedroomcap){
        if(numlights[2].size()){
            int cur = numlights[2].front();
            numlights[2].pop();
            if(used[cur] || used[cur+1]) continue;
            used[cur] = used[cur+1] = 1;
            cnt--;
            twobedroom++;
        }
        else if(numlights[1].size()){
            int cur = numlights[1].front();
            numlights[1].pop();
            if(used[cur] || used[cur+1]) continue;
            used[cur] = used[cur+1] = 1;
            twobedroom++;
        }
        else{
            twobedroom++;
        }
    }
    return cnt;
}

int getmax(vector<int> &row){
    int n = row.size();
    int cnt = 0;
    int twobedroom = 0;
    vector<int> used(n,0);
    queue<int> numlights[3];
    for(int i =0 ; i < n; i++) cnt+=row[i];
    for(int i = 0; i < n-1; i++){
        int nlights = row[i] + row[i+1];
        if(nlights <2){

            twobedroom++;i++;
        }
    }
    return cnt-max(0,(n/4-twobedroom));
}
int main(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> grid(n,vector<int>(m)); 

    int minval = 0;
    int maxval = 0;
    for(int i = 0; i < n; i++){
        string s;
        cin >> s;
        vector<int> cur;
        for(int j = 0; j < m; j++){
            cur.push_back(s[j]-'0');
        }
        minval+=getmin(cur);
        int cmax = getmax(cur);
        maxval+=cmax;
    }
    cout << minval << " " << maxval << endl;
}
