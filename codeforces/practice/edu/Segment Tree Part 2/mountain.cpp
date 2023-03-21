#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
 
const bool DEBUG = false;
struct item{
    ll l, r, start, send, sdiff,smax;
};
 
struct oper{
    ll a, d, ADD;
};
struct segtree{
    vector<item> S;
    vector<oper> op;
    int size;
    ll MAX_VAL = 2e10;
    item NEUTRAL_ELEMENT = {0,0,0,0,0,0};
    oper NO_OP = {LLONG_MAX,LLONG_MAX,0};
    item NOELEMENT = {MAX_VAL,MAX_VAL,0,0,0,0};
    vector<int> boundries;
 
    void propogate(int x, int lx, int rx){
        if(rx-lx==1) return;
        int m = (lx+rx)/2;
        int lstart = boundries[lx];
        int bsize = boundries.size();
        int nm = min(m,bsize-1);
        int mstart = boundries[nm];
        int nrx = min(rx,bsize-1);
        int rstart = boundries[nrx];
        if(op[x].a != LLONG_MAX && op[x].d != LLONG_MAX){
            S[x*2+1].sdiff = op[x].d;
            S[x*2+1].start = op[x].a;
            S[x*2+1].send = op[x].a+op[x].d*(mstart-1-lstart);
            S[x*2+1].smax = max(S[x*2+1].start,S[x*2+1].send);
            S[x*2+2].start = op[x].a+op[x].d*(mstart-lstart);
            S[x*2+2].sdiff = op[x].d;
            S[x*2+2].send = op[x].a+op[x].d*(rstart-1-lstart);
            S[x*2+2].smax = max(S[x*2+2].start,S[x*2+2].send);
            op[x*2+1] = {op[x].a, op[x].d, NO_OP.ADD};
            op[x*2+2] = {op[x].a+(mstart-lstart)*op[x].d,op[x].d,NO_OP.ADD};
        }
        if(op[x].ADD != NO_OP.ADD){
            S[x*2+1].start+=op[x].ADD;
            S[x*2+1].send+=op[x].ADD;
            //S[x*2+1].smax+=op[x].ADD;
            S[x*2+2].start+=op[x].ADD;
            S[x*2+2].send+=op[x].ADD;
            //S[x*2+2].smax+=op[x].ADD;
            S[x*2+1].smax += op[x].ADD;
            S[x*2+2].smax += op[x].ADD; 
            op[x*2+1].ADD+=op[x].ADD;
            op[x*2+2].ADD+=op[x].ADD;
        }
        //else if(op[x].a != LLONG_MAX){
        //    S[x*2+1].start = op[x].a;
        //    S[x*2+1].send = op[x].a+S[x*2+1].sdiff*(mstart-1-lstart);
        //    S[x*2+1].smax = max(S[x*2+1].start,S[x*2+1].send);
        //    S[x*2+2].start = S[x*2+1].send+S[x*2+2].sdiff;
        //    S[x*2+2].send = op[x].a+S[x*2+2].sdiff*(rstart-1-lstart);
        //    S[x*2+2].smax = max(S[x*2+2].start,S[x*2+2].send);
        //    op[x*2+1].a = op[x].a;
        //    op[x*2+2].a = S[x*2+2].start;
        //}
        //else if(op[x].d!=LLONG_MAX){
        //    S[x*2+1].sdiff = op[x].d;
        //    S[x*2+1].send = S[x*2+1].start+op[x].d*(mstart-1-lstart);
        //    S[x*2+1].smax = max(S[x*2+1].start,S[x*2+1].send);
        //    S[x*2+2].sdiff = op[x].d;
        //    S[x*2+2].start = S[x*2+1].send+op[x].d;
        //    S[x*2+2].send = S[x*2+2].start+op[x].d*(rstart-1-lstart);
        //    S[x*2+2].smax = max(S[x*2+2].start,S[x*2+2].send);
        //    op[x*2+1].d = op[x].d;
        //    op[x*2+2].d = op[x].d;
        //}
        S[x] = merge(S[x*2+1],S[x*2+2]);
        op[x] = NO_OP;
        //rstart should == S[x].r
    }
 
