class Solution {
public:
    string simplifyPath(string path) {
        path+="/";
        int n=path.size();
        stack<string>st;
        string curr="";
        for(int i=0;i<n;i++)
        {
            if(path[i] == '/' )
            {
               if(curr=="..")
               {
                    if(!st.empty()) st.pop();
               }
               else if (curr != "" && curr != ".")
               {
                    st.push(curr);
               }
               curr= "";
            }
            else
            {
                curr+=path[i];
            }

             
        }


    string ans="/";
    vector<string>directory;
    while(!st.empty())
    {
        directory.push_back(st.top());
        st.pop();
    }
    reverse(directory.begin(),directory.end());
    
    int d=directory.size();
    for(int i=0;i<d;i++)
    {
        ans+=directory[i];
        if(i!=d-1)
        {
            ans+="/";
        }

    }

    return ans;

    }
};