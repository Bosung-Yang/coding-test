def to_minutes(t):
    return int(t[:2]) * 60 + int(t[3:])


def solution(logs):
    # 가동 시간 = Σ(OFF - ON) = ΣOFF - ΣON
    # → 로그가 섞여 있어도 정렬 없이 OFF는 더하고 ON은 빼면 됨
    total = {}
    for log in logs:
        equip_id, t, state = log.split()
        m = to_minutes(t)
        total[equip_id] = total.get(equip_id, 0) + (m if state == "OFF" else -m)

    # 가동 시간 긴 순 → ID 사전순
    return sorted(total, key=lambda e: (-total[e], e))
