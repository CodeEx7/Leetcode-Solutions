class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) { //(3,3,3,2,5)
        if(nums.size()<=1) return 1;
        int res;
        int prev=nums[1]-nums[0]; //prev=0
        if(prev==0){
            res=1; //sjdgwelkfjhk
        }else{
            res=2;
        }
        for(int i=2;i<nums.size();i++){ //nums[5]=5
            int diff=nums[i]-nums[i-1]; //diff=3
            if((diff>0 && prev<=0) || (diff<0 && prev>=0)){ 
                res++; //res=3
                prev=diff; //prev=3
            }
        }
        return res;
    }
};

//O(n)
//O(1)