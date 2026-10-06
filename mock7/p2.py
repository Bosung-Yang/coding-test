PAIR = {')': '(', ']': '[', '}': '{'}


def solution(s):
    st = []                                   # 아직 닫히지 않은 여는 괄호
    for i, c in enumerate(s):
        if c in '([{':
            st.append(c)
        else:
            if not st or st[-1] != PAIR[c]:   # 짝이 없거나 종류가 다름
                return i
            st.pop()
    return len(s) if st else -1               # 남은 여는 괄호가 있으면 길이
