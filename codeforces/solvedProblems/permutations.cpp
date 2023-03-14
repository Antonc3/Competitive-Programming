#include <bits/stdc++.h>
using namespace std;

int arr[10][10];

vector<vector<int>> permutations;
int fact[10];

void generatePermutations(vector<int> &cur, vector<int> &building){
    if(cur.size()==0) {
        permutations.push_back(building);
    }
    for(int i = 0; i < cur.size(); i++){
        vector<int> a;
        for(int j = 0; j < cur.size(); j++){
            if(j==i) continue;
            a.push_back(cur[j]);
        }
        building.push_back(cur[i]);
        generatePermutations(a,building);
        building.pop_back();
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < k; j++){
            char c;
            cin >> c;
            arr[i][j] = c-'0';
        }
    }
    vector<int> starter;
    for(int i = 0; i < k; i++) starter.push_back(i);
    vector<int> bstart;
    generatePermutations(starter, bstart);
    int best = 1e9;
    for(int i = 0; i < permutations.size(); i++){
        vector<int> cur = permutations[i];
        //for(int val : cur) cout << val <<" ";
        //cout << endl;
        int maxnum = 0;
        int minnum = 1e9;
        for(int j = 0; j < n; j++){
            int curnum = 0;
            for(int z = 0; z < k; z++){
                curnum*=10;
                curnum+=arr[j][cur[z]];
            }
            maxnum = max(curnum,maxnum);
            minnum = min(minnum,curnum);
        }
        //cout << "maxnum: " << maxnum << " minnum: " << minnum<<endl;
        best = min(best,maxnum-minnum);
    }
    cout << best << endl;

}
    //0 1 2 3
    //0 1 3 2
    //0 2 1 3
    //0 2 3 1
    //0 3 1 2
    //0 3 2 1
    //1 0 2 3
    //1 0 3 2
    //1 2 0 3
    //1 2 3 0
    //1 3 0 2
    //1 3 2 0
    //2 0 1 3
    //2 0 3 1
    //2 1 0 3
    //2 1 3 0
    //2 3 0 1
    //2 3 1 0
    //3 0 1 2
    //3 0 2 1
    //3 1 0 2
    //3 1 2 0
    //3 2 0 1
    //3 2 1 0
