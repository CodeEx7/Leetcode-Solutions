/*
                    h( AAB , -1 , 0 )              LEVEL=0 ie 0 length substring
                    /               \
            h('A'AB,0,1)           h('B'AA,6,1)    LEVEL=1 ie 1 length substrings ("A","B")
            /         \              /
        h('AA'B,1,2) h('AB'A,4,2) h('BA'A,7,2)     LEVEL=2 ie 2 length substrings ("AB","BA","AA")
        /            /             /
    h('AAB',2,3)    h('ABA',5,2)  h('BAA',8,3)     LEVEL=3 ie 3 length substrings 
                                                   ("AAB", "ABA", "BAA")
*/

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