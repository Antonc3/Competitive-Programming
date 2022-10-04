#include <bits/stdc++.h>

using namespace std;
#define MAXN 1005
#define f first
#define s second
typedef pair<int,int> pii;
int n;
multiset<int> houses;
int d1[MAXN];
int d2[MAXN];
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> d1[i];
        houses.insert(-d1[i]);
        houses.insert(d1[i]);
    }
    for(int i = 0; i < n; i++){
        cin >> d2[i];
    }
    //set house at s[0]-2
    vector<int> usedHouses;
    int secondHouse;
    // cout << "FIRST HOUSE: " << *houses.begin();
    for(int i = 0; i < n*2; i++){
        //four times
        // *advance(houses.begin(),i);
        auto it = houses.begin();
        for(int j =0; j < i; j++){
            it++;
        }
        int usedHouse = (*it);

        secondHouse = usedHouse-d2[0];
        cout << "SECOND HOUSE: " << secondHouse<<endl;
        cout << "USED HOUSE: " <<usedHouse << endl;
        usedHouses.push_back(usedHouse);
        houses.erase(houses.find(usedHouse));
        houses.erase(houses.find(-usedHouse));
        bool goodHouse = true;
        for(int j = 1; j < n; j++){
            cout <<"HOUSES SIZE: " << houses.size() << endl;
            auto it = houses.find(secondHouse+d2[j]);
            if(it!=houses.end()){
                usedHouses.push_back(*it);
                int usingHouse = *it;
                houses.erase(houses.find(usingHouse));
                houses.erase(houses.find(-usingHouse));
                continue;
            }
            it = houses.find(secondHouse-d2[j]);
            if(it!=houses.end()){
                usedHouses.push_back(*it);
                int usingHouse = *it;
                houses.erase(houses.find(usingHouse));
                houses.erase(houses.find(-usingHouse));
                continue;
            }
            goodHouse = false;
            break;
        }
        if(goodHouse) break;
        for(int j : usedHouses){
            houses.insert(-j);
            houses.insert(j);
        }
        usedHouses.clear();
        goodHouse=true;
        secondHouse = usedHouse+d2[0];
        cout << "SECOND HOUSE: " << secondHouse<<endl;

        usedHouses.push_back(usedHouse);
        houses.erase(houses.find(usedHouse));
        houses.erase(houses.find(-usedHouse));
        goodHouse = true;
        for(int j = 1; j < n; j++){
            cout <<"HOUSES SIZE: " << houses.size() << endl;
            auto it = houses.find(secondHouse+d2[j]);
            if(it!=houses.end()){
                usedHouses.push_back(*it);
                int usingHouse = *it;
                houses.erase(houses.find(usingHouse));
                houses.erase(houses.find(-usingHouse));
                continue;
            }
            it = houses.find(secondHouse-d2[j]);
            if(it!=houses.end()){
                usedHouses.push_back(*it);
                int usingHouse = *it;
                houses.erase(houses.find(usingHouse));
                houses.erase(houses.find(-usingHouse));
                continue;
            }
            goodHouse = false;
            break;
        }
        if(goodHouse) break;
        for(int j : usedHouses){
            houses.insert(-j);
            houses.insert(j);
        }
        usedHouses.clear();
        goodHouse=true;
    }
    if(usedHouses.size() == n){
        cout << "YES\n";
        sort(usedHouses.begin(), usedHouses.end());
        int smallest  = min(secondHouse,usedHouses[0]);
        for(int house : usedHouses){
            cout << house-smallest<< " ";
        }
        cout << endl;
        cout << -smallest << " " << secondHouse-smallest<<endl;
        return;
    }
    cout << "NO\n";    
}

int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
    }
}