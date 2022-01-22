class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) 
            return 0;
        int lcs = 0;
        set<int>hashSet;
        for(int num : nums){
            hashSet.insert(num);
        }
        
        for(int num : nums){
            if(!hashSet.count(num-1)){
                int curNum = num;
                int curLen = 1;
                
                while(hashSet.count(curNum + 1)){
                    curNum += 1;
                    curLen += 1;
                }
                
                lcs = max(lcs, curLen);
            }
        }
        
        return lcs;
    }
};