class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>mergeInterval;
        
        //If we have nothing in the 'merge' we will return empty mergeInterval
        if(intervals.size() == 0){
            return mergeInterval;
        }
        
        //sorting the 'intervals' to calculate the overlaping in one iteration
        sort(intervals.begin(), intervals.end());
        
        //storing the first pair of 'intervals' in 'tempInterval' 
        vector<int>tempInterval = intervals[0];
        
        //interating over 'intervals'
        for(auto it : intervals){
            if(it[0] <= tempInterval[1]){   //[[1,3],[2,6]....] checking if(2<3)
                tempInterval[1] = max(tempInterval[1], it[1]); //if yes, update 'tempInterval'
            }
            else{
                mergeInterval.push_back(tempInterval); //if no, push it into the ans vector 'mergeInterval' because it can no longer be merged (because 'intervals' is sorted)
                tempInterval = it; //updating 'tempInterval' to next pair, because the previous part is already merged completely
            }  
        }
        mergeInterval.push_back(tempInterval);
        return mergeInterval;
    }
};