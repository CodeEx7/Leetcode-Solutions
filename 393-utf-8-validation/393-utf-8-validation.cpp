class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int remBytes=0;
        for(auto it:data){
            if(remBytes==0){
                if((it>>5)==0b110){
                    remBytes=1;
                }else if((it>>4)==0b1110){
                    remBytes=2;
                }else if((it>>3)==0b11110){
                    remBytes=3;
                }else if((it>>7)!=0){ 
                    return false;
                }
            }else{
                if((it>>6)==0b10){
                    remBytes--;
                }else{
                    return false;
                }
            }
        }
        return remBytes==0;
    }
};