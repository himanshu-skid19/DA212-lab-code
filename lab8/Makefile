
output: main.o sorting_algos.o stl_sort.o run.o
	g++ main.o sorting_algos.o stl_sort.o run.o -o output

main.o: main.cpp
	g++ -c main.cpp

sorting_algos.o : sorting_algos.cpp sorting_algos.h
	g++ -c sorting_algos.cpp

stl_sort.o: stl_sort.cpp stl_sort.h
	g++ -c stl_sort.cpp

run.o: run.cpp run.h
	g++ -c run.cpp


clean:
	rm *.o output
