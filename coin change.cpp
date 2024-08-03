vector<int> dp(amount + 1, amount + 1);
dp[0] = 0;

// dp[i] represents the fewest number of coins to make up the amount i
for (int i = 1; i <= amount; i++)
{

    for (auto coin : coins)
    {

        if (coin <= i)
        {

            dp[i] = min(dp[i], dp[i - coin] + 1);
        }
    }
}

return dp[amount] > amount ? -1 : dp[amount];
}