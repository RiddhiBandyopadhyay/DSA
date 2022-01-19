//Brute force : Using visited vector(hashing)
//TC : O(N)
//SC : O(N)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int N = 1e6+2;
        vector<int> vis(N,0);
        for(int i = 0; i < nums.size(); i++){
            if(vis[nums[i]] == 0){
                vis[nums[i]] = 1;
            }
            else if(vis[nums[i]] != 0){
                return nums[i];
            }
        }
        return -1;
    }
};


//Optimal : Linked-list cycle method
//TC : O(N)
//SC : O(N)

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];
        
        do{
            slow = nums[slow];
            fast = nums[nums[fast]];
        }while(slow != fast);   
       
        fast = nums[0];
        
        while(fast != slow){
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};

