class Fenwick: 

    def __init__(self, n: int):
        self.nums = [0]*(n+1)

    def sum(self, k: int) -> int: 
        k += 1
        ans = 0
        while k:
            ans += self.nums[k]
            k &= k-1 # unset last set bit 
        return ans

    def add(self, k: int, x: int) -> None: 
        k += 1
        while k < len(self.nums): 
            self.nums[k] += x
            k += k & -k 


class MKAverage:

    def __init__(self, m: int, k: int):
        self.m = m
        self.k = k 
        self.data = deque()
        self.value = Fenwick(10**5+1)
        self.index = Fenwick(10**5+1)

    def addElement(self, num: int) -> None:
        self.data.append(num)
        self.value.add(num, num)
        self.index.add(num, 1)
        if len(self.data) > self.m: 
            num = self.data.popleft()
            self.value.add(num, -num)
            self.index.add(num, -1)

    def _getindex(self, k): 
        lo, hi = 0, 10**5 + 1
        while lo < hi: 
            mid = lo + hi >> 1
            if self.index.sum(mid) < k: lo = mid + 1
            else: hi = mid
        return lo 
            
    def calculateMKAverage(self) -> int:
        if len(self.data) < self.m: return -1 
        lo = self._getindex(self.k)
        hi = self._getindex(self.m-self.k)
        ans = self.value.sum(hi) - self.value.sum(lo)
        ans += (self.index.sum(lo) - self.k) * lo
        ans -= (self.index.sum(hi) - (self.m-self.k)) * hi
        return ans // (self.m - 2*self.k)

# Your MKAverage object will be instantiated and called as such:
# obj = MKAverage(m, k)
# obj.addElement(num)
# param_2 = obj.calculateMKAverage()