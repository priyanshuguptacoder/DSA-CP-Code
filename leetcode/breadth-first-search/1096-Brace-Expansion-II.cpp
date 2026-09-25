class Solution {
    string s;
    int i = 0;
private:
    set<string> parseExpression(){ //term (',' term) *
        set<string> result = parseTerm();
        while(i < s.size() && s[i] == ','){
            i++; //Skip

            set<string> next = parseTerm();
            result.insert(next.begin(), next.end());
        }
        return result;
    }

    set<string> parseTerm(){ //Factor factor
        set<string> result = {""};

        while(i < s.size() && s[i] != ',' && s[i] != '}'){
            set<string> cur = parseFactor();
            set<string> next;

            for(const string& a : result){ //Cartesian product + concatenation
                for(const string& b : cur){
                    next.insert(a + b);
                }
            }
            result = next;
        }

        return result;
    }

    set<string> parseFactor(){
        set<string> result;

        if(s[i] == '{'){
            i++; //Skip

            result = parseExpression();
            i++; //Skip
        }
        else{
            result.insert(string(1, s[i]));
            i++;
        }

        return result;
    }

public:
    vector<string> braceExpansionII(string expression) {
        s = expression;
        i = 0;

        set<string> result = parseExpression();
        return vector<string>(result.begin(), result.end());
    }
};