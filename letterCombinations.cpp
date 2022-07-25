#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;
map<char,string> hm = {{'2', "abc"}, {'3', "def"}, {'4', "ghi"}, 
{'5', "jkl"}, {'6', "mno"}, {'7', "pqrs"},
{'8', "tuv"}, {'9', "wxyz"}};

vector<string> comb(string digits, vector<string> curr){
	if(digits == ""){
		return curr;
	}
	if(digits.length() == 1){
		for(int j = 0; j < hm[digits[0]].length(); j++){
		    curr.push_back(hm[digits[0]].substr(j,1));
	    }
	}
	else{
		curr = comb(digits.substr(1), curr);
		int n = curr.size();
		for(int i = 0; i < n; i++){
			for(int j = 0; j < hm[digits[0]].length(); j++){
				curr.push_back(hm[digits[0]][j] + curr[i]);
			}
		}
		curr.erase(curr.begin(), curr.begin() + n);
	}
	return curr;
}

vector<string> letterCombinations(string digits){
	vector<string> res;
	return comb(digits, res);
}

