#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <map>
using namespace std;

//converts integer to vector
vector <int> integerToVec(int x)
{
    vector <int> resultArray;
    while (true)
    {
        resultArray.insert(resultArray.begin(), x%10);
        x /= 10;
        if(x == 0)
            return resultArray;
    }
}

//converts vector to integer
int vecToInt(vector<int> v)
{
    reverse(v.begin(), v.end());
    int decimal = 1;
    int total = 0;
    for (auto& it : v)
    {
        total += it * decimal;
        decimal *= 10;
    }
    return total;
}

//converts vec to long long
long long vecToLL(vector<int> v)
{
    reverse(v.begin(), v.end());
    long long decimal = 1;
    long long total = 0;
    for (auto& it : v)
    {
        total += it * decimal;
        decimal *= 10;
    }
    return total;
}