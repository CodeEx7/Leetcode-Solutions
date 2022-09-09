class Solution {
public:
    //--------------------------------------------
    static bool mycomp(vector<int> &a, vector<int> &b){
        if(a[0]==b[0]){
            return a[1]>b[1];
        }
        return a[0]<b[0];
    }
    //---------------------------------------------
    int numberOfWeakCharacters(vector<vector<int>>& props) {
        sort(props.begin(), props.end(), mycomp);
        
        int cmp=INT_MIN, res=0;
        for(int i=props.size()-1;i>=0;i--){
            if(cmp>props[i][1]){
                res++;
            }
                cmp=max(cmp,props[i][1]);
        }
        return res;
    }
};