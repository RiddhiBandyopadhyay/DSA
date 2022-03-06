#include <bits/stdc++.h>
using namespace std;

double mult(double mid, double root)
{
    double ans = 1.0;
    for (int i = 0; i < root; i++)
    {
        ans = ans * mid;
    }
    return ans;
}

void solve(double num, double root)
{
    double low = 1;
    double high = num;
    double exp = 1e-6;
    while ((high - low) > exp)
    {
        double mid = (high + low) / 2.0;
        if (mult(mid, root) > num)
            high = mid;
        else
            low = mid;
    }
    cout << low << endl;
    // cout << pow(num,(1.0/root)); --> cross check
}

int main()
{
    double num, root;
    cin >> num >> root;
    solve(num, root);
    return 0;
}