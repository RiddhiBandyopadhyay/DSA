//TC : O(N)
//SC : O(N)

class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int sum = 0;
        vector<int> maxL(n);
        vector<int> maxR(n);
        vector<int> water(n);
        
        maxL[0] = height[0];
        for(int i = 1 ; i < n ; i++){
            maxL[i] = max(maxL[i-1], height[i]);
        }
        
        maxR[n-1] = height[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            maxR[i] = max(maxR[i+1],height[i]);
        }
        
        for(int i = 0 ; i < n ; i++){
            water[i] = min(maxL[i], maxR[i]) - height[i];
        }
        
        for(int i = 0 ; i < n ; i++){
            sum += water[i];
        }
        
        return sum;
    }
};

//TC : O(N)
//SC : O(1)

class Solution {
public:
    int trap(vector<int>& a) {
        int n = a.size();
        int l = 0 ,r = n-1;
        int maxL = 0, maxR = 0;
        int res = 0;
        
        while(l <= r){
            if(a[l] <= a[r]){
                if(a[l] >= maxL) maxL = a[l];
                else res += maxL - a[l];
                l++;
            }
            else{
                if(a[r] >= maxR) maxR = a[r];
                else res += maxR - a[r];
                r--;
            }
        }
        return res;
    }
};