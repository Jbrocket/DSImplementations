all: sllist

init:
	mkdir exe

sllist: LinkedList/main.cpp Linkedlist/sllist.cpp
	g++ LinkedList/main.cpp Linkedlist/sllist.cpp -o exe/sllist

clean:
	rm -rf ./exe/*

clean_exe:
	rm -rf ./exe