#!/bin/bash
# 사용법: ./run_py.sh mock1/p1   → mock1/p1.py 를 tests/mock1/p1/*.in 전부로 채점 (케이스당 10초 제한)
#         ./run_py.sh mock1/p1 다른풀이.py
name=$1
file=${2:-$1.py}
pass=0; total=0
for in in $(ls tests/$name/*.in | sort -V); do
  out=${in%.in}.out
  total=$((total+1))
  got=$(perl -e 'alarm 10; exec @ARGV' python3 pyjudge.py "$name" "$file" < "$in" 2>&1); rc=$?
  if [ $rc -eq 142 ]; then
    echo "⏰ $(basename "$in")  시간 초과 (10초)"
  elif [ "$got" == "$(cat "$out")" ]; then
    pass=$((pass+1)); echo "✅ $(basename "$in")"
  else
    echo "❌ $(basename "$in")  입력: $(head -c 150 "$in" | tr '\n' ' ')"
    echo "   기대: $(head -c 150 "$out")"
    echo "   출력: $(echo "$got" | tail -c 300)"
  fi
done
echo "결과: $pass / $total"
