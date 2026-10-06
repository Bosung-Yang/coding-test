def solution(n, commands):
    mem = [0] * n          # mem[i] : i번 칸을 가진 id (0 = 빈 칸)
    answer = []

    for cmd in commands:
        parts = cmd.split()
        pid = int(parts[1])

        if parts[0] == "A":
            size = int(parts[2])
            # 연속 빈 칸이 size개가 되는 순간 → 가장 앞 시작 위치
            run, start = 0, -1
            for i in range(n):
                run = run + 1 if mem[i] == 0 else 0
                if run == size:
                    start = i - size + 1
                    break
            if start != -1:
                for i in range(start, start + size):
                    mem[i] = pid           # 실제로 할당
            answer.append(start)
        else:  # "F"
            for i in range(n):
                if mem[i] == pid:
                    mem[i] = 0
    return answer
