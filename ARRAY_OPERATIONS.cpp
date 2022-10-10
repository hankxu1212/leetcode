#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <ctype.h>
#include <math.h>
#include <set>
#include <stack>
#include <bitset>
using namespace std;

//print2D
void print2D(vector<vector<int>> v){
    cout << '[';
    for(auto &x : v){
        cout << '[';
        for(auto &e : x){
            cout << e << ' ';
        }
        cout << ']';
    }
    cout << ']' << '\n';
}

//to Distinct vectors
//converts to a set first then dump back
vector<int> toDistinct(vector<int> vec){
    set<int> s( vec.begin(), vec.end() );
    vec.assign( s.begin(), s.end() );
    return vec;
}

//removes 'val'
void removeElement(vector<int>& v, int val) {
    //erase-remove idiom
    v.erase(std::remove(v.begin(), v.end(), val), v.end());
}

//returns {i,j} such that i is the first occurance of target and j is the last
vector<int> search(vector<int>& nums, int x, int i, int j){
    while(i <= j){
        int mid = i+(j-i)/2;
        if(nums[mid] == x){
            vector<int> left = search(nums, x, i, mid-1);
            vector<int> right = search(nums, x, mid +1, j);
            if(left[0] == -1 && left[1] == -1 && right[0] == -1 && right[1] == -1) 
                return {mid, mid};
            else if(left[0] == -1 && left[1] == -1) 
                return {mid, right[1]};
            else if(right[0] == -1 && right[1] == -1)
                return {left[0], mid};
            return {left[0], right[1]};
        }
        if(nums[mid] < x){
            return search(nums, x, mid +1, j);
        }
        else{
            return search(nums, x, i, mid -1);
        }
    }
    return {-1,-1};
}
vector<int> searchRange(vector<int>& nums, int target) {
    return search(nums, target, 0, nums.size() - 1);    
}

//unique permutations (if contains duplicates)
vector<vector<int>> permute(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    vector<vector<int>>v;
    do{
        v.push_back(nums);
    }
    while(next_permutation(nums.begin(),nums.end()));
    return v;
}

//merge intervals
vector<vector<int>> merge(vector<vector<int>> &intervals){
    sort(intervals.begin(), intervals.end());
    stack<vector<int>> s;
    vector<vector<int>> res;
    for(auto &elem : intervals){
        if(s.empty()) 
            s.push(elem);
        else if(elem[0] > s.top()[1]){
            res.push_back(s.top());
            s.pop();
            s.push(elem);
        }
        else if(elem[1] <= s.top()[1]){
            continue;
        }
        else{
            s.top()[1] = elem[1];
        }
    }
    res.push_back(s.top());
    return res;
}

//powerset (cascading approach)
vector<vector<int>> powerSet(vector<int>& nums) {
    vector<vector<int>> res = {{}};
    for(int i=0;i<nums.size();i++){
        int k = res.size();
        for(int j=0;j<k;j++){
            vector<int> new_sol(res[j]);
            new_sol.push_back(nums[i]);
            res.push_back(new_sol);
        }
    }
    return res;
}

//powerset (bitmask approach)
vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res = {};
    int n = nums.size();
    for(int i = 0; i < pow(2,n); ++i){
        //creates bitmask with length = 32
        //i : integer
        string bitmask = bitset<32>(i).to_string();
        cout << bitmask << '\n';
        vector<int> new_sol;
        for(int i=0;i < n;i++){
            int index = 32 - n + i;
            if(bitmask[index] == '1')
                new_sol.push_back(nums[i]);
        }
        res.push_back(new_sol);
    }
    return res;
}

//return next/prev small element for heights at each index
//invariant : height[st[i]] > height[st[j]] for all i > j
//            or st is the indices of height sorted in increasing order 
//                          (decreasing order from top of the stack) with respect to height
vector<int> nextsmall(vector<int> heights,int n){
    vector<int> res(n);
    stack<int> st;
    
    for(int i=n-1; i>=0; i--){
        while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
        if(st.empty())
            res[i] = -1;
        else
            res[i] = st.top();
        st.push(i);
    }
    return res;
    
}
vector<int> prevsmall(vector<int> heights,int n){
    vector<int> res(n);
    stack<int> st;
    
    for(int i=0; i<n; i++){
        while(!st.empty() && heights[st.top()]>=heights[i])
            st.pop();
        if(st.empty())
            res[i] = -1;
        else
            res[i] = st.top();
        st.push(i);
    }
    return res;   
}

vector<pair<int,int>> zip(vector<int> v){
    vector<pair<int,int>> res(v.size());
    for(int i=0;i<v.size();i++){
        res[i] = {v[i],i};
    }
    return res;
}

int main(){
    vector<int> v = {10,10,8,7,6,5};
    nextsmall(v, v.size());
}