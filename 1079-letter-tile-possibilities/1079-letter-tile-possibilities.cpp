class Solution {
public:
    //helper function
    void helper(string tiles, int idx, int &cnt){
        cnt++;
        for(int i=idx;i<tiles.size(); i++){
            if(i!=idx && tiles[i]==tiles[idx])
                continue;   // to skip same characters
            swap(tiles[i], tiles[idx]);
            helper(tiles, idx+1, cnt);
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