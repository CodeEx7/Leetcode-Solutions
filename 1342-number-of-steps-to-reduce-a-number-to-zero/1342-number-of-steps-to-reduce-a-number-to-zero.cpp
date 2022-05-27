class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0) return 0;
        int step=0;
        while(num>0){
            if((num&1) != 1){
                num=num>>1;;
            }else{
                num-=1;
            }
            step++;
        }
        return step;
    }
};