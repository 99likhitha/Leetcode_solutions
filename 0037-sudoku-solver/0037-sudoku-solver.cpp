class Solution {
public:
    bool isSafe(vector<vector<char>>&board,int row,int col,char val)
    {
        for(int i=0;i<9;i++)
        {
            if(board[i][col] == val) return false;
            if(board[row][i]==val) return false;
        }

        int startrow=3*(row/3);
        int startcol=3*(col/3);
        for(int i=0;i<3;i++)
        {
            for(int j=0;j<3;j++)
            {
                if(board[startrow+i][startcol+j]==val) return false;
            }
        }

        return true;

    }

    bool recur(vector<vector<char>>&board)
    {
        for(int i=0;i<9;i++)
        {
            for(int j=0;j<9;j++)
            {
                if(board[i][j]=='.')
                {
                    for(char c='1';c<='9';c++)
                    {
                        if(isSafe(board,i,j,c))
                        {
                            board[i][j]=c;
                            
                            if(recur(board)) return true;
                            board[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }

        return true;
    }

    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        recur(board);
        
    }
};