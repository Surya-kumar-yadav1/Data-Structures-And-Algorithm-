//
//

func maxLength(nums []int) int {
	res := 2
	prodVal := 1
	n := len(nums)
	start, end := 0, 0

	gcd := func(a, b int) int {
		for b != 0 {
			a, b = b, a%b
		}
		return a
	}

	for end < n {
		for gcd(prodVal, nums[end]) > 1 {
			prodVal /= nums[start]
			start++
		}
		prodVal *= nums[end]
		if end-start+1 > res {
			res = end - start + 1
		}
		end++
	}
	return res
}
