class Solution {
public:

    unordered_map<string , int>map;
    // function to tokenize the string on the basis of the delimiter [i.e. a special character]
    void split (string str, char delimiter) {
        stringstream ss(str);
        
        vector<string>res;
        string token;
        while(getline(ss, token, delimiter)) {
            map[token]++;
        }
        return;
    }

    vector<string> uncommonFromSentences(string s1, string s2) {
        split(s1, ' ');
        split(s2, ' ');
        
        vector<string>res;
        // iterating to check the frequency of each. token in the given strings, if the frequency then we push it in the resultant array
        for(auto m : map) {
            if(m.second == 1) {
                res.push_back(m.first);
            }
        }
        return res;
    }
};