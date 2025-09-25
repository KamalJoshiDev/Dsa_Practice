#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// * Brute Force

bool isConsecutive(vector<int> arr, int Num)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == Num)
            return true;
    }
    return false;
}

void LongConSeq(vector<int> arr)
{
    int Count;
    for (int i = 0; i < arr.size(); i++)
    {
        int Num = arr[i];
        Count = 1;
        while (isConsecutive(arr, Num + 1))
        {
            Num = Num + 1;
            Count++;
        }
    }
    cout << Count;
}

// * Better

int BetterSol(vector<int> arr)
{
    int Count = 0;
    int Longest = 1;
    int Mini = INT8_MIN;

    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (arr[i] - 1 == Mini)
        {
            Count++;
            Mini = arr[i];
        }
        else if (arr[i] != Mini)
        {
            Count = 1;
            Mini = arr[i];
        }
        Longest = max(Count, Longest);
    }

    return Longest;
}

int main()
{

    vector<int> arr = {102, 4, 100, 1, 101, 3, 2, 1, 1};
    // LongConSeq(arr);
    sort(arr.begin(), arr.end()); // ? You have To Sort The Array For Better Sol*
    int Result = BetterSol(arr);
    cout << Result;

    return 0;
}
