class Solution {
public:
    int compareVersion(string version1, string version2) {
         vector<int>V;
         stringstream ss1(version1); 
         stringstream ss2(version2);
        string part1;
        string part2;
        vector<string> result1;
        vector<string>result2;

        while (getline(ss1, part1, '.')) {
            result1.push_back(part1);
        }
         while (getline(ss2, part2, '.')) {
            result2.push_back(part2);
        }

        int n=result1.size();
        int m=result2.size();

            int i=0,j=0;
            while(i<n && j<m)
            {
            int num1 = stoi(result1[i]);
            int num2 = stoi(result2[j]);

            if (num1 < num2) return -1;
            else if (num1 > num2) return 1;


            i++;
            j++;
                
            }
            while(i<n)
            {
                if(stoi(result1[i])==0) 
                {
                    i++;
                }
                else return 1;
            }
            while(j<m)
            {
                if(stoi(result2[j])==0) 
                {
                    j++;
                }
                else return -1;
            }
        

        return 0;
    }

};