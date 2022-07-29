class Solution {
public:
    //BFS function
    bool DFS(int s, vector<int> &color, vector<bool> &vis, vector<vector<int>> &graph, int col){
        if(col==0)
            col=1;
        else
            col=0;
        
        color[s]=col;
        
        vis[s]=true;
        
        for(auto u:graph[s]){
            if(vis[u]==false){
                if(DFS(u,color, vis, graph, col)==false){
                    return false;
                }
            }else if(color[u]==color[s]){
                return false;
            }
        }
        return true;
    }
    //main working functioon
    bool isBipartite(vector<vector<int>>& graph) {
        int V=graph.size();
        vector<int> color(V+1);
        vector<bool> vis(V+1, false);
        int col=0;
        
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                if(DFS(i, color, vis, graph, col)==false) return false;
            }
        }
        return true;
    }
};