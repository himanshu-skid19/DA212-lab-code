
output: main.o shortest_path.o  run.o
	g++ main.o shortest_path.o run.o -o output

main.o: main.cpp
	g++ -c main.cpp

shortest_path.o: shortest_path.cpp shortest_path.h
	g++ -c shortest_path.cpp

run.o: run.cpp run.h
	g++ -c run.cpp


clean:
	rm *.o output
