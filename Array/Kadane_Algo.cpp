#include <iostream>
#include <vector>
using namespace std;
//? Brute

void MaxSubArraySum(vector<int> res)
{
    int n = res.size();
    int maxsum = res[0]; // {2, 4, -6, 8, -2, -12, 4};

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            int sum = 0;

            for (int k = i; k <= j; k++)
            {
                sum += res[k];
            }
            maxsum = max(maxsum, sum);
        }
    }

    cout << maxsum;
}

//? Better

void MaxSubArraySum_Two(vector<int> res)
{
    int n = res.size();
    int maxsum = res[0];
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = i; j < n; j++)
        {

            sum += res[j];
            maxsum = max(maxsum, sum);
        }
    }

    cout << maxsum;
}

//? Optimal ( Kadane Algo )

void MaxSubArraySum_Three(vector<int> res)
{
    int n = res.size();
    int maxsum = res[0];
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += res[i];
        if (sum > maxsum)

        {
            maxsum = sum;
        }
        if (sum < 0) // ! Don't Carry Neg Value
            sum = 0;
    }

    cout << maxsum;
}

//? Varaition

void MaxSubArraySum_Index(vector<int> res)
{
    int n = res.size();
    int maxsum = res[0];
    int sum = 0;
    int start = 0, ansStart = -1, ansEnd = -1;

    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
            start = i;
        sum += res[i];
        if (sum > maxsum)

        {
            maxsum = sum;
            ansStart = start;
            ansEnd = i;
        }
        if (sum < 0) // ! Don't Carry Neg Value
            sum = 0;
    }

    cout << maxsum << "Start With Index Of : " << ansStart << " To " << ansEnd;
}

int main()
{

    vector<int> res = {2, 4, -6, 8, -2, -12, 4};
    MaxSubArraySum_Index(res);
    return 0;
}