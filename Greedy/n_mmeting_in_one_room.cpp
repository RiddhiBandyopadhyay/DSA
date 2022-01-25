#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int, int>> meet;
        for(int i=0;i<n;i++){
            meet.push_back(make_pair(end[i], start[i]));
        }
        
        sort(meet.begin(), meet.end());
        
        int count = 1;
        int limit = meet[0].first;
        
        for(int i=1;i<n;i++){
            if(meet[i].second > limit){
                count++;
                limit = meet[i].first;
            }
        }
       return count; 
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        Solution ob;
        int ans = ob.maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
} 