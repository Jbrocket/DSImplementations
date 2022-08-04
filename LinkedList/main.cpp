#include "sllist.cpp"

int main(){
    int option = 0;
    sllist<int> *myList = new sllist<int>();
    int data;
    do{
        std::cout << "1. Insert Right" << std::endl;
        std::cout << "2. Insert Left" << std::endl;
        std::cout << "3. Print List" << std::endl;
        std::cout << "6. Quit" << std::endl;
        std::cout << "\n" << "Enter an integer corresponding with an option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "Input data: ";
                std::cin >> data;
                myList->insertRight(data);
                break;
            case 2:
                std::cout << "Input data: ";
                std::cin >> data;
                myList->insertLeft(data);
                break;
            case 3:
                myList->printList();
                break;
            default:
                delete myList;
                return 0;
        }
        
    } while( option != 6);

    return 0;
}