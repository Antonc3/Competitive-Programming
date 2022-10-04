#include <bits/stdc++.h>
using namespace std;
int weights[1005];
int main(){
    double T;
    int n;
    cin >> T >> n;
    for(int i = 0; i < n; i++){
        cin >> weights[i];
    }
    sort(weights, weights+n);
    int ans = 500;
    for(int i =0; i < 500; i++){
        int cuts = i;
        double fir = (double) weights[0]/(i+1);
        // cout << "FIRST PIECEE: " << fir<<endl;
        for(int j = 1; j < n; j++){
            double ncur = weights[j];
            int numcuts = 0;

            //fir is small
            // small/(big/cuts) > T
            double pieces = ncur/(numcuts+1);

            while(!((pieces/fir > T && pieces/fir <=1.0 ) ||
                (fir/pieces > T && fir/pieces <=1.0))){
                // cout << "fir/(ncur/(numcuts+1)) " << fir/(ncur/(numcuts+1))<<endl;
                numcuts++;
                pieces = ncur/(numcuts+1);
                if(pieces/fir<T){
                    break;
                }
            } 
            // cout << "NUM CUTS: " << numcuts<<endl;
            // cout << "PIECES: " << pieces << endl;
            // cout << "FIR/PIECES: "<< fir/pieces<<endl;
            // cout << "PIECES/FIR: "<<pieces/fir<<endl;
            if( !((pieces/fir > T && pieces/fir <=1.0 ) ||
                (fir/pieces > T && fir/pieces <=1.0)) || cuts > ans){
                cuts = 5000;
                break;
            }
            cuts+=numcuts;
        }
        ans = min(ans,cuts);
    }
    cout << ans << endl;
}