#include <iostream>

using namespace std;

int main(){
	int cases;
	for(int c = 0; c< cases; c++){
		int c1, c2;
		cin >> c1 >> c2;
		int cnts, cntw;
		cin >> cnts>>cntw;
		int wS, wW;
		cin >> wS >> wW;
		int max = 0;
		int minW, maxW;
		int minN, maxN;
		if(wS < wW){
			minW = wS;
			minN = cnts;
			maxW = wW;
			maxN = cntw;
		}else{
			maxW = wS;
			maxN = cnts;
			minW = wW;
			minN = cntw;
		}	
		if(c1/minW > minN){
			c1-=minN*minW;
			minN = 0;
			max+= minN;
			if(c1/maxW > maxN){
				c1-=maxN*maxW;
				max+=maxN;
			}
			else{
				max+=c1/maxW;
				maxW-=c1/maxW;
				if(c2/maxW > maxN){
					c2-=maxN*maxW;
					max+=maxN;
				}
				else{
					max+=c2/maxW;
					maxW-=c2/maxW;
					
				}
			}
		}
		else{
			
			max+= (c1/minW);
			minN-=(c1/minW);
			if(c2/minW > minN){
				c2-=minN*minW;
				max+=minN;
				if(c2/maxW > maxN){
					c2-=maxN*maxW;
					max+=maxN;
				}
				else{
					max+=c2/maxW;
					maxW-=c2/maxW;
					
				}			
			}
			else{
				max+=c2/minN;
				maxW-=c1/maxW;
				if(c2/maxW > maxN){
					c2-=maxN*maxW;
					max+=maxN;
				}
				else{
					max+=c2/maxW;
					maxW-=c2/maxW;
					
				}
			}
		}
		cout << max;
	}
}