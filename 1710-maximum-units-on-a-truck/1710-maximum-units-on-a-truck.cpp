class Solution {
public:
    static bool mycmp(vector<int> &a, vector<int> &b){
        return a[1] > b[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), mycmp);
        int res=0;
        for(auto box:boxTypes){
            if(box[0]<=truckSize){
               res+=(box[0]*box[1]);
                truckSize-=box[0];
            } 
            else{
                res+=truckSize*box[1];
                truckSize=0;
            }
            if(truckSize==0) break;
        }
        
        return res;
    }
};