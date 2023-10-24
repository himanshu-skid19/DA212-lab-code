
output: main.o insertion_sort.o sorting.o run.o
	g++ main.o insertion_sort.o sorting.o run.o -o output

main.o: main.cpp
	g++ -c main.cpp

insertion_sort.o : insertion_sort.cpp insertion_sort.h
	g++ -c insertion_sort.cpp

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp

run.o: run.cpp run.h
	g++ -c run.cpp


clean:
	rm *.o output
