#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include <math.h>
#include <set>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums){

}

int main(){
	vector<int> vec = {-1,0,1,2,-1,-4};
	vector<vector<int>> v = threeSum(vec);
	for(auto &i:v){
		for(auto &j : i){
			cout << j << " ";
		}
		cout << '\n';
	}
	return 0;
}