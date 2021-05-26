CC = g++
OBJ = Assn2.cpp Circle.cpp Cross.cpp main.cpp Point.cpp Rectangle.cpp ShapeTwoD.cpp Square.cpp 


EXE = enterprise

all:
	$(CC) $(OBJ) -o $(EXE)
 
clean:
	rm -f $(EXE)