
func lengthOfPalindrome(s string, left int, right int, l int) int {
    if left > right {
        return 0;
    }
    for left >= 0 && right < l && s[left] == s[right] {
        left--;
        right++;
    }
    return right - left - 1;
}

func longestPalindrome(s string) string {
    l := len(s);
    if l < 1 {
        return "";
    }
    start := 0;
    end := 0;
    for i := 0; i < l; i++ {
        len1 := lengthOfPalindrome(s, i, i, l);
        len2 := lengthOfPalindrome(s, i, i + 1, l);
        max := 0;
        if max < len1 {
            max = len1;
        }
        if max < len2 {
            max = len2;
        }
        if max > end - start {
            start = i - ((max - 1) / 2);
            end = i + (max / 2);
        }
    }
    return s[start:end + 1];
}