    void init(int n){
        size =1 ;
        while(size < n) size*=2;
        S.resize(2*size,NEUTRAL_ELEMENT);
        op.resize(2*size,NO_OP);
    }
    item merge(item a, item b){
        item res = {
            a.l,
            b.r,
            a.start,
            b.send,
            0,
            max(a.smax,b.smax)
        };
        return res;
    }
    
    void build(vector<int>&a,int x, int lx, int rx){
        if(rx-lx==1){
            if(lx+1<a.size()){
                S[x] = {a[lx],a[lx+1],0,0,0,0};
            }
            else if(lx<a.size()){
                S[x] = {a[lx],MAX_VAL,0,0,0,0};
            }
            else{
                S[x] = NOELEMENT;
            }
            return;
        }
        int m = (lx+rx)/2;
        build(a,x*2+1,lx,m);
        build(a,x*2+2,m,rx);
        S[x] = merge(S[x*2+1],S[x*2+2]);
    }
    void build(vector<int> &a){
        boundries = a;
        MAX_VAL=boundries.back();
        NOELEMENT = {MAX_VAL,MAX_VAL,0,0,0,0};
        build(a,0,0,size);
    }
 
    void modify(int l, int r, int a, int d, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx <= l || r <= lx) return;
        if(l <= lx && rx <= r){
            //l, r, start, end diff, max
            ll segstart = a;
            ll segend = segstart+(S[x].r-1-S[x].l)*d;
            S[x] = {S[x].l,S[x].r,segstart,segend,d,max(segend,segstart)};
            op[x] = {segstart,d,0};
            return;
        }
        int m = (lx+rx)/2;
        int lstart = boundries[lx];
        int bsize = boundries.size();
        int nm = min(m,bsize-1);
        int mstart = boundries[nm];
        modify(l,r,a,d,x*2+1,lx,m);
        // do some shit here
        int actuallstart = boundries[l];
        if(actuallstart > lstart) lstart = actuallstart;
        modify(l,r,a+(max(0,mstart-lstart))*d,d,x*2+2,m,rx);
        S[x] = merge(S[x*2+1],S[x*2+2]);
        //if(DEBUG) cout << "S[x].max: " << S[x].smax<<endl;
    }
    
    void modify2(int r, int a, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(r >= rx) return;
        if(lx >= r){
            //l, r, start, end diff, max
            S[x].start+=a;
            S[x].send+=a;
            S[x].smax+=a;
            op[x].ADD = a;
            return;
        }
        int m = (lx+rx)/2;
        int lstart = boundries[lx];
        int bsize = boundries.size();
        int nm = min(m,bsize-1);
        int mstart = boundries[nm];
        modify2(r,a,x*2+1,lx,m);
        modify2(r,a,x*2+2,m,rx);
        S[x] = merge(S[x*2+1],S[x*2+2]);
    }
    
    void modify(int l, int r, int d){
        ll initialgap = get(r-1).send-get(l-1).start;
        if(DEBUG) cout << "INITIAL L START: " << get(l).start << endl;
        modify(l,r,get(l-1).send+d,d,0,0,size);
        //set everything after and including r to it -
        ll newgap = (get(r-1).send-get(l-1).start);
        if(DEBUG) cout << "newgap: " << newgap << " initial: " <<initialgap << endl;
        modify2(r,newgap-initialgap,0,0,size);
        
    }
    item get(int i,int x, int lx, int rx){
        propogate(x,lx,rx);
        if(rx-lx==1){
            return S[x];
        }
        int m = (lx+rx)/2;
        if(i < m){
            return get(i,x*2+1,lx,m);
        }
        else{
            return get(i,x*2+2,m,rx);
        }
    }
 
    item get(int i){
        return get(i,0,0,size);
    }
    int calc(ll h, int x, int lx, int rx){
        propogate(x,lx,rx);
        if(lx >= boundries.size()-1) return boundries.back()-1;
        if(DEBUG) cout << "lx: " << lx << " rx: " << rx << endl;
        if(DEBUG) cout << "seg: "<< S[x].start << " max: " << S[x].smax << endl;
        //if(S[x].start > S[x].smax || S[x].send > S[x].smax){
        //    cout << "lx: " << lx << " rx: " << rx<<endl;
        //    auto cur = S[x];
        //    cout << cur.l << " " << cur.r << " start: " << cur.start <<" end: "<< cur.send << " diff: " << cur.sdiff << " smax: " << cur.smax<<endl;
        //}
        if(S[x].smax < h) return S[x].r-1;
        if(S[x].start > h) return -1;
        if(rx-lx==1){
            if(S[x].smax > h){
                //start calc
                ll segstart = S[x].l;
                ll segdiff = S[x].sdiff;
                ll hdiff = h-S[x].start;
                //if(S[x].l+hdiff/segdiff==12935){
                //    for(int i = 0; i < boundries.size(); i++){
                //        auto cur = get(i,0,0,size);
                //         cout << cur.l << " " << cur.r << " start: " << cur.start <<" end: "<< cur.send << " diff: " << cur.sdiff << " smax: " << cur.smax<<endl;
                //    }
                //    cout << endl;
                //}
                return S[x].l+hdiff/segdiff;
            }
            return S[x].r-1;
        }
        int m = (lx+rx)/2;
        //auto res = calc(h,x*2+1,lx,m);
        //if(res==boundries.back()-1) return res;
        //if(res == S[x*2+1].r-1){
        //    auto res2 = calc(h,x*2+2,m,rx);
        //    if(res2==-1) return res;
        //}
        //return res;
        if(S[x*2+1].smax <= h){
            int res = calc(h,x*2+2,m,rx);
            if(res == -1 ){
                return calc(h,x*2+1,lx,m);
            }
            return res;
        }
        else{
            return calc(h,x*2+1,lx,m);
        }
    }
    int calc(ll h){
        return calc(h,0,0,size);
    }
};
 
