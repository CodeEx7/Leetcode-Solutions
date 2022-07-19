class Solution {
public:
    //helper function
    void helper(string tiles, int level, int &cnt){
        cnt++;
        for(int i=level;i<tiles.size(); i++){
            if(i!=level && tiles[i]==tiles[level])
                continue;
            swap(tiles[i], tiles[level]);
            helper(tiles, level+1, cnt);
        }
        
    }
    //main working function
    int numTilePossibilities(string tiles) {
        int cnt=-1;
        sort(tiles.begin(), tiles.end());
        helper(tiles,0,cnt);
        return cnt;
    }
};