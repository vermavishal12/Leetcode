class Solution {
public:
    using p = pair<double, pair<double,double>>;
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        
        priority_queue<p>pq;
        double fraction, delta, res = 0;
        for(auto& c : classes) {
            fraction = ((double) c[0]) /c[1];
            delta = ((double) c[0]+1)/(c[1] +1);
            delta = delta - fraction;
            pq.push({delta, {c[0], c[1]}});

        }
        
        double passed, total;
        while(extraStudents) {
            passed = pq.top().second.first + 1;
            total = pq.top().second.second + 1;
            pq.pop();
            fraction = (passed)/total;
            delta = (passed+1)/(total+1);
            delta = delta - fraction;

            extraStudents--;
            pq.push({delta, {passed, total}});
        }

        while(!pq.empty()) {
            res += pq.top().second.first/pq.top().second.second;
            pq.pop();
        }

        return res/classes.size();



    }
};