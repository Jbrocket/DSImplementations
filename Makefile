CMP = g++ -std=c++2a
OBJ = obj
EXE = exe

all: $(EXE)/sllist $(EXE)/bst

## CREATE DIRECTORIES FOR COMPILED FILES
init:
	mkdir exe obj

## RULES FOR SINGLY LINKED LIST
$(EXE)/sllist: LinkedList/main.cpp $(OBJ)/sllist.o
	$(CMP) LinkedList/main.cpp $(OBJ)/sllist.o -o $(EXE)/sllist

$(OBJ)/sllist.o: LinkedList/sllist.cpp LinkedList/sllist.h
	$(CMP) -c LinkedList/sllist.cpp -o $(OBJ)/sllist.o

## RULES FOR BINARY SEARCH TREE
$(EXE)/bst: BST/main.cpp $(OBJ)/bst.o
	$(CMP) BST/main.cpp $(OBJ)/bst.o -o $(EXE)/bst

$(OBJ)/bst.o: BST/bst.cpp BST/bst.h
	$(CMP) -c BST/bst.cpp -o $(OBJ)/bst.o


## CLEAN EXECUTABLES OUT
clean:
	rm -rf ./$(EXE)/* ./$(OBJ)/*

## GET RID OF ALL CREATED FOLDERS AND FILES
sterilize:
	rm -rf ./$(EXE) ./$(OBJ)