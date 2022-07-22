#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

double bisearch(vector<int>& Long, vector<int>& Short){
    int total = Long.size() + Short.size();
    int half = total/2;
    int l = 0;
    int r = Short.size();

    while(true){
        int Si = (l+r)/2;
        int Li = (total + 1)/2-Si;
        int left1,left2,right1,right2;

        if(Si == 0) left1 = INT_MIN; else left1 = Short[Si-1];
        if(Li == 0) left2 = INT_MIN; else left2 = Long[Li-1];
        if(Si == Short.size()) right1 = INT_MAX; else right1 = Short[Si];
        if(Li == Long.size()) right2 = INT_MAX; else right2 = Long[Li];

        if(left1<=right2 && left2<=right1){
            if(total%2==0) return (max(left1,left2)+min(right1,right2))/2.0;   // in this case the median can be found out by adding the for even and odd no of total elements.
            else return max(left1,left2);
        }
        if(left1>right2)
            r = Si - 1;
        else 
            l = Si + 1;
    }
    return 0.0;
}

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if(nums1.size() > nums2.size())
        return bisearch(nums1,nums2);
    return bisearch(nums2,nums1);
}

int main(){
    vector<int> v1 = {1,3};
    vector<int> v2 = {2};
    cout << findMedianSortedArrays(v1,v2);
    return 0;
}