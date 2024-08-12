class Solution
{
public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        int destination = pow(board.size(), 2);
        int n = board.size();

        int ans = 0;
        // creating a  hashtable for maintaining which cell is visited already
        unordered_set<int> visited;

        queue<int> q;

        q.push(1);
        visited.insert(1);

        while (!q.empty())
        {
            int size = q.size();

            for (int i = 0; i < size; i++)
            {
                // popping current position
                int curr_pos = q.front();
                q.pop();

                // now we roll the dice
                for (int dice = 1; dice <= 6; dice++)
                {
                    // we have our next position as given below
                    int next_pos = curr_pos + dice;

                    // row and column number of that position in board
                    int row = (n - 1) - (next_pos - 1) / n;
                    int col = (next_pos - 1) % n;

                    // now according to the board we have to flip the row
                    // whenever we encounter odd row number
                    if ((n - 1 - row) % 2 != 0)
                    {
                        col = n - 1 - col;
                    }

                    // now at the next position we may encounter a snake or ladder
                    if (board[row][col] != -1)
                    {
                        next_pos = board[row][col];
                    }

                    // case when we reach the destination
                    if (next_pos == destination)
                    {
                        return ans + 1;
                    }

                    // if the next position is not visited then we
                    // push it in the queue and make it as visited
                    if (visited.count(next_pos) == 0)
                    {
                        visited.insert(next_pos);
                        q.push(next_pos);
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};