class Solution {
public:
    //compare function
    static bool mycmp(vector<int> &a, vector<int> &b){
        if(a[0]!=b[0]) return a[0]<b[0];
        
        return a[1]<b[1];
    }
    //main working function
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), mycmp);
        
        for(auto it:intervals){
            cout<<it[0]<<" "<<it[1]<<"  ";
        }
        
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0] < intervals[i-1][1]){
                return false;
            }
        }
        return true;
    }
};