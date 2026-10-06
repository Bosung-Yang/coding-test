LIMIT = 10 ** 9


def solution(commands):
    st = []
    for cmd in commands:
        parts = cmd.split()
        op = parts[0]
        if op == "PUSH":
            st.append(int(parts[1]))
        elif op == "POP":
            if not st:
                return "ERROR"
            st.pop()
        elif op == "DUP":
            if not st:
                return "ERROR"
            st.append(st[-1])
        else:                                # 값 2개 필요
            if len(st) < 2:
                return "ERROR"
            a = st.pop()                     # 맨 위
            b = st.pop()                     # 그 아래
            if op == "SWAP":
                st += [a, b]
                continue
            if op == "ADD":
                v = b + a
            elif op == "SUB":
                v = b - a                    # 아래 - 위
            else:
                v = b * a
            if abs(v) > LIMIT:               # Python은 오버플로가 없지만 문제 조건대로 검사
                return "ERROR"
            st.append(v)
    return str(st[-1]) if st else "EMPTY"
