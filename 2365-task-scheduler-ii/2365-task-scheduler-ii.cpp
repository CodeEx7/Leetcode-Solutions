class Solution {
public:
    long long taskSchedulerII(vector<int>& nums, int space) {
        long long day=0;
        unordered_map<int,long long int> mapp;
        for(int i=0;i<nums.size();i++){
            if(mapp.find(nums[i])==mapp.end()){
                day++;
                mapp[nums[i]]=day;
                //cout<<i<<" "<<day<<endl;
            }else{
                if(day-mapp[nums[i]]<space){
                    day+=space-(day-mapp[nums[i]])+1;
                    mapp[nums[i]]=day;
                    //cout<<i<<" "<<day<<endl;
                }else{
                    day++;
                    mapp[nums[i]]=day;
                    //cout<<i<<" "<<day<<endl;
                }
            }
        }
        
        return day;
    }
};