CC = g++
INCLUDES = ../files/
CFLAGS = -I$(INCLUDES) -O3
OBBJS = graph.o node_escola.o node_professor.o

emparelha: $(OBBJS) main.cpp
	$(CC) -o $@ $^ $(CFLAGS)

main.o: main.cpp graph.o node_escola.o node_professor.o

graph.o: node_escola.o node_professor.o

node_escola.o: node_escola.cpp

node_professor.o: node_professor.cpp

.PHONY: clean run

clean:
	rm *.o emparelha
	
run: emparelha
	./emparelha
