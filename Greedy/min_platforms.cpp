#include <bits/stdc++.h>
using namespace std;

class Solution{

    public:
    int findPlatform(int arr[], int dep[], int n)
    {
    	sort(arr, arr + n);
    	sort(dep, dep + n);
    	
    	int plat_tillnow = 1;
    	int ans = 1;
    	
    	int i = 1, j = 0;
    	
    	while(i < n and j < n){
    	    if(arr[i] <= dep[j]){
    	        plat_tillnow++;
    	        i++;
    	        
    	        ans = max(ans, plat_tillnow);
    	    }
    	    else if(arr[i] > dep[j]){
    	        plat_tillnow--;
    	        j++;
    	    }
    	    
    	}
    	
    	return ans;
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}