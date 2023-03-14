#include <bits/stdc++.h>

using namespace std;

multimap<string,vector<string>> m;
vector<vector<string>> queries;
void readInp(){
    string s;
    while(true){
        getline(cin,s);
        // cout << s;
        if(s.length() == 0) break;
        int last = 0;
        string factName = "";
        vector<string> arglist;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == ',' || s[i] ==')'){
                string cur = s.substr(last,i-last);
                int front = 0;
                while(cur[front] == ' '){
                    front++;
                }
                int back = cur.length()-1;
                while(cur[back]==' '){
                    back--;
                }
                cur = cur.substr(front,back-front+1);
                if(s[i] =='('){
                    // cout << "FACTNAME: " << cur;
                    factName  =cur;
                    last = i+1;
                }
                if(s[i] == ','){
                    arglist.push_back(cur);
                    last = i+1;
                }
                if(s[i]==')'){
                    arglist.push_back(cur);
                    last = i+1;
                    m.insert({factName,arglist});
                    arglist.clear();
                }
            }
        }
    }
    while(true){
        getline(cin,s);
        if(s.length() == 0) break;
        int last = 0;
        string factName = "";
        vector<string> arglist;
        for(int i = 0; i < s.length(); i++){
            if(s[i] == '(' || s[i] == ',' || s[i] ==')'){
                string cur = s.substr(last,i-last);
                int front = 0;
                while(cur[front] == ' '){
                    front++;
                }
                int back = cur.length()-1;
                while(cur[back]==' '){
                    back--;
                }
                cur = cur.substr(front,back-front+1);
                if(s[i] =='('){
                    arglist.push_back(cur);
                    last = i+1;
                }
                if(s[i] == ','){
                    arglist.push_back(cur);
                    last = i+1;
                }
                if(s[i]==')'){
                    arglist.push_back(cur);
                    last = i+1;
                    queries.push_back(arglist);
                    arglist.clear();
                }
            }
        }
    }
}

bool checkOk(vector<string> a, vector<string> querie){
    if(a.size() != querie.size()-1) return false;
    unordered_map<string,string> checkString;
    for(int i = 0; i < a.size(); i++){
        if(querie[i+1].compare("_")==0){
            continue;
        }
        if(querie[i+1][0]!='_'){
            if(querie[i+1].compare(a[i]) != 0){
                return false;
            }
            continue;
        }
        if(checkString.count(querie[i+1]) ==0){
            checkString.insert({querie[i+1],a[i]});
            continue;
        }
        if(checkString[querie[i+1]].compare(a[i])!=0){
            return false;
        }
    }
    return true;
}

int main(){
    readInp();
    for(vector<string> q : queries){
        // for( string s:q){
        //     cout << s << " ";
        // }
        // cout << endl;
        int qlength = q.size();
        string varname = q[0];
        auto a = m.equal_range(varname);
        int ans = 0;
        for(auto i = a.first; i != a.second; i++){
            // cout << i->first << " ";
            // for(string s : i->second){
            //     cout << s << " ";
            // }
            // cout << endl;
            if(checkOk((i->second), q)){
                ans++;
            }
        }
        // cout << endl;
        cout << ans << endl;
    }
}