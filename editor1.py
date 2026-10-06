def solution(init, commands):
    # 커서 왼쪽(left)과 오른쪽(right)을 스택 두 개로 관리
    #   left  : 맨 뒤 = 커서 바로 왼쪽 문자
    #   right : 맨 뒤 = 커서 바로 오른쪽 문자
    left = list(init)
    right = []
    history = []   # 실제로 동작한 명령 기록: ('L',), ('R',), ('P',), ('B', 지운 문자)
    edits = 0      # history 안에 남은 편집(P, B) 수

    for cmd in commands:
        t = cmd[0]
        if t == 'L':
            if not left:
                continue                  # 무시된 명령은 기록하지 않음
            right.append(left.pop())
            history.append(('L',))
        elif t == 'R':
            if not right:
                continue
            left.append(right.pop())
            history.append(('R',))
        elif t == 'P':
            left.append(cmd[2])
            history.append(('P',))
            edits += 1
        elif t == 'B':
            if not left:
                continue
            history.append(('B', left.pop()))
            edits += 1
        else:  # 'U'
            if edits == 0:
                continue                  # 되돌릴 편집이 없으면 아무것도 안 함
            edits -= 1
            # 편집을 하나 만날 때까지 기록을 거꾸로 되돌림 (커서 이동 포함)
            while True:
                rec = history.pop()
                if rec[0] == 'L':
                    left.append(right.pop())
                elif rec[0] == 'R':
                    right.append(left.pop())
                elif rec[0] == 'P':
                    left.pop()
                    break
                else:
                    left.append(rec[1])
                    break

    return "".join(left) + "".join(reversed(right))
