
output: main.o binary_search_tree.o task3.o  run.o
	g++ main.o binary_search_tree.o task3.o  run.o -o output

main.o: main.cpp
	g++ -c main.cpp

binary_search_tree.o: binary_search_tree.cpp binary_search_tree.h
	g++ -c binary_search_tree.cpp

task3.o: task3.cpp task3.h
	g++ -c task3.cpp

run.o: run.cpp run.h
	g++ -c run.cpp


clean:
	rm *.o output
