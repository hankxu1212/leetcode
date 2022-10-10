#include<iostream>
#include<string>
#include<vector>
#include<algorithm> 
#include<unordered_map>
#include<map>
#include<stack>
#include<set>
#include<queue>
using namespace std;

vector<string> fullJustify(vector<string>& words, int maxWidth) {
	deque<string> dq;
	vector<string> res;
	int cl = 0;
	int cc = 0;
	for(auto &w : words){
		int l = w.length();
		if(l + cl == maxWidth){
			//last element
			string new_s = "";
			while(!dq.empty()){
				new_s += dq.front();
				new_s += " ";
				dq.pop_front();
			}
			new_s += w;
			while(new_s.length() < maxWidth)
				new_s += " ";
			res.push_back(new_s);

			cl = 0;
			cc = 0;
		}
		else if(l + cl < maxWidth){
			dq.push_back(w);
			cl += l + 1;
			cc ++;
		}
		else{
			//previous line
			int avg = 0;
			if(cc > 1) 
				avg = (maxWidth - cl + cc) / (cc - 1);
			int tmp = avg;
			string append = "";
			while(tmp > 0){
				append += " ";
				tmp--;
			}
			int leftover = maxWidth - (avg * (cc - 1) + cl - cc);
			string new_s = "";
			while(!dq.empty()){
				new_s += dq.front();
				dq.pop_front();
				if(!dq.empty())
					new_s += append;
				
				if(leftover > 0){
					new_s += " ";
					leftover --;
				}
				
			}
			res.push_back(new_s);
			while(new_s.length() < maxWidth)
				new_s += " ";
			//newline
			dq.push_back(w);
			cl = l + 1;
			cc = 1;
		}
	}
	int avg = 0;
	if(cc > 1) 
		int avg = (maxWidth - cl + cc) / (cc - 1);
	int tmp = avg;
	string append = "";
	while(tmp > 0){
		append += " ";
		tmp--;
	}
	int leftover = maxWidth - (avg * (cc - 1) + cl - cc);
	string new_s = "";
	while(!dq.empty()){
		new_s += dq.front();
		dq.pop_front();
		if(!dq.empty())
			new_s += append;
		
		if(leftover > 0){
			new_s += " ";
			leftover --;
		}
		
	}
	while(new_s.length() < maxWidth)
		new_s += " ";
	res.push_back(new_s);
	return res;
}

int main(){
	vector<string> words = {"What","must","be","acknowledgment","shall","be"};
	int maxWidth = 16;
	fullJustify(words,maxWidth);
	return 0;
}