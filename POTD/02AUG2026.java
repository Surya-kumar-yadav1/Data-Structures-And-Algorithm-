/*
Problem: 877. Stone Game
Difficulty: Medium
Topic: Math, Game Theory

Approach 2:
- Alice can always guarantee a win by choosing either all even-indexed piles or all odd-indexed piles.
- Since the number of piles is even and the total number of stones is odd, the sums of the even-indexed and odd-indexed piles cannot be equal.
- Before the game starts, Alice determines which parity (even or odd indices) has the larger total.
- On every turn, she can always pick from the corresponding end to continue taking piles of that parity.
- Thus, Alice always collects more stones than Bob.

Time Complexity: O(1)
Space Complexity: O(1)
*/

class Solution {
    public boolean stoneGame(int[] piles) {
        return true;
    }
}
