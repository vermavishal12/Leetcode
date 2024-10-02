class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        unordered_map<int,int>map;
        vector<int>ar;
        for(int i = 0; i < arr.size(); i++) {
            if(map[arr[i]] == 0) {
                ar.push_back(arr[i]);
            }
            map[arr[i]] = i+1;
        }        
        
        sort(ar.begin(), ar.end());

        for(int i = 0; i < ar.size() ; i++) {
            map[ar[i]] = i+1;
        }
        
        for(auto & a : arr) {
            a = map[a];
        }

        return arr;

    }
};