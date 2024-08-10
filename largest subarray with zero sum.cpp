int maxLen(vector<int> &A, int n)
{
    // Your code here
    unordered_map<int, int> sumState;
    int currSum = 0;
    int answer = 0;
    for (int i = 0; i < n; i++)
    {
        currSum += A[i];
        if (currSum == 0)
            answer = max(answer, i + 1);
        else
        {
            if (sumState.find(currSum) != sumState.end())
            {
                answer = max(answer, i - sumState[currSum]);
            }
            else
                sumState[currSum] = i;
        }
    }
    return answer;
}