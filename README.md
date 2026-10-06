# SK하이닉스 코딩테스트 대비

C++ 기준으로 준비한 모의고사와 정답 모음입니다. 모든 문제에 **C++ 정답(`.cpp`)과 Python 정답(`.py`)**이 있고, 둘 다 테스트를 전부 통과합니다.

## 구성
| 폴더 / 파일 | 내용 |
|---|---|
| `mock1/` ~ `mock7/` | 모의고사 1~7회 (회차당 4문제). `pN.md` 문제, `pN.cpp` / `pN.py` 정답 |
| `gemini1/` | 추가 문제 3개. `pN.txt` 문제, `pN.cpp` / `pN.py` 정답 |
| `editor1.*` | 연습 문제 (되돌리기가 있는 편집기) |
| `오답노트.md` | 자주 틀린 유형 정리 (틀린 코드 → 맞는 코드) |
| `tests/` | 채점용 입력/출력, C++용 `main.cpp`, 허용 헤더 목록 |
| `include/bits/stdc++.h` | Mac clang용 대체 헤더 |

## 난이도
| 회차 | 난이도 |
|---|---|
| 1~3회 | 실전보다 어려움 (3·4번이 골드 상위) |
| 4·5회 | 실전 수준 |
| 6회 | 실전보다 어려움 |
| 7회 | 5회와 6회 사이 |

2회부터는 실전 후기에 맞춰 **`<string>`, `<vector>` 헤더만** 사용합니다. 그래서 C++ 정답은 `sort`, `queue`, `map` 없이 직접 구현했습니다. Python 정답은 표준 라이브러리를 자유롭게 사용합니다.

## 채점
```bash
./run.sh mock1/p1                 # C++ : mock1/p1.cpp 채점 (케이스당 2초)
./run.sh 내풀이 mock1/p1          # C++ : 내풀이.cpp 를 mock1/p1 테스트로 채점
./run_py.sh mock1/p1              # Python : mock1/p1.py 채점 (케이스당 10초)
./run_py.sh mock1/p1 내풀이.py    # Python : 다른 파일 채점
./debug.sh mock1/p1 3             # C++ : 3번 테스트만 실행해서 출력 전부 보기
```
C++ 풀이에는 `solution` 함수만 작성합니다. 입력을 읽는 `main`은 `tests/<문제>/main.cpp`에 있습니다. Python도 `solution` 함수만 작성하면 `pyjudge.py`가 같은 형식으로 입력을 넣어줍니다.
