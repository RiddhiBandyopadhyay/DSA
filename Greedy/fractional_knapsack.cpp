#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

class Solution
{
public:
    static bool comparator(Item a, Item b)
    {
        double f1 = (double)a.value / (double)a.weight;
        double f2 = (double)b.value / (double)b.weight;

        return f1 > f2;
    }

    double fractionalKnapsack(int W, Item arr[], int n)
    {
        sort(arr, arr + n, comparator);
        int curW = 0;
        double maxVal = 0.0;

        for (int i = 0; i < n; i++)
        {
            if (curW + arr[i].weight <= W)
            {
                curW += arr[i].weight;
                maxVal += arr[i].value;
            }
            else
            {
                int rem = W - curW;
                maxVal += (double)arr[i].value / (double)arr[i].weight * (double)rem;
                break;
            }
        }

        return maxVal;
    }
};

int main()
{
    int t;
    cin >> t;
    cout << setprecision(2) << fixed;
    while (t--)
    {
        int n, W;
        cin >> n >> W;

        Item arr[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i].value >> arr[i].weight;
        }

        Solution ob;
        cout << ob.fractionalKnapsack(W, arr, n) << endl;
    }
    return 0;
}