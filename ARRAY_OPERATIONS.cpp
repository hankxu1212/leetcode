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

//converts to a set first then dump back
vector<int> toDistinct(vector<int> vec){
    set<int> s( vec.begin(), vec.end() );
    vec.assign( s.begin(), s.end() );
    return vec;
}

void removeElement(vector<int>& v, int val) {
    //erase-remove idiom
    v.erase(std::remove(v.begin(), v.end(), val), v.end());
}

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

int main(){
    vector<int> v = {5,7,7,8,8,10};
    searchRange(v, 8);
}