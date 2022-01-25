// { Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;

// A structure to represent a job
struct Job
{
    int id;     // Job Id
    int dead;   // Deadline of job
    int profit; // Profit if job is over before or on deadline
};

class Solution
{
public:
    static bool comparator(Job a, Job b)
    {
        return (a.profit > b.profit);
    }

    vector<int> JobScheduling(Job arr[], int n)
    {
        sort(arr, arr + n, comparator);

        int jobs = 0;
        int maxProfit = 0;

        int deadMax = arr[0].dead;
        for (int i = 0; i < n; i++)
        {
            deadMax = max(deadMax, arr[i].dead);
        }

        int slots[deadMax + 1];
        for (int i = 0; i < deadMax + 1; i++)
        {
            slots[i] = -1;
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = arr[i].dead; j > 0; j--)
            {
                if (slots[j] == -1)
                {
                    slots[j] = arr[i].id;
                    jobs++;
                    maxProfit += arr[i].profit;
                    break;
                }
            }
        }

        vector<int> ans;
        ans.push_back(jobs);
        ans.push_back(maxProfit);

        return ans;
    }
};

int main()
{
    int t;
    // testcases
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        Job arr[n];

        // adding id, deadline, profit
        for (int i = 0; i < n; i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }
        Solution obj;
        vector<int> ans = obj.JobScheduling(arr, n);
        cout << ans[0] << " " << ans[1] << endl;
    }
    return 0;
}