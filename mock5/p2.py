def solution(s):
    result = []
    i, n = 0, len(s)
    while i < n:
        j = i
        while j < n and s[j] == s[i]:     # 같은 문자가 어디까지 이어지는지
            j += 1
        count = j - i
        result.append(s[i] + (str(count) if count > 1 else ""))   # 1번이면 횟수 생략
        i = j
    return "".join(result)
