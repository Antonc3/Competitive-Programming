#include <iostream>
#include <queue>

using namespace std;


int main(){
	int N, K;
	string s;
	string pattern
	cin >> N >> K >> s >>pattern;
	int behind = 0;
	priority_queue<pair<int, int>> pq;
	for(int i = N-1; N >= 0; N--){
		if(s[i] == pattern[0]){
		 	pq.push({i+i-N+1,1+i*10});
		}
		else if(s[i] == pattern[1]){
			pq.push({N-1-i-i,0+i*10});
		}
		else{
			pq.push({N-1-i,1+i*10});
			pq.push({i,0+i*10});
		}
	}
	for(int i = 0; i < K; i++){
		pair<int, int> top = pq.top();
		pq.pop();
		if(top.second%10 == 0){
			s[top.second/10] = pattern[0];
		}
		else{
			s[top.second/10] = pattern[1];
		}
	}
	int ans = 0;
	int front = 0;
	for(int i = 0; i < N; i++){
		if(s[i] == pattern[0]){
			front++;
		}
		else if(s[i] == pattern[1]){
			ans+= front;
		}
	}
	cout << ans;
}