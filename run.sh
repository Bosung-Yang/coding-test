#!/bin/bash
# 사용법: ./run.sh editor1  또는  ./run.sh mock1/p1   → 컴파일 후 tests/<이름>/*.in 전부 채점 (케이스당 2초 제한)
name=$1
test=${2:-$1}   # 두 번째 인자로 다른 테스트 세트 지정 가능 (예: ./run.sh mock1/p2answer mock1/p2)
main=""; [ -f "tests/$test/main.cpp" ] && main="tests/$test/main.cpp"
g++ -std=c++17 -O2 -Wall -I include -o "/tmp/${name//\//_}.bin" "$name.cpp" $main || exit 1
# 허용 헤더 검사 (tests/<이름>/allowed 에 적힌 헤더만 허용)
if [ -f "tests/$test/allowed" ]; then
  for h in $(grep -oE '#include *<[^>]+>' "$name.cpp" | sed -E 's/.*<(.*)>/\1/'); do
    grep -qx "$h" "tests/$test/allowed" || echo "⚠️  허용되지 않은 헤더: <$h>  (실전에서는 감점될 수 있음)"
  done
fi
pass=0; total=0
for in in $(ls tests/$test/*.in | sort -V); do
  out=${in%.in}.out
  total=$((total+1))
  got=$(perl -e 'alarm 2; exec @ARGV' "/tmp/${name//\//_}.bin" < "$in"); rc=$?
  if [ $rc -eq 142 ]; then
    echo "⏰ $(basename "$in")  시간 초과 (2초)"
  elif [ "$got" == "$(cat "$out")" ]; then
    pass=$((pass+1)); echo "✅ $(basename "$in")"
  else
    echo "❌ $(basename "$in")  입력: $(head -c 150 "$in" | tr '\n' ' ')"
    echo "   기대: $(head -c 150 "$out")"
    echo "   출력: $(echo "$got" | head -c 150)"
  fi
done
echo "결과: $pass / $total"
