#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <ctype.h>
#include <math.h>
using namespace std;

int find_next_unmatched(string s,  int k){
	int count = 0;
	for(int i=k; i < s.length(); i++){
		if(s[i] == '[') count ++;
		if(s[i] == ']') count --;
		if(count < 0) return i;
    }
    return -1;
}

//REQUIRES: s[0] : int
int find_int(string s){
	for(int i=0;i<s.length();i++){
		if(!(s[i] >= '0' && s[i] <= '9')) return i;
	}
    return -1;
}

//REQUIRES: end is the last index that we have decoded
string decodeString(string s){
    if(s.length() == 1) return s.substr(0,1);
	if (s == "") return "";
	if (s[0] >= 'a') return s[0] + decodeString(s.substr(1));
	else{
		int j = find_int(s);
		int multi_factor = stoi(s.substr(0,j));
		int next_unmatched = find_next_unmatched(s, j+1);
		string decoded = decodeString(s.substr(j+1, next_unmatched - j - 1));
		string res = "";
        for(int i=0;i<multi_factor;i++){
			res += decoded;
        }
        return res + decodeString(s.substr(next_unmatched+1));
    }
}

int main(){
	string r = decodeString("3[a]2[bc]");
	cout << r << " ";
	return 0;
}
