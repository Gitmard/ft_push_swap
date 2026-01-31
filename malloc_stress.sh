#!/bin/bash



ARGS="$(shuf -i $@)"

for FAIL in $(seq 1 120); do
    echo "========== FAIL=$FAIL =========="

    # Build must succeed
    if ! make re CFLAGS="-Wall -Wextra -Werror -g3 -Dmalloc=ft_malloc -DFAIL=$FAIL" >/dev/null; then
        echo "Build failed at FAIL=$FAIL"
        exit 1
    fi

    # Run program
    valgrind ./push_swap --medium $ARGS 2>> out
    STATUS=$?

    if [ $STATUS -eq 139 ]; then
        echo "Segfault at FAIL=$FAIL"
        exit 1
    fi

    if [ $STATUS -ne 0 ]; then
        echo "Handled malloc failure at FAIL=$FAIL (exit $STATUS)"
    else
        echo "OK (no failure triggered)"
    fi

    echo
done

make fclean
