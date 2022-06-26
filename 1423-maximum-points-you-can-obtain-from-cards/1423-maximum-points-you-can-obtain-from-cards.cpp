class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int maxi=INT_MIN, left_sum=0, right_sum;
        for(int i=0;i<k;i++){
            left_sum+=cardPoints[i];
            maxi=max(maxi, left_sum);
        }
        right_sum=left_sum;
        int n=cardPoints.size();
        int i=0;
        for(int i=1, j=k-1; i<n && j>=0; i++, j--){
            right_sum-=cardPoints[j];
            right_sum+=cardPoints[n-i];
            maxi=max(maxi, right_sum);
        }
        return maxi;
    }
};