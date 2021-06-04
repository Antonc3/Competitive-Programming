#include <iostream>
#include <stack>

using namespace std;

int main(){
	int t;
	cin >> t;
	while(t--){
		int N;
		string s;
		cin >> N >> s;
		int ans[N];
		int newNum = 0;
		stack<int> last0;
		stack<int> last1;
		for(int i = 0; i < N; i++){
			if(s[i] == '0'){
				if(last1.empty()){
					newNum++;
					ans[i] = newNum;
				}
				else{
					int a = last1.top();
					last1.pop();
					ans[i] = a;
				}
				last0.push(ans[i]);
			}
			else{
				if(last0.empty()){
					newNum++;
					ans[i] = newNum;
				}
				else{
					int a = last0.top();
					last0.pop();
					ans[i] = a;
				}
				last1.push(ans[i]);
			}
		}
		cout << newNum <<endl;
		for(int i = 0; i < N; i++){
			cout << ans[i]<< " ";
		}
		cout << endl;
	}
}