
output: main.o bubble_sort.o sorting.o run.o
	g++ main.o bubble_sort.o sorting.o run.o -o output

main.o: main.cpp
	g++ -c main.cpp

bubble_sort.o : bubble_sort.cpp bubble_sort.h
	g++ -c bubble_sort.cpp

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp

run.o: run.cpp run.h
	g++ -c run.cpp


clean:
	rm *.o output
