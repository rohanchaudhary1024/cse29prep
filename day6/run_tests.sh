#!/bin/bash
mkdir -p build
fails=0

for t in test_*.c; do
	name="${t%.c}"
	if gcc "$t" mystring.c -o "build/$name" -Wall 2>build/err; then
		if "./build/$name"; then :; else echo "FAILED: $name"; fails=1; fi
	else
		echo "DID NOT COMPILE: $t"
		cat build/err
		fails=1
	fi
done

if [ "$fails" -eq 0 ]; then
	echo "--- all test files passed ---"
else
	echo "--- something failed ---"
fi
exit $fails

