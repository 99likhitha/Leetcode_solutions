class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);

        for (int i = 0; i < n; i++) {
            indices[i] = i;
        }

        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });

        vector<int> st;
        for (int i : indices) {
            if (directions[i] == 'R') {
             
                st.push_back(i);
            } else {
              
                while (!st.empty() && healths[i] > 0) {
                    int top = st.back();
                    
                    if (healths[i] > healths[top]) {
                        
                        healths[top] = 0;
                        healths[i] -= 1;
                        st.pop_back();
                    } else if (healths[i] < healths[top]) {
                        
                        healths[i] = 0;
                        healths[top] -= 1;
                    } else {
                       
                        healths[i] = 0;
                        healths[top] = 0;
                        st.pop_back();
                    }
                }
            }
        }

      
        vector<int> result;
        for (int h : healths) {
            if (h > 0) {
                result.push_back(h);
            }
        }
        return result;
    }
};