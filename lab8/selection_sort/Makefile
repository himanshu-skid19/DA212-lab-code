
output: main.o selection_sort.o sorting.o run.o
	g++ main.o selection_sort.o sorting.o run.o -o output

main.o: main.cpp
	g++ -c main.cpp

selection_sort.o : selection_sort.cpp selection_sort.h
	g++ -c selection_sort.cpp

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp

run.o: run.cpp run.h
	g++ -c run.cpp


clean:
	rm *.o output
