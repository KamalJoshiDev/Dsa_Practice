#include <iostream>
#include <vector>
using namespace std;

//? Brute
// ! Use Merge Sort

//?Better

vector<int> ColorSort_One(vector<int> arr)
{
    int cnt0 = 0, cnt1 = 0, cnt2 = 0;
    vector<int> res(arr.size(), -1);
    for (int i : arr)
    {
        if (i == 0)
        {
            cnt0++;
        }
        else if (i == 1)
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }

    for (int i = 0; i < cnt0; i++)
    {
        res[i] = 0;
    }
    for (int i = cnt0; i < cnt0 + cnt1; i++)
    {
        res[i] = 1;
    }
    for (int i = cnt0 + cnt1; i < arr.size(); i++)
    {
        res[i] = 2;
    }
    return res;
}

//? Optimal

void ColorSort_Two(vector<int> arr)
{
    int Start = 0, Mid = 0, End = arr.size() - 1;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] == 1)
        {
            Mid++;
        }
        else if (arr[i] == 2)
        {
            swap(arr[Mid], arr[End]);
            End--;
        }
        else
        {
            swap(arr[Start], arr[Mid]);
            Start++;
            Mid++;
        }
    }
}

int main()
{
    vector<int> arr = {1, 2, 0, 1, 2};
    // vector<int> res = ColorSort_One(arr);
    ColorSort_Two(arr);

    for (int &it : arr)
    {
        cout << it << " ";
    }
    return 0;
}