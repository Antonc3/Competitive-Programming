#include <bits/stdc++.h>
using namespace std;
#define MAXN 10005
int n;
int main(){
	int n;
	cin >> n;
	int scnd = 0;
	bool first = true;
	int l = 1;
	int r = n;
	bool askleft = false;
	while(l< r){
		if(r-l == 1){
			if(scnd == l){
				l = r;
			}
			else{
				r  = l;
			}
		}
		if(first){
			cout << "? " << l << " " << r<<"\n";
			cout.flush();
			cin >> scnd;
			first = false;
			int mid = (l+r)/2;
			if(scnd > mid){
				askleft = false;
			}
			else{
				askleft = true;
			}
			// if(r-l == 1){
			// 	if(scnd == l){
			// 		l = r;
			// 	}
			// 	else{
			// 		r  = l;
			// 	}
			// }
			continue;
		}
		if(askleft){
			int mid = (l+r)/2;
			cout << "? " << l << " " << mid << "\n";
			cout.flush();
			int x;
			cin >> x;
			if(mid == scnd){
				if(x==scnd){
					r = mid-1;
					first = true;
				}
				else{
					l = mid+1;
					first = true;
				}
				continue;
			}
			if(x == scnd){
				r = mid;
				int mid2 = (l+r)/2;
				if(scnd > mid2){
					askleft = false;
				}
				else{
					askleft = true;
				}
			}
			else{
				first = true;
				l= mid+1;
			}
		}
		else{
			int mid = (l+r)/2;
			cout << "? " << mid << " " << r << "\n";
			cout.flush();
			int x;
			cin >> x;
			if(x == scnd){
				l = mid;
				int mid2 = (l+r)/2;
				if(scnd > mid2){
					askleft = false;
				}
				else{
					askleft = true;
				}
			}
			else{
				first = true;
				r= mid-1;
			}
		}
		// int mid = (l+r)/2;
		// int x;
		// cin >> x;
		// if(x == scnd){
		// 	l = scnd+1;
		// 	first = true;
		// }
		// else{
		// 	r = scnd-1;
		// 	first = true;
		// }
	}
	cout<< "! " <<l;
}
// if(askleft){
// 			cout << "? " << l << " " << il << "\n";
// 			int x;
// 			cin >> x;
// 			if(x != scnd){
// 				r = il;
// 				il = (l+r)/2;
// 				askleft = false;
// 			}
// 			else{
// 				l = il;
// 				il = (l+r)/2;
// 				askleft = true;
// 			}
// 		}
// 		else{
// 			cout << "? " << il << " " << r << "\n";
// 			cout.flush();
// 			int x;
// 			cin >> x;
// 			if(first){
// 				scnd = x;
// 				first = false;
// 				il = (l+r)/2;
// 				continue;
// 			}
// 			if(x != scnd){
// 				r = il;
// 				il = (l+r)/2;
// 				askleft = false;
// 			}
// 			else{
// 				l = il;
// 				il = (l+r)/2;
// 				askleft = true;
// 			}
// 		}