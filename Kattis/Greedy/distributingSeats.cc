#include <bits/stdc++.h>

using namespace std;
#define f first
#define s second
#define MAXN 100005

typedef pair<int,int> pii;



int n, r, c;
vector<pii> passengers;
// int ft[MAXN];

// int lsb(int pos){
//     return pos&-pos;
// }
// int prefix(int i){
//     int sum = ft[0];
//     for(; i != 0; i-=lsb(i)){
//         sum+=ft[i];
//     }
//     return sum;
// }

// void update(int pos, int val){
//     while(pos <= r+2){
//         ft[pos]+=val;
//         pos+=lsb(pos);
//     }
// }
// class Compare{
//     public:
//         bool operator() (pii a, pii b){
//             // form starting seat, endingseat;
//             int aseats =(a.s-a.f+1)*c-(prefix(a.s)-prefix(a.f-1));
//             int bseats = (b.s-b.f+1)*c-(prefix(b.s)-prefix(b.f-1));
//             // cout << "aseats: " << aseats<< " bseaats: " << bseats<<endl;
//             return aseats>bseats;
//         }
// };
bool comp(pii a, pii b){
    return a.s < b.s;
}
int main(){
    cin >> n >> r >> c;
    // fill(ft,ft+r+4, 0);
    // set<int> usedCols;
    for(int i =0; i < n; i++){
        int a,b,c1;
        cin >> a >> b >> c1;
        // if(usedCols.find(b) == usedCols.end()) usedCols.insert(b);
        passengers.push_back({max(1,a-c1),min(r, a+c1)});
    }
    int ans = 0;        
    set<pii> available;
    for(int i = 1; i <= r; i++){
        available.insert({i,c});
    }

    sort(passengers.begin(), passengers.end(), comp);
    // for(auto i : passengers){
    //     cout << i.f << " " <<i.s << endl;
    // }
    // int curseat = 0;
    for(int i =0; i < passengers.size(); i++){
        pii cur = passengers[i];
        // if(cur.f > curseat) curseat = cur.f;
        auto lb = available.lower_bound({cur.f, 0});
        pii seat = (*lb);
        if(lb == available.end()) continue;
        if((*lb).f > cur.s) continue;
        available.erase(lb);
        if(seat.s > 1) available.insert({seat.f, seat.s-1});
        ans++;
    }
    // cout << available.siz
    // for(int i : usedCols){
    // vector<int> seats;
    // priority_queue<pii, vector<pii>, Compare> pq;
    // for(auto p : passengers){   
    //     // cout << "PEOPLE IN ROW "     << 1 << ": " <<p.f << " " << p.s << endl;
    //     pq.push({max(1,p.f-p.s),min(r, p.f+p.s)});
    // }

    // while(!pq.empty()){
    //     pii cur = pq.top();
    //     // cout << "CUR: " << cur.f << " " << cur.s << endl;
    //     pq.pop();
    //     auto it = available.lower_bound({cur.f,0});
    //     pii seat = *it;
    //     if(it == available.end() || seat.f > cur.s) continue;
    //     // cout <<"seat taken: " <<  seat.f << endl ;
    //     available.erase(it);
    //     if(seat.s > 1) available.insert({seat.f, seat.s-1});
    //     // seats.push_back(seat);
    //     update(seat.f,1); 
    //     ans++;
    // }
    // for(auto i : available){
    //     cout << "row: " << i.f << ", seats avail: " << i.s<<endl;
    // }
        // for(int j : seats){
        //     update(j,-1);
        //     available.insert(j);
        // }        
    // }
    cout << ans<<endl;
}