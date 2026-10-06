def is_valid(code):
    if len(code) != 9:                                   # 1. 길이부터
        return False
    if not ('A' <= code[0] <= 'Z' and 'A' <= code[1] <= 'Z'):   # 2. 대문자 두 글자
        return False
    if code[2] != '-' or code[7] != '-':                 # 3. 하이픈
        return False
    digits = code[3:7]
    if not all('0' <= ch <= '9' for ch in digits):       # 4. 숫자 네 글자
        return False
    total = sum(int(ch) for ch in digits)
    return code[8] == chr(ord('A') + total % 26)         # 5. 검증 문자


def solution(codes):
    bad = [i for i, code in enumerate(codes) if not is_valid(code)]
    return bad if bad else [-1]
