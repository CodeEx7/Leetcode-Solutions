class Solution {
public:
    vector<int>parent;
    
    int find(int child){
        if(parent[child]==child) return child;      // if parent[child]==child means that it is parent of itself
        return parent[child]=find(parent[child]);   // using path compression technique
    }
    void union_f(int fir,int sec){
        int abs_fir= find(fir);
        int abs_sec=find(sec);
        
        if(abs_fir==abs_sec) return;
        else parent[abs_fir]=abs_sec;    // make second as parent of first 
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        iota(begin(parent),end(parent),0);
        for(auto it:equations){
            if(it[1]=='=') union_f(it[0]-'a',it[3]-'a');   // if = sign then make them in one group 
        }
        
        for(auto it:equations){
            if(it[1]=='!' and find(it[0]-'a')==find(it[3]-'a')) return false;  // if found in same group for != sign then false
        }
        return true;
    }
};