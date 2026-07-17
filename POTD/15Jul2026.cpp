/*
Problem: 3658. GCD of Odd and Even Sums
Difficulty: Easy
Topic: Math, GCD

Approach:
- The sum of the first n odd numbers is n².
- The sum of the first n even numbers is n(n + 1).
- Compute gcd(n², n(n + 1)).
- Since gcd(n, n + 1) = 1, the result simplifies to n.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n;
    }
};
