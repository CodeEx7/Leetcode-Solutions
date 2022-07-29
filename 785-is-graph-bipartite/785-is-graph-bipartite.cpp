class Solution {
public:
    //BFS function
    bool BFS(int s, vector<int> &color, vector<vector<int>> &graph){
        queue<int> q;
        q.push(s);
        color[s]=1;
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:graph[u]){
                if(color[v]==-1){
                    q.push(v);
                    color[v]=1-color[u];
                } else if(color[v]==color[u]){
                    return false;
                }
            }
        }
        return true;
    }
    //main working functioon
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V+1, -1);
        
        for(int i=0;i<V;i++){
            if(color[i]==-1){
                if(BFS(i, color, graph)==false) return false;
            }
        }
        return true;
    }
};