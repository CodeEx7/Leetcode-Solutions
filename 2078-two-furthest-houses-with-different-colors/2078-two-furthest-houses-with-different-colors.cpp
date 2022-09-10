class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int left=0, right=colors.size()-1, res=0;
        while(left<right){
            if(colors[left]!=colors[right]){
                res=max(res, right-left);
            }
            right--;
        }
        
        left=0, right=colors.size()-1;
        
        while(left<right){
            if(colors[left]!=colors[right]){
                res=max(res, right-left);
            }
            left++;
        }
       return res; 
    }
};