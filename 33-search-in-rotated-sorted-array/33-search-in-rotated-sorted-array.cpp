class Solution {
public:
    int findPivot(vector<int>& nums){
    int left=0, right=nums.size()-1;
    
    while(left<right){
        int mid=left+(right-left)/2;
        if(nums[mid]>=nums[0])
            left=mid+1;
        
        else
            right=mid;
    }
    return left;
}

int binarySearch(vector<int>& nums, int s, int e, int target){    
    while(s<=e){
        int mid = s+(e-s)/2;
        
        if(nums[mid]==target)
            return mid;
        
        else if(nums[mid]<target)
            s=mid+1;
        
        else
            e=mid-1;
    }
    return -1;
}

int search(vector<int>& nums, int target) {
    int pivot = findPivot(nums);
    int answer;
    
    if(nums[pivot]<=target && target<=nums[nums.size()-1])
        answer = binarySearch(nums, pivot, nums.size()-1, target);
    else
        answer = binarySearch(nums, 0, pivot-1, target);
    
    return answer;
}
};