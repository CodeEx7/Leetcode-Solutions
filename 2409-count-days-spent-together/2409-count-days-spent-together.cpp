class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        vector<int> arr({0,31,59,90,120,151,181,212,243,273,304,334,365}); //count th number of days till the month
        //find out all 
        int AA=arr[stoi(arriveAlice.substr(0,2))-1]+stoi(arriveAlice.substr(3,2));
        int BA=arr[stoi(arriveBob.substr(0,2))-1]+stoi(arriveBob.substr(3,2));
        int AL=arr[stoi(leaveAlice.substr(0,2))-1]+stoi(leaveAlice.substr(3,2));
        int BL=arr[stoi(leaveBob.substr(0,2))-1]+stoi(leaveBob.substr(3,2));
        if(BA>AL || AA>BL){
            return 0;
        }
        int maxi=max(AA,BA);
        int mini=min(AL,BL);
        return mini-maxi+1;
    }
};