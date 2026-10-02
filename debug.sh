#!/bin/bash
# 사용법: ./debug.sh mock4/p2 [테스트번호=1] [테스트세트=이름과 같음]
#   - 테스트 하나만 실행해서 cout/cerr 출력을 전부 보여줌
#   - 배열/문자열 범위 밖 접근 등 메모리 오류를 감지해서 메시지로 알려줌
name=$1
num=${2:-1}
test=${3:-$1}
main=""; [ -f "tests/$test/main.cpp" ] && main="tests/$test/main.cpp"
bin="/tmp/${name//\//_}.debug"
g++ -std=c++17 -g -O0 -fsanitize=address,undefined -fno-omit-frame-pointer -D_LIBCPP_HARDENING_MODE=_LIBCPP_HARDENING_MODE_DEBUG -I include \
    -o "$bin" "$name.cpp" $main || exit 1

echo "──── 입력 (tests/$test/$num.in)"
head -c 500 "tests/$test/$num.in"; echo
echo "──── 기대 출력"
head -c 500 "tests/$test/$num.out"
echo "──── 실행 결과 (cout + cerr 전부)"
"$bin" < "tests/$test/$num.in" 2>&1 | grep -v "^    #[0-9]* 0x.* in .*\(libsystem\|libdyld\|dyld\|libclang_rt\)" | head -60
