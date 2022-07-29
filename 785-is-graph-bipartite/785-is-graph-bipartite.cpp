class Solution {
public:
    //BFS function
    bool BFS(int s, vector<int> &color, vector<bool> &vis, vector<vector<int>> &graph){
        queue<int> q;
        q.push(s);
        color[s]=0;
        vis[s]=true;
        
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v:graph[u]){
                if(vis[v]==false){
                    q.push(v);
                    vis[v]=true;
                    if(color[u]==0) color[v]=1;
                    else color[v]=0;
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
        vector<int> color(V+1);
        vector<bool> vis(V+1, false);
        
        for(int i=0;i<V;i++){
            if(vis[i]==false){
                if(BFS(i, color, vis, graph)==false) return false;
            }
        }
        return true;
    }
};