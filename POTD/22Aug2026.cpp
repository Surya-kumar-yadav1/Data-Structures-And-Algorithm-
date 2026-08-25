/*
Problem: 3622. Check Divisibility by Digit Sum and Product
Difficulty: Easy
Topic: Math, Number Manipulation

Approach:
- Store the original value of n because we will modify n while extracting
  its digits.
- Initialize:
    digitSum = 0
    digitProduct = 1
- Repeatedly take the last digit using n % 10.
- Add the digit to digitSum and multiply it into digitProduct.
- Remove the last digit using n /= 10.
- The required divisor is:
      digitSum + digitProduct
- Finally, check whether the original number is divisible by this divisor.

Time Complexity: O(log n)
Space Complexity: O(1)
*/

class Solution {
public:
    bool checkDivisibility(int n) {
        int original = n;

        int digitSum = 0;
        int digitProduct = 1;

        // Extract every digit of n.
        while (n > 0) {
            int digit = n % 10;

            digitSum += digit;
            digitProduct *= digit;

            n /= 10;
        }

        // Required divisor = digit sum + digit product.
        int divisor = digitSum + digitProduct;

        return original % divisor == 0;
    }
};
