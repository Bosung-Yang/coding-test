"""Python 정답 채점용 실행기 (tests/<세트>/main.cpp 와 같은 입력 형식을 읽음)

사용법: python3 pyjudge.py <테스트세트> <풀이.py> < 입력파일
예)    python3 pyjudge.py mock1/p1 mock1/p1.py < tests/mock1/p1/1.in
"""
import importlib.util
import sys


def tokens(text):
    return text.split()


def ints(it, k):
    return [int(next(it)) for _ in range(k)]


def grid_int(it, n, m):
    return [ints(it, m) for _ in range(n)]


def join(v):
    return " ".join(map(str, v))


def lines_out(v):
    return "\n".join(map(str, v))


# ---- 세트별 입력 파서: text -> (인자 튜플), 출력 포매터: 결과 -> 문자열 ----
def p_editor1(text):
    ls = text.split("\n")
    init, n = ls[0], int(ls[1])
    return (init, ls[2:2 + n])


def p_lines_after_count(text):
    ls = text.split("\n")
    n = int(ls[0].split()[0])
    return (ls[1:1 + n],)


def p_mock1_p2(text):
    it = iter(tokens(text)); n = int(next(it))
    cost = grid_int(it, n, n); m = int(next(it))
    return (cost, grid_int(it, m, 2))


def p_grid_str(text):                 # "R C" + R줄
    t = tokens(text); r = int(t[0])
    return (t[2:2 + r],)


def p_grid_str_k(text):               # "R C K" + R줄
    t = tokens(text); r, k = int(t[0]), int(t[2])
    return (t[3:3 + r], k)


def p_mock1_p4(text):
    it = iter(tokens(text)); n, m, k = ints(it, 3)
    return (grid_int(it, n, m), k)


def p_grid_int(text):                 # "N M" + 격자
    it = iter(tokens(text)); n, m = ints(it, 2)
    return (grid_int(it, n, m),)


def p_mock2_p2(text):
    ls = text.split("\n"); n, q = map(int, ls[0].split())
    return (n, ls[1:1 + q])


def p_mock2_p4(text):
    it = iter(tokens(text)); n, m = ints(it, 2)
    times = ints(it, n); c = int(next(it))
    return (times, m, grid_int(it, c, 2))


def p_mock3_p1(text):
    ls = text.split("\n"); r = int(ls[0].split()[0])
    grid = ls[1:1 + r]; q = int(ls[1 + r])
    return (grid, ls[2 + r:2 + r + q])


def p_mock3_p2(text):
    ls = text.split("\n"); n, k = map(int, ls[0].split())
    return (ls[1:1 + n], k)


def p_mock4_p1(text):
    it = iter(tokens(text)); n, t = ints(it, 2)
    return (ints(it, n), t)


def p_mock4_p2(text):
    t = tokens(text); n = int(t[0])
    return (t[1:1 + n],)


def p_mock4_p4(text):
    it = iter(tokens(text)); n, need = ints(it, 2)
    cost = ints(it, n); power = ints(it, n); m = int(next(it))
    return (cost, power, need, grid_int(it, m, 2))


def p_single_str(text):
    return (text.split()[0],)


def p_mock5_p4(text):
    it = iter(tokens(text)); n, k = ints(it, 2)
    return (grid_int(it, n, n), k)


def p_mock6_p1(text):
    t = tokens(text); n = int(t[0]); grid = t[1:1 + n]
    m = int(t[1 + n])
    return (grid, t[2 + n:2 + n + m])


def p_mock6_p4(text):
    it = iter(tokens(text)); n = int(next(it))
    return (grid_int(it, n, n),)


def p_mock7_p1(text):
    it = iter(tokens(text)); n, m, k = ints(it, 3)
    return (grid_int(it, n, m), k)


def p_mock7_p4(text):
    it = iter(tokens(text)); n = int(next(it))
    return (ints(it, n), ints(it, 4))


def p_gemini_p1(text):
    it = iter(tokens(text)); n, m, limit, k = ints(it, 4)
    return (grid_int(it, n, m), limit, k)


def p_gemini_p2(text):
    it = iter(tokens(text)); n, c = ints(it, 2)
    return (ints(it, n), c)


def p_gemini_p3(text):
    it = iter(tokens(text)); n = int(next(it))
    return (grid_int(it, n, 3),)


SPECS = {
    "editor1":    (p_editor1, str),
    "mock1/p1":   (p_lines_after_count, lines_out),
    "mock1/p2":   (p_mock1_p2, str),
    "mock1/p3":   (p_grid_str, str),
    "mock1/p4":   (p_mock1_p4, str),
    "mock2/p1":   (p_grid_int, join),
    "mock2/p2":   (p_mock2_p2, join),
    "mock2/p3":   (p_grid_str_k, str),
    "mock2/p4":   (p_mock2_p4, str),
    "mock3/p1":   (p_mock3_p1, join),
    "mock3/p2":   (p_mock3_p2, lines_out),
    "mock3/p3":   (p_grid_str_k, join),
    "mock3/p4":   (p_grid_str, str),
    "mock4/p1":   (p_mock4_p1, join),
    "mock4/p2":   (p_mock4_p2, join),
    "mock4/p3":   (p_grid_str, join),
    "mock4/p4":   (p_mock4_p4, str),
    "mock5/p1":   (p_grid_int, join),
    "mock5/p2":   (p_single_str, str),
    "mock5/p3":   (p_grid_str, str),
    "mock5/p4":   (p_mock5_p4, str),
    "mock6/p1":   (p_mock6_p1, str),
    "mock6/p2":   (p_lines_after_count, str),
    "mock6/p3":   (p_grid_str, str),
    "mock6/p4":   (p_mock6_p4, str),
    "mock7/p1":   (p_mock7_p1, lambda g: "\n".join(join(r) for r in g)),
    "mock7/p2":   (p_single_str, str),
    "mock7/p3":   (p_grid_str, str),
    "mock7/p4":   (p_mock7_p4, join),
    "gemini1/p1": (p_gemini_p1, str),
    "gemini1/p2": (p_gemini_p2, str),
    "gemini1/p3": (p_gemini_p3, join),
}


def main():
    test_set, path = sys.argv[1], sys.argv[2]
    spec = importlib.util.spec_from_file_location("solution_module", path)
    module = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(module)
    sys.setrecursionlimit(100000)

    parse, fmt = SPECS[test_set]
    args = parse(sys.stdin.read())
    print(fmt(module.solution(*args)))


if __name__ == "__main__":
    main()
