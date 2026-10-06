def solution(nums, ops):
    n = len(nums)
    remain = list(ops)          # 남은 연산자 개수 (+, -, ×, ÷)
    result = [-float('inf'), float('inf')]

    def divide(a, b):
        # C++처럼 0 방향으로 버림 (Python의 // 는 음수에서 내림이라 다름: -7 // 3 = -3)
        q = abs(a) // abs(b)
        return q if (a >= 0) == (b > 0) else -q

    def dfs(idx, cur):
        if idx == n:
            result[0] = max(result[0], cur)
            result[1] = min(result[1], cur)
            return
        for k in range(4):
            if remain[k] == 0:
                continue
            x = nums[idx]
            nxt = (cur + x, cur - x, cur * x, divide(cur, x))[k]
            remain[k] -= 1
            dfs(idx + 1, nxt)
            remain[k] += 1      # 되돌리기

    dfs(1, nums[0])
    return result
