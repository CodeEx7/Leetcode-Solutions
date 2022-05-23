class Solution {
public:
    void DFS(vector<vector<int>>& image, int sr, int sc, int newColor, int mainColor){
        int m=image.size(), n=image[0].size();
        if(sr<0 || sr>=m || sc<0 || sc>=n || image[sr][sc]!=mainColor) return;
        
        image[sr][sc]=newColor;
        
        DFS(image, sr+1, sc, newColor,mainColor);
        DFS(image, sr, sc+1, newColor,mainColor);
        DFS(image, sr-1, sc, newColor,mainColor);
        DFS(image, sr, sc-1, newColor,mainColor);
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int mainColor=image[sr][sc];
        if(mainColor!=newColor)
            DFS(image, sr, sc, newColor, mainColor);
        return image;
    }
};