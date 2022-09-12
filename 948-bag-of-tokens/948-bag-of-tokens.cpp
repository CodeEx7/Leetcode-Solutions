class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        //--------------------
        int res=0, curr_power=0;
        int left=0, right=tokens.size()-1;
        while(left<=right){
            if(tokens[left]<=power){
                curr_power++;
                power-=tokens[left];
                left++;
                res=max(res, curr_power);
            }else if(curr_power>=1){
                curr_power--;
                power+=tokens[right];
                right--;
            }else{
                break;
            }
        }
        return res;
    }
};