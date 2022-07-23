#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

int romanToInt(string s) {
    map<char,int> hm = {{'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}};
    int res = 0;
    for(int i=0;i<s.length()-1;i++){
        if(s[i] == 'I' && (s[i+1] == 'V' || s[i+1] == 'X')){
            res-=1;
       }
        else if(s[i] == 'X' && (s[i+1] == 'L' || s[i+1] == 'C')){
            res-=10;
       }
        else if(s[i] == 'C' && (s[i+1] == 'D' || s[i+1] == 'M')){
            res-=100;
       }
        else res+= hm[s[i]];
    }
    res+=hm[s[s.length()-1]];
    return res;
}

int main(){
    cout << romanToInt("IVV");
    return 0;
}
