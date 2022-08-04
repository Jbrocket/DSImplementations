#include "sllist.cpp"

int main(){
    int option = 0;
    // sllist<int> *myList = new sllist<int>();
    // sllist<int> newList = *myList;
    sllist<int> newList;

    int data;
    do{
        std::cout << "1. Insert Right" << std::endl;
        std::cout << "2. Insert Left" << std::endl;
        std::cout << "3. Print List" << std::endl;
        std::cout << "4. Get Length" << std::endl;
        std::cout << "6. Quit" << std::endl;
        std::cout << "\n" << "Enter an integer corresponding with an option: ";
        std::cin >> option;

        switch (option) {
            case 1:
                std::cout << "Input data: ";
                std::cin >> data;
                newList.insertRight(data);
                break;
            case 2:
                std::cout << "Input data: ";
                std::cin >> data;
                newList.insertLeft(data);
                break;
            case 3:
                newList.printList();
                break;
            case 4:
                std::cout << "\nSize: " << newList.size() << "\n" << std::endl;
                break;
            case 5:
                newList.printList();
                std::cout << "Where do you want to insert num?: " << std::endl;
                std::cin >> data;
                //newList.insertAt(data);
                break;
            default:
                return 0;
        }
        
    } while( option != 6);

    return 0;
}