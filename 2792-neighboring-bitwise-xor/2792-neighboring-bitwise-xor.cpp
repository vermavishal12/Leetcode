class Solution {
public:

    bool doesValidArrayExistHelper(vector<int>& derived, int start) {
        int ptr = start;
        for(int i = 0; i < derived.size() ; i++) {
            ptr = ptr ^ derived[i];
        }
        return (ptr == start);
    }

    bool doesValidArrayExist(vector<int>& derived) {
        return doesValidArrayExistHelper(derived, 1) || doesValidArrayExistHelper(derived, 0);
    }
};