#include <iostream>
#include <string>
#include <stack>
#include <map>

using namespace std;

int solution(string S) {
  int cnt = 0;
  map<string,int> mp = {{"a",0},{"b",1},{"c",2},
                        {"aa",2},{"ac",1},{"ab",0},
                        {"ba",1},{"bb",2},{"bc",0},
                        {"ca",0},{"cb",1},{"cc",2}};
  cnt += mp[S.substr(0,1)];
  for(int i=1;i<S.length();i++){
    cnt += mp[""+ S[i-1] + S[i]];
  }
  return cnt;
}



int main(){
    return solution("ccccccc");
}