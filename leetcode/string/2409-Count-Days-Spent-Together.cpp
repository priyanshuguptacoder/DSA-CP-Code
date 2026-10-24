class Solution {
private:
    int count(string num){
        vector<int>months = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int mon = stoi(num.substr(0, 2));
        int day = stoi(num.substr(3, 2));

        for(int i=0; i<mon-1; i++){ //Usse previous months ka nikal lo aur uss month ke day ko jodh lo
            day += months[i];
        }

        return day;
    }
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {
        int start = max(count(arriveAlice), count(arriveBob));
        int end = min(count(leaveAlice), count(leaveBob));

        int ans = max(0, end - start + 1);
        return ans;
    }
};