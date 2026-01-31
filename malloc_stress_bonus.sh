#!/bin/bash

ARGS="$(cat arg)"

for FAIL in $(seq 120 10000); do
    echo "========== FAIL=$FAIL =========="

    # Clean everything
    make fclean > /dev/null

    # Build bonus with malloc fail override
    if ! make bonus CFLAGS="-Wall -Wextra -Werror -g3 -Dmalloc=ft_malloc -DFAIL=$FAIL" >/dev/null; then
        echo "Build failed at FAIL=$FAIL"
        exit 1
    fi

    # Run program
    cat op | valgrind ./checker $ARGS 2>> out
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

