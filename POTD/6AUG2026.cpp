/*
Problem: 3345. Smallest Divisible Digit Product I
Difficulty: Easy
Topic: Math, Brute Force

Approach:
- Starting from n, compute the product of the digits of each number.
- Check if the product is divisible by t.
- Return the first number that satisfies the condition.

Time Complexity: O(k × d)
Space Complexity: O(1)

Where:
- k = numbers checked until a valid answer is found
- d = number of digits in the current number
*/

class Solution {
public:
    int product(int n) {
        int prod = 1;

        while (n > 0) {
            int rem = n % 10;
            prod *= rem;
            n /= 10;
        }

        return prod;
    }

    int smallestNumber(int n, int t) {
        while (true) {
            if (product(n) % t == 0)
                return n;
            n++;
        }

        return -1;
    }
};