struct instr{
    char c;
    vector<int> s;
};
int main(){
    int n;
    cin >> n;
    vector<instr> instructions;
    vector<int> vals;
    map<int,int> mp;
    vals.push_back(0);
    vals.push_back(n);
    vals.push_back(n+1);
    while(true){
        char c;
        cin >> c;
        if(c=='E') break;
        else if( c== 'I'){
            vector<int> s(3);
            for(int &x : s) cin >> x;
            s[1]++;
            instructions.push_back({c,s});
            vals.push_back(s[0]);
            vals.push_back(s[1]);
        }
        else{
            int h;
            cin >> h;
            instructions.push_back({c,{h}});
        }
    }
    sort(vals.begin(),vals.end());
    vector<int> vnodupe;
    for(int i = 0; i < vals.size();i++){
        while(i < vals.size()-1 && vals[i] == vals[i+1]) i++;
        vnodupe.push_back(vals[i]);
    }
    if(DEBUG) cout << " VNODUPE SIZE: " << vnodupe.size()<<"\n";
    for(int i = 0; i < vnodupe.size(); i++){
        mp[vnodupe[i]]=i;
    }
    segtree st;
    st.init(vnodupe.size()+2);
    st.build(vnodupe);
    for(instr i : instructions){
        if(i.c=='I'){
            if(DEBUG) cout << "instr: "<< i.c << " " << i.s[0] << " " << i.s[1] <<" " << i.s[2] << endl;
            st.modify(mp[i.s[0]],mp[i.s[1]],i.s[2]);
        }
        else{
            if(DEBUG) cout << "instr: "<< i.c << " " << i.s[0] <<endl;
            //st.modify(mp[i.s[0]],mp[i.s[1]]+1,i.s[2]);
            cout << st.calc(i.s[0])<<"\n";
        }
    }
}

