#include <stdio.h>

// Function to find the maximum of two integers
int max(int a, int b) {
    return (a > b) ? a : b;
}

// Recursive function to solve knapsack problem
int knapsack(int W, int wt[], int val[], int n) {
    // Base case: If either the capacity of the knapsack or the number of items becomes 0, return 0
    if (n == 0 || W == 0)
        return 0;

    // If the weight of the nth item is more than the knapsack capacity, then this item cannot be included in the optimal solution
    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);

    // Return the maximum of two cases:
    // 1. nth item included
    // 2. nth item not included
    else
        return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), knapsack(W, wt, val, n - 1));
}

int main() {
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(val) / sizeof(val[0]);
    printf("Maximum value that can be obtained is %d\n", knapsack(W, wt, val, n));
    return 0;
}

