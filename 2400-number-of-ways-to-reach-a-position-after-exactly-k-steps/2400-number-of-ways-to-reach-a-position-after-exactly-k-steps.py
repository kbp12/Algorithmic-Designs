class Solution:
    def numberOfWays(self, a: int, b: int, k: int) -> int:
        if (a - b - k) % 2: return 0
        return comb(k, (b - a + k) // 2) % (10 ** 9 + 7)