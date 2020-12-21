How to use test_assig2.pl:
1. Make sure you have perl installed, it will be best to use the CSE machines
2. Make sure the script is executable, to do this type: chmod u+x test_assig2.pl
3. If the tests and your compiled solution file are all in the same directory simply type ./test_assig2.pl
4. Otherwise you can provide the location as an argument: ./test_assig2.pl ../poG
5. You can provide the location of the tests input file as a second argument: ./test_assig2.pl ../poG ../tests.in
6. The test output files should be located in the same directory as the test_assig2.pl script, if they aren't found then it will simply create them based on your solutions output. This isn't a test in itself but it can help ensure your output doesn't change, or allow you to share your output with other people.

It would be a good idea to test for memory leaks as well, you can do this using Valgrind:
valgrind --leak-check=yes ./poG 1155