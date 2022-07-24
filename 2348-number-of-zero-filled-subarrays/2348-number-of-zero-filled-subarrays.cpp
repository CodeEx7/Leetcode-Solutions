class Solution {
public:
    long long zeroFilledSubarray(vector<int>& a) {
        long long c = 0,ans = 0;
		for(int &x: a) {
			if(x == 0) c++;
			else c = 0;
			ans += c;
		}
		return ans;
    }
};