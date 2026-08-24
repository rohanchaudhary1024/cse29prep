#!/bin/bash
fails=0

for t in test_*.c; do
	name="${t%.c}"
	if gcc "$t" mystring.c -o "/tmp/$name" -Wall 2>/tmp/err; then
		if "/tmp/$name"; then :; else echo "FAILED: $name"; fails=1; fi
	else
		echo "DID NOT COMPILE: $t"
		cat /tmp/err
		fails=1
	fi
done

if [ "$fails" -eq 0 ]; then
	echo "--- all test files passed ---"
else
	echo "--- something failed ---"
fi
exit $fails

