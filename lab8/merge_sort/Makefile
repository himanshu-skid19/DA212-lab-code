
output: main.o merge_sort.o sorting.o run.o
	g++ main.o merge_sort.o sorting.o run.o -o output

main.o: main.cpp
	g++ -c main.cpp

merge_sort.o : merge_sort.cpp merge_sort.h
	g++ -c merge_sort.cpp

sorting.o: sorting.cpp sorting.h
	g++ -c sorting.cpp

run.o: run.cpp run.h
	g++ -c run.cpp


clean:
	rm *.o output
