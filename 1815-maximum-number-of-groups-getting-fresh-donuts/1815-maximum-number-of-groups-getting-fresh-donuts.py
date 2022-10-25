class Solution:
    def maxHappyGroups(self, batchSize: int, groups: List[int]) -> int:
        N = len(groups)

        # We only need to worry about the non-zero remainder
        groups = [i % batchSize for i in groups if i % batchSize]

        # Can already be satisfied
        satisfied = N - len(groups)

        # For those groups that complement each other, we can only satisfy one group
        matching = defaultdict(int)
        for group in groups:
            if matching[batchSize - group] > 0:
                matching[batchSize - group] -= 1
                satisfied += 1
            else:
                matching[group] += 1

        groups = []
        for group, count in matching.items():
            groups += [group] * count

        # Brute force the rest
        @lru_cache(None)
        def allocate(leftOver: int, groups: tuple) -> int:
            if not groups:
                return 0

            result = 0
            for i in range(len(groups)):
                nextGroups = groups[0: i] + groups[i + 1:]
                nextLeftOver = (leftOver - groups[i]) % batchSize
                result = max(result, allocate(nextLeftOver, nextGroups))

            return result + int(leftOver == 0)

        return allocate(0, tuple(groups)) + satisfied