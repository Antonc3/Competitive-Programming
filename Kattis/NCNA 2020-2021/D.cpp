#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

string S; 

void process(string S){
    set<char> s;
    set<string> s1;
    for(char a : S)
        s.insert(a);
    for(int l = 0; l < (int)S.size(); ++l)
        for(int r = l; r < (int)S.size(); ++r){
            if(l==0 && r==(int)S.size()-1)
                continue;
            set<char> ss;
            for(char c : S.substr(l, r - l + 1))
                ss.insert(c);
            if((int)ss.size()!=(int)s.size())
                continue;
            ss.clear();
            if(l==r){
                s1.insert(S.substr(l, r - l + 1));
                continue;
            }
            for(char c : S.substr(l + 1, r - l))
                ss.insert(c);
            if((int)ss.size()==(int)s.size())
                continue;
            ss.clear();
            for(char c : S.substr(l, r - l))
                ss.insert(c);
            if((int)ss.size()==(int)s.size())
                continue;
            s1.insert(S.substr(l, r - l + 1));
        }
    cout << (int)s1.size() << '\n'; 

}

void inp(){
    while (cin >> S) {
        process(S); 
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
}