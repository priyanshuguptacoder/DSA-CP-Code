class Solution {
private:
    bool isPrime(int n){
        if(n == 2 || n == 3){
            return true;
        }
        
        if(n < 2 || n % 2 == 0 || n % 3 == 0){
            return false;
        }

        for(int i=2; i*i<=n; i++){
            if(n % i == 0){
                return false;
            }
        }
        return true;
    }

public:
    bool completePrime(int num) {
        string s = to_string(num);
        int n = s.length();
        int pref = 0;

        for(int i=0; i<n; i++){
            pref = pref * 10 + (s[i] - '0');
            if(!isPrime(pref)){
                return false;
            }
        }

        int suff = 0;
        int place = 1;

        for(int i=n-1; i>=0; i--){
            suff = (s[i] - '0') * place + suff;

            if(!isPrime(suff)){
                return false;
            }
            place *= 10;
        }

        return true;
    }
};