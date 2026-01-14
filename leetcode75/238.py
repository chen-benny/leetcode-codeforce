class Solution:
    def productExceptSelf(self, nums: list[int]) -> list[int]:
        n = len(nums)
        res = [1] * n

        leftProd = 1
        for i in range(n):
            res[i] = leftProd
            leftProd *= nums[i]

        rightProd = 1
        for i in range(n - 1, -1, -1):
            res[i] *= rightProd
            rightProd *= nums[i]

        return res
