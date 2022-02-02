#include<bits/stdc++.h> 
using namespace std; 

class Solution
{
public:

    void solve(vector<int>&arr, int N, int ind, int sum, vector<int>&ans){
        if(ind == N){
            ans.push_back(sum);
            return;
        }
        
        //take
        solve(arr, N, ind+1, sum + arr[ind], ans);
        //no-take
        solve(arr, N, ind+1, sum, ans);
        
    }
    
    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int>ans;
        int ind = 0;
        int sum = 0;
        solve(arr, N, ind, sum, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}