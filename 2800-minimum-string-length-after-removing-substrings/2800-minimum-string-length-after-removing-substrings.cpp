class Solution {
public:
    int minLength(string s) {
        stack<char>st;

        for(auto & c : s) {
            if(c == 'B') {
                if(!st.empty() && st.top() == 'A'){
                    st.pop();
                }else{
                    st.push('B');
                }
            }else if(c == 'D') {
                if(!st.empty() && st.top() == 'C') {
                    st.pop();
                }else {
                    st.push('D');
                }
            }else {
                st.push(c);
            }
        }

        return st.size();
        
    }
};