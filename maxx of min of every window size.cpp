
class Solution
{
    public:
    //Function to find maximum of minimums of every window size.
    vector <int> maxOfMin(int arr[], int n)
    {
    
    
        
      // Initialize vectors to store left and right indices of the minimums for each element.
        vector<int> left(n+1, -1); // To store the left index of the minimum for each element.
        vector<int> right(n+1, n); // To store the right index of the minimum for each element.

        // Vector to store the final result (maximum of minimums for each window size).
        vector<int> result(n+1, 0);

        // Stack to store the indices of elements in ascending order.
        stack<int> smallerIndex;

        // Traverse the array from left to right and find the left index of the minimum for each element.
        for (int i = 0; i < n; i++) {
            while (!smallerIndex.empty() && arr[smallerIndex.top()] >= arr[i])
                smallerIndex.pop();
            left[i] = smallerIndex.empty() ? -1 : smallerIndex.top();
            smallerIndex.push(i);
        }

        // Clear the stack to be used again for the next loop.
        while (!smallerIndex.empty())
            smallerIndex.pop();

        // Traverse the array from right to left and find the right index of the minimum for each element.
        for (int i = n-1; i >= 0; i--) {
            while (!smallerIndex.empty() && arr[smallerIndex.top()] >= arr[i])
                smallerIndex.pop();
            right[i] = smallerIndex.empty() ? n : smallerIndex.top();
            smallerIndex.push(i);
        }

        // Calculate the maximum of minimums for each window size.
        for (int i = 0; i < n; i++) {
            int len = right[i] - left[i] - 1;
            result[len] = max(result[len], arr[i]);
        }

        // Fill in the gaps (some elements of result[] might not have been updated in the previous loop).
        for (int i = n-1; i >= 1; i--)
            result[i] = max(result[i], result[i+1]);

        // Remove the first element (it's 0, and the result starts from index 1).
        vector<int> finalResult(result.begin() + 1, result.end());
        return finalResult;
    
    
     
    }
};