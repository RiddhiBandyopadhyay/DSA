#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        unordered_map<int,int>mpp;
        int sum = 0, max_len = 0;
        for(int i=0;i<A.size();i++){
            sum += A[i];
            
            if(sum == 0)
                max_len = i+1;
            else{
                if(mpp.find(sum) != mpp.end()){
                    max_len = max(max_len, i - mpp[sum]);
                }
                else{
                    mpp[sum] = i;
                }
            }
        }
        return max_len;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i){
            cin>>array1[i];
        }
        Solution ob;
        cout<<ob.maxLen(array1,m)<<endl;
    }
    return 0; 
}