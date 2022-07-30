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