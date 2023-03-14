#include <bits/stdc++.h>

using namespace std;
const int N = 1e3 + 5;

string s;

void inp(){
    cin >> s;
}

int res = 0;
char open[4] = {'(', '{', '[', '<'};
map<char, char> c;

void dfs(int pos, vector<char> &st){
    if((int)st.size() > (int)s.size() - pos)
        return;
    if(pos == (int)s.size()){
        if(st.empty())
            ++res;
        return;
    }
    if(s[pos] == '(' || s[pos] == '[' || s[pos] == '{' || s[pos] == '<'){
        st.push_back(s[pos]);
        dfs(pos + 1, st);
        st.pop_back();
    }
    else if(s[pos] == ')' || s[pos] == ']' || s[pos] == '}' || s[pos] == '>'){
        if(st.empty())
            return;
        if(st.back() == c[s[pos]]){
            st.pop_back();
            dfs(pos + 1, st);
            st.push_back(c[s[pos]]);
        }
        else return;
    }
    else{
        for(int i = 0; i < 4; ++i){
            st.push_back(open[i]);
            dfs(pos + 1, st);
            st.pop_back();
        }
        for(int i = 0; i < 4; ++i){
            if(!st.empty() && st.back() == open[i]){
                st.pop_back();
                dfs(pos + 1, st);
                st.push_back(open[i]);
            }
        }
    }
}

void process(){
    vector<char> empty;
    c[')'] = '(';
    c['}'] = '{';
    c[']'] = '[';
    c['>'] = '<';
    dfs(0, empty);
    cout << res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    inp();
    process();
}
