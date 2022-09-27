class Solution {
public:
    string pushDominoes(string dominoes) {
        int n=dominoes.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        int time=1;
        char prev='.';
        for(int i=0;i<n;i++){
            if(dominoes[i]=='R'){
                prev='R';
                time=1;
                continue;
            }else if(dominoes[i]=='L'){
                prev='L';
            }else if(prev=='R' && dominoes[i]=='.'){
                right[i]=time;
                time++;
            }
        }
        
        time=1;
        prev='.';
        for(int i=n-1;i>=0;i--){
            if(dominoes[i]=='L'){
                prev='L';
                time=1;
                continue;
            }else if(dominoes[i]=='R'){
                prev='R';
            }else if(prev=='L' && dominoes[i]=='.'){
                left[i]=time;
                time++;
            }
        }
        string res="";
        for(int i=0;i<n;i++){
            if(left[i]==0 && right[i]==0){
                res+=dominoes[i];
            }else if(left[i]==right[i]){
                res+='.';
            }else if(left[i]==0 && right[i]){
                res+='R';
            }else if(left[i] && right[i]==0){
                res+='L';
            }else if(left[i]<right[i]){
                res+='L';
            }else if(left[i]>right[i]){
                res+='R';
            }
        }
        return res;
    }
};