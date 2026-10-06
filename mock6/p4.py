def solution(synergy):
    n = len(synergy)
    size = n // 3
    team = [-1] * n
    cnt = [0, 0, 0]
    best = float('inf')

    def evaluate():
        score = [0, 0, 0]
        for a in range(n):
            for b in range(a + 1, n):            # 두 사람 쌍을 한 번씩만
                if team[a] == team[b]:
                    score[team[a]] += synergy[a][b]
        return max(score) - min(score)

    # 나눠 담기 백트래킹 : person번 사람을 어느 팀에 넣을지
    def dfs(person):
        nonlocal best
        if person == n:
            best = min(best, evaluate())
            return
        for t in range(3):
            if cnt[t] == size:
                continue                         # 팀이 꽉 참
            team[person] = t
            cnt[t] += 1
            dfs(person + 1)
            cnt[t] -= 1                          # 되돌리기
            if cnt[t] == 0:
                break                            # 빈 팀은 어디든 같으므로 하나만 시도

    dfs(0)
    return best
