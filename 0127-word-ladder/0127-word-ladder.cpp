class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        if (beginWord==endWord) return 0;
        set<string>S(wordList.begin(),wordList.end());
        if(S.find(endWord)==S.end()) 
        {
            return 0;
        }

        queue<string>q;
        int level=0,wordlen=beginWord.size();

        q.push(beginWord);
        while(!q.empty())
        {
            level++;

            int qsize=q.size();

            for(int i=0;i<qsize;i++)
            {
                string word=q.front();
                q.pop();
                for(int j=0;j<wordlen;j++)
                {

                    char curr=word[j];
                    for(char c='a';c<='z';c++)
                    {
                        word[j]=c;

                        if(word==endWord) return level+1;

                        if(S.find(word)==S.end())
                        {
                            continue;
                        }
                        S.erase(word);

                        q.push(word);
                    }

                    word[j]=curr;
                }
            }
        }
        return 0;
    }
};