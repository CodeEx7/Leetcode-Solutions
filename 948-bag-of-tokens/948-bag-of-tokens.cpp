class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        if(tokens.size()==0) return 0;
        if(tokens.size()==1){
            if(power>tokens[0]){
                return 1;
            }else{
                return 0;
            }
        }
        sort(tokens.begin(), tokens.end());
        //--------------------
        int res=0, curr_power=0;
        int left=0, right=tokens.size()-1;
        if(tokens[left]<=power){
        while(left<=right){
            if(tokens[left]<=power){
                curr_power++;
                power-=tokens[left];
                cout<<power<<" ";
                left++;
                res=max(res, curr_power);
            }else if(tokens[left]>power && curr_power>=1){
                curr_power--;
                power+=tokens[right];
                cout<<power<<" ";
                right--;
            }
        }
        }
        return res;
    }
};