class Solution:
    def numberOfPoints(self, nums: list[list[int]]) -> int:
        a = set()
        for i in nums:
            a.update(range(i[0], i[1] + 1))
        return len(a)


a = Solution()

b = [[3, 6], [1, 5], [4, 7]]

b = a.numberOfPoints(b)

print(b)