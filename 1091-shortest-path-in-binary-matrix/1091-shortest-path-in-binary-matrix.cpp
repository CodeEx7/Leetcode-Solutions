struct Point{
    int x;
    int y;
    int cnt;
};

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int row=grid.size();
        int col=grid[0].size();
        //edge case
        if(grid[0][0]==1) return -1;
        
        queue<Point> q;
        q.push({0,0,1});
        
        grid[0][0]=-1;
        
        pair<int, int> dirs[8]={{1,0}, {-1,0}, {0,1}, {0,-1}, {1,1}, {1,-1}, {-1,1}, {-1,-1}};
        while(!q.empty()){
           Point p=q.front();
            q.pop();
            
            if(p.x==row-1 && p.y==col-1) return p.cnt;
            
            for(auto dir:dirs){
                int nx=p.x+dir.first;
                int ny=p.y+dir.second;
                
                if(nx>=0 && ny>=0 && nx<row && ny<col && grid[nx][ny]==0){
                    q.push({nx,ny,p.cnt+1});
                    grid[nx][ny]=-1;
                }
            }
        }
        return -1;
    }
};