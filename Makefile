all: sllist bst

init:
	mkdir exe

sllist: LinkedList/main.cpp Linkedlist/sllist.cpp
	g++ LinkedList/main.cpp Linkedlist/sllist.cpp -o exe/sllist

bst: BST/main.cpp BST/bst.cpp
	g++ BST/main.cpp BST/bst.cpp -o exe/bst

clean:
	rm -rf ./exe/*

clean_exe:
	rm -rf ./exe