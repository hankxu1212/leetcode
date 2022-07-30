#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
#include <ctype.h>
#include <math.h>
using namespace std;

//string to integer
int atoi(string input) {
    int sign = 1; 
    int result = 0; 
    int index = 0;
    int n = input.size();
    
    while (index < n && input[index] == ' ') { 
        index++; 
    }
    
    if (index < n && input[index] == '+') {
        sign = 1;
        index++;
    } else if (index < n && input[index] == '-') {
        sign = -1;
        index++;
    }
    
    while (index < n && isdigit(input[index])) {
        int digit = input[index] - '0';

        if ((result > INT_MAX / 10) || (result == INT_MAX / 10 && digit > INT_MAX % 10)) {   
            return sign == 1 ? INT_MAX : INT_MIN;
        }
        
        result = 10 * result + digit;
        index++;
    }
    
    return sign * result;
}

// returns count of non-overlapping occurrences of 'sub' in 'str'
int countSubstring(const std::string& str, const std::string& sub)
{
    if (sub.length() == 0) return 0;
    int count = 0;
    for (size_t offset = str.find(sub); offset != std::string::npos;
     offset = str.find(sub, offset + sub.length()))
    {
        ++count;
    }
    return count;
}