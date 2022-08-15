CMP = g++ -std=c++2a
OBJ = obj
EXE = exe
FLAGS = -Werror -Wextra -O2 -Wconversion -Wall

all: sllist bst dll

## CREATE DIRECTORIES FOR COMPILED FILES ##
init:
	mkdir exe obj

##################################
## RULES FOR SINGLY LINKED LIST ##
sllist: $(EXE)/sllist ## EASIER COMMAND TO TYPE

$(EXE)/sllist: LinkedList/main.cpp $(OBJ)/sllist.o
	$(CMP) $(FLAGS) LinkedList/main.cpp $(OBJ)/sllist.o -o $(EXE)/sllist

$(OBJ)/sllist.o: LinkedList/sllist.cpp LinkedList/sllist.h
	$(CMP) -c LinkedList/sllist.cpp -o $(OBJ)/sllist.o
##################################

##################################
## RULES FOR BINARY SEARCH TREE ##
bst: $(EXE)/bst ## EASIER COMMAND TO TYPE

$(EXE)/bst: BST/main.cpp $(OBJ)/bst.o
	$(CMP) $(FLAGS) BST/main.cpp $(OBJ)/bst.o -o $(EXE)/bst

$(OBJ)/bst.o: BST/bst.cpp BST/bst.h
	$(CMP) -c BST/bst.cpp -o $(OBJ)/bst.o
##################################

##################################
## RULES FOR DOUBLY LINKED LIST ##
dll: $(EXE)/dll ## EASIER COMMAND TO TYPE

$(EXE)/dll: DoublyLinkedList/main.cpp $(OBJ)/dll.o
	$(CMP) $(FLAGS) DoublyLinkedList/main.cpp $(OBJ)/dll.o -o $(EXE)/dll

$(OBJ)/dll.o: DoublyLinkedList/dllist.hh DoublyLinkedList/dllist.cpp
	$(CMP) -c DoublyLinkedList/dllist.cpp -o $(OBJ)/dll.o
##################################

##################################
## RULES FOR QUEUE ##


##################################

##################################
## RULES FOR STACK ##


##################################

##################################
## RULES FOR UNWEIGHTED GRAPH ##


##################################

##################################
## RULES FOR WEIGHTED GRAPH ##


##################################
## RULES FOR UNION FIND ##


## CLEAN EXECUTABLES OUT
clean:
	rm -rf ./$(EXE)/* ./$(OBJ)/*

## GET RID OF ALL CREATED FOLDERS AND FILES
sterilize:
	rm -rf ./$(EXE) ./$(OBJ) ./.vscode