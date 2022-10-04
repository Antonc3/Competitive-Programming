#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    bool pos = true;

    for(int i = 0; i < n; i++){
        string s;
        getline(cin,s);
        int vowel =0;
        char vowels[] = {'a','e','i','o','u','y'};
        cout <<
        "S: "<< s << endl;
        for(int j =0; j < s.size(); j++){
            for(char c : vowels){
                if(s[j] == c){
                    vowel++;
                }
            }
        }
        cout << "VOWEL" << vowel <<endl;
        if(vowel < arr[i]){
            pos = false;
        }
    }
    if(pos){
        cout << "YES";
    }
    else{
        cout << "NO";
    }
}