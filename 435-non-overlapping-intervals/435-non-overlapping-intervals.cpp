class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if(intervals.size()==1) return 0;
        
        sort(intervals.begin(), intervals.end());
        
        int n=intervals.size();
        
        //---------------------
       int prevEnd= intervals[0][1], ans=0;
        
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=prevEnd){
                prevEnd = intervals[i][1];
            }else{ // Overlapping case : 1 interval has to be removed so remove the one with less end point as it will have less chances of overlapping with further intervals
                ans ++;
                if(intervals[i][1]<prevEnd){    
                    prevEnd = intervals[i][1];  // Removal taken care by just updating prev End point to one which is smaller in their 2 possible cases
                }
            }
        }
        
        return ans;
    }
};