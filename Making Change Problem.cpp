#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinCoins(const vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, amount + 1);
    
    dp[0] = 0;

    for (int i = 1; i <= amount; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }
    return (dp[amount] > amount) ? -1 : dp[amount];
}

int main() {
    int numCoins, targetAmount;

    cout << "Enter the number of coin denominations available: ";
    if (!(cin >> numCoins) || numCoins <= 0) {
        cout << "Invalid number of coins." << endl;
        return 1;
    }

    vector<int> coins(numCoins);
    cout << "Enter the coin values (separated by spaces): ";
    for (int i = 0; i < numCoins; i++) {
        cin >> coins[i];
    }

    cout << "Enter the target amount: ";
    cin >> targetAmount;

    if (targetAmount < 0) {
        cout << "Target amount cannot be negative." << endl;
        return 1;
    }

    int result = getMinCoins(coins, targetAmount);

    if (result == -1) {
        cout << "\nIt is impossible to make change for " << targetAmount << " with the given denominations." << endl;
    } else {
        cout << "\nThe minimum number of coins required to make change is: " << result << endl;
    }

    return 0;
}
