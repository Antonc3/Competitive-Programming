#include<bits/stdc++.h>

using namespace std;
const int N = 2e5 + 5;

string s;
bool flag = 0;
vector<vector<string> > store1, store2, st1, st2;
vector<vector<string> > ss1, ss2;

bool cmp(vector<string> &s, vector<string> &t){
    string t1 = "";
    for(char c : s[2])
        t1 += tolower(c);
    string t2 = "";
    for(char c : t[2])
        t2 += tolower(c);
    return t1 < t2;
}

void process(){
    while(getline(cin, s) && s!="0"){
        stringstream ss(s);
        string temp;
        int cnt = 0;
        vector<string> s1;
        while(ss>>temp){
            s1.push_back(temp);
        }
        if(s==""){
            flag = 1;
            continue;
        }
        if(!flag)
            store1.push_back(s1);
        else store2.push_back(s1);
        vector<string> t1;
        for(string s : s1){
            string t = "";
            for(char c : s)
                t += tolower(c);
            t1.push_back(t);
        }
        if(!flag)
            st1.push_back(t1);
        else st2.push_back(t1);
    }
    bool ok = 0;
    for(int i = 0; i < (int)st1.size(); ++i)
    {
        vector<string> temp = st1[i];
        bool ok1 = 0;
        for(auto temp1 : st2)
            if((temp1[2]==temp[2]) || (temp[0]==temp1[0] && temp[1]==temp1[1])){
                ok1 = 1;
                break;
            }
        if(!ok1){
            ss1.push_back(store1[i]);
            ok = 1;
        }
    }
    for(int i = 0; i < (int)st2.size(); ++i){
        vector<string> temp = st2[i];
        bool ok1 = 0;
        for(auto temp1 : st1)
            if(temp1[2]==temp[2] || (temp[0]==temp1[0] && temp[1]==temp1[1])){
                ok1 = 1;
                break;
            }
        if(!ok1){
            ss2.push_back(store2[i]);
            ok= 1;
        }
    }
    if(!ok){
        cout << "No mismatches.";
        return;
    }
    sort(ss1.begin(), ss1.end(), cmp);
    sort(ss2.begin(), ss2.end(), cmp);
    for(vector<string> temp : ss1){
        cout << "I " << temp[2] << " " << temp[1] << " " << temp[0] << '\n';
    }
    for(vector<string> temp : ss2){
            cout << "O " << temp[2] << " " << temp[1] << " " << temp[0] << '\n';
    }
}

void inp(){

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //inp();
    process();
}