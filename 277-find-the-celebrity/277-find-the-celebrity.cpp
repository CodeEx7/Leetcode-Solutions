/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    //checking if it is really a celeb or not
    bool isceleb(int i, int n){
        for(int j=0;j<n;j++){
            if(i!=j){
                if(knows(i,j) || !knows(j,i))
                    return false;
            }
        }
        return true;
    }
   // main working function, Finding out possible celeb candidate
    int findCelebrity(int n) {
        int celeb=0;
        for(int i=0;i<n;i++){
            if(knows(celeb,i)){
                celeb=i;
            }
        }
        if(isceleb(celeb,n)) 
            return celeb;
        return -1;
    }
};

//space O(1)
//time O(n)