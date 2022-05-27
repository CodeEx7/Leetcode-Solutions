class Solution {
public:
    int numberOfSteps(int num) {
        if(num==0) return 0;
        int step=0;
        for(int i=1;i<=num;i=i*2){
            if((i&num)!=0)
                step+=2;
            else
                step+=1;
        }
        return step-1;
    }
};