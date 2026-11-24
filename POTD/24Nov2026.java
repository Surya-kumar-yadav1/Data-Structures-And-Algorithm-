class Solution {

    public int maxLength(int[] nums) {
        int res = 2;
        int prodVal = 1;
        int n = nums.length;
        int start = 0,
            end = 0;

        while (end < n) {
            while (gcd(prodVal, nums[end]) > 1) {
                prodVal /= nums[start];
                start++;
            }
            prodVal *= nums[end];
            res = Math.max(res, end - start + 1);
            end++;
        }
        return res;
    }

    private int gcd(int num1, int num2) {
        while (num2 != 0) {
            int temp = num1;
            num1 = num2;
            num2 = temp % num2;
        }
        return num1;
    }
}
