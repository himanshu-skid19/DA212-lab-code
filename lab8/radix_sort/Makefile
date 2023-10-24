
output: main.o radix_sort.o sorting.o run.o
	g++ main.o radix_sort.o sorting.o run.o -o output

main.o: main.cpp
	g++ -c main.cpp

radix_sort.o : radix_sort.cpp radix_sort.h
	g++ -c radix_sort.cpp

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp

run.o: run.cpp run.h
	g++ -c run.cpp


clean:
	rm *.o output
