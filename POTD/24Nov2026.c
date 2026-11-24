//
//
int gcd(int a, int b) {
    while (b != 0) {
        int temp = a;
        a = b;
        b = temp % b;
    }
    return a;
}

int maxLength(int* nums, int numsSize) {
    int res = 2;
    int prodVal = 1;
    int n = numsSize;
    int start = 0, end = 0;

    while (end < n) {
        while (gcd(prodVal, nums[end]) > 1) {
            prodVal /= nums[start];
            start++;
        }
        prodVal *= nums[end];
        int length = end - start + 1;
        res = (res > length) ? res : length;
        end++;
    }
    return res;
}
