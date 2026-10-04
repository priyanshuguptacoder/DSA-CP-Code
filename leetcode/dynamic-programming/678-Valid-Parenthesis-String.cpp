class Solution {
public:
    bool checkValidString(string s) {
        int n = s.length();
        int minOpen = 0, maxOpen = 0;

        for(int i=0; i<n; i++){
            if(s[i] == '('){
                minOpen++;
                maxOpen++;
            }
            else if(s[i] == ')'){
                minOpen--;
                maxOpen--;
            }
            else{
                minOpen--;
                maxOpen++;
            }

            if(maxOpen < 0){ //If any close bracket bracket than open seen any where then return false
                return false;
            }
            if(minOpen < 0){
                minOpen = 0;
            }
        }

        return (minOpen == 0);
    }
};