#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;
typedef pair<int,pii>   node;


string s;
int n;

vector<int> t;
vector<int> o;
vector<int> c;

void build(int id =1, int l=0, int r=n){
	if(r-l < 2){
		if(s[l] == '('){
			o[id]=1;
		}
		else{
			c[id] = 1;
		}
	}
	int mid = (l+r)/2;
	build(2*id,l,mid);
	build(2*id+1,mid,r);
	int tmp = min(o[2*d],c[2*d+1]);
	t[id] = t[2*id]+t[2*id+1]+tmp;
	o[id] = o[2*id]+o[2*id+1]-tmp;
	c[id] = c[2*id]+c[2*id+1]-tmp;
}

int query(int l, int r)

int main(){
	string s;
	cin >> s;
	n = s.length();

}