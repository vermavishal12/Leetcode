class Solution {
public:
    
    vector<int> func(string exp) {
        vector<int>res;

        for(int i = 0; i < exp.size() ; i++) {
            char ch = exp[i];

            if(ch == '+' || ch == '-' || ch == '*') {
                // we will be breaking our problem into sub problems, one will compute the all the [possible] 
                // values in the left of the operator and other will do the same for the right side of the operator
                vector<int>left = func(exp.substr(0,i));
                vector<int>right = func((exp.substr(i+1)));
                // then we will do all the possible answers by iterating over all the left and right possible values
                for(auto l : left) {
                    for(auto r : right) {
                        if(ch == '+'){
                            res.push_back(l+r);
                        }else if(ch == '-') {
                            res.push_back(l-r);
                        }else if(ch == '*') {
                            res.push_back(l*r);
                        }
                    }
                }
            }
        }

        // let say there is nothing in the result array then it means there is no operator in the given 
        // expression, so may be expression is empty or only contains the digits
        if(res.empty()) {
            res.push_back(stoi(exp));
        }
        return res;
    }

    vector<int> diffWaysToCompute(string expression) {
        stack<int>st;
        return func(expression);
    }
};