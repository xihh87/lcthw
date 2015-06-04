echo "Running unit tests:"

for i in tests/*_tests
do
	if test -f $i
	then
		if $VALGRIND ./$i ./build/libex29.so print_a_message "Hello there" 2>> tests/tests.log &&
			$VALGRIND ./$i ./build/libex29.so uppercase "Hello there" 2>> tests/tests.log && 
			$VALGRIND ./$i ./build/libex29.so lowercase "Hello there" 2>> tests/tests.log &&
			! $VALGRIND ./$i ./build/libex29.so fail_on_purpose "Hello there" 2>> tests/tests.log &&
			! $VALGRIND ./$i ./build/libex.so fail_on_purpose "Hello there" 2>> tests/tests.log &&
			! $VALGRIND ./$i ./build/libex29.so on_purpose "Hello there" 2>> tests/tests.log 

		then
			echo $i PASS
		else
			echo "ERROR in test $i: here's tests/tests.log"
			echo "------"
			tail tests/tests.log
			exit 1
		fi
	fi
done

echo ""
