/* 
Problem: 3875. Construct Uniform Parity Array I 
Difficulty: Easy 
Topic: Array, Parity 
 
Approach: 
- We only care about whether each number is odd or even. 
- If all elements already have the same parity, we can simply choose 
  nums2[i] = nums1[i] for every index. 
- Otherwise, there are both odd and even numbers in the array. 
- Since the array contains distinct integers, for any element we can 
  subtract another element having the opposite parity. 
- Odd - even = odd, and even - odd = even, so choosing an element with 
  the appropriate parity allows us to make every resulting value have 
  the same parity. 
- Therefore, the only impossible case is when the array contains both 
  odd and even values but no valid opposite-parity subtraction can be 
  made for some element. With distinct integers, this never happens as 
  long as n > 1. 
 
Time Complexity: O(n) 
Space Complexity: O(1) 
*/ 
 
class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool hasOdd = false;
        bool hasEven = false;

        for (int x : nums1) {
            if (x % 2 == 0)
                hasEven = true;
            else
                hasOdd = true;
        }

        // All elements already have the same parity.
        if (!hasOdd || !hasEven)
            return true;

        // Both parities are present, so we can make
        // all elements have the same parity using subtraction.
        return nums1.size() > 1;
    }
};
