
output: main.o quicksort.o sorting.o run.o
	g++ main.o quicksort.o sorting.o run.o -o output

main.o: main.cpp
	g++ -c main.cpp

quicksort.o : quicksort.cpp quicksort.h
	g++ -c quicksort.cpp

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp

run.o: run.cpp run.h
	g++ -c run.cpp


clean:
	rm *.o output
