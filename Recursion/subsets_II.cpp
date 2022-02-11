#include <bits/stdc++.h>
using namespace std;

void solve(int ind, vector<int> &nums, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    for (int i = ind; i < nums.size(); i++)
    {
        if (i != ind and nums[i] == nums[i - 1])
            continue;
        ds.push_back(nums[i]);
        solve(i + 1, nums, ds, ans);
        ds.pop_back();
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    for (int i = 0; i < n; i++)
    {
        int el;
        cin >> el;
        vec.push_back(el);
    }

    vector<vector<int>> ans;
    vector<int> ds;
    sort(vec.begin(), vec.end());
    int ind = 0;
    solve(ind, vec, ds, ans);
    return 0;
}