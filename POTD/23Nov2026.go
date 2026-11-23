type ProductOfNumbers struct {
    prefix []int  // prefix[i]: the product of the first i numbers after the last zero
}

func Constructor() ProductOfNumbers {
    return ProductOfNumbers{prefix: []int{1}}
}

func (p *ProductOfNumbers) Add(num int) {
    if num == 0 {
        p.prefix = p.prefix[:1]  // a window that reaches this zero is 0, so keep only the leading 1
    } else {
        p.prefix = append(p.prefix, p.prefix[len(p.prefix)-1]*num)
    }
}

func (p *ProductOfNumbers) GetProduct(k int) int {
    n := len(p.prefix)
    if k >= n {  // the window reaches back to a zero
        return 0
    }
    return p.prefix[n-1] / p.prefix[n-1-k]
}
