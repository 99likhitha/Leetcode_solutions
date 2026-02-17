class Solution {
public:
    void backtrack(vector<int>&values,int count,int start,int sum,vector<int>&result)
    {
        if(count==0)
        {
            result.push_back(sum);
            return;
        }

        for(int i=start;i<values.size();i++)
        {
            backtrack(values,count-1,i+1,sum+values[i],result);
        }

    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string>ans;
        if(turnedOn>8) return {};
        vector<int>hrs={1,2,4,8};
        vector<int>mins={1,2,4,8,16,32}; 
        for(int hours=0;hours<=min(4,turnedOn);hours++)
        {
            int Minutes = turnedOn-hours;
            if(Minutes>6) continue;
            vector<int>validhrs,validmins;
            backtrack(hrs,hours,0,0,validhrs);
            backtrack(mins,Minutes,0,0,validmins);

            for(int hr:validhrs)
            {
                if(hr>=12) continue;
                for(int min:validmins)
                {
                    if(min>=60) continue;
                    string time=to_string(hr) +":";
                    if(min<10) time+="0";
                    time +=to_string(min);
                    ans.push_back(time);
                }
            }
        }
        return ans;
    }
};