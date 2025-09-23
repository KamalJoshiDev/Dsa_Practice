#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> Leader(vector<int> arr)
{
    vector<int> res;
    int Maxi = INT8_MIN;
    for (int i = arr.size() - 1; i >= 0; i--)
    {
        if (arr[i] >= Maxi)
        {

            res.push_back(arr[i]);
            Maxi = arr[i];
        }
    }
    reverse(res.begin(), res.end());
    return res;
}

int main()
{
    vector<int> arr = {10, 22, 12, 3, 0, 6};
    vector<int> res = Leader(arr);
    for (auto &it : res)
    {
        cout << it << " ";
    }
    return 0;
}