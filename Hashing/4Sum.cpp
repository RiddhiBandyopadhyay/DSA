class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>>res;
        int n = nums.size();
        if(n == 0)
            return res;
        else{
            sort(nums.begin(), nums.end());
            for(int i=0;i<n-3;i++){
                for(int j=i+1;j<n-2;j++){
                    int left = j+1;
                    int right = n-1;
                    int target1 = target - nums[j] - nums[i];
                    
                    while(left < right){
                        int twoSum = nums[left] + nums[right];
                        
                        if(twoSum < target1)
                            left++;
                        else if(twoSum > target1)
                            right--;
                        else{
                            vector<int>quad(4,0);
                            quad[0] = nums[i];
                            quad[1] = nums[j];
                            quad[2] = nums[left];
                            quad[3] = nums[right];
                            res.push_back(quad);
                            
                            while(left < right and nums[left] == quad[2]) ++left;
                            while(left < right and nums[right] == quad[3]) --right;

                        }
                    }
                    
                    while(j+1 < n and nums[j+1] == nums[j]) ++j;
                    
                }
                
                while(i+1 < n and nums[i+1] == nums[i]) ++i; 
            }
        }
        
        return res;
    }
};