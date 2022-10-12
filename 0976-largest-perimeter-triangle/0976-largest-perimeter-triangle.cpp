class Solution {
public:
    bool makes_tringle(int a, int b, int c){
        if(a+b>c && a+c>b && b+c>a){
            return true;
        }
        return false;
    }
    //-------------------------------
    int largestPerimeter(vector<int>& nums) {
        priority_queue<int> pq;
        for(auto n:nums){
            pq.push(n);
        }
        int a, b, c;
        a=pq.top();
        pq.pop();
        b=pq.top();
        pq.pop();
        c=pq.top();
        pq.pop();
        
        if(makes_tringle(a,b,c)){
            return a+b+c;
        }else{
            int i=0;
            while(!pq.empty()){
                if(i%3==0){
                    a=pq.top();
                }else if(i%3==1){
                    b=pq.top();
                }else if(i%3==2){
                    c=pq.top();
                }
                i++;
                pq.pop();
                
                if(makes_tringle(a,b,c)){
                    return a+b+c;
                }
            }
        }
        return 0;
    }
};