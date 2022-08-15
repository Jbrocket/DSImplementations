#include "dllist.cpp"

int main(){
    int option, data;

    dllist<int> list;

    do{
        std::cout << "1: Insert node to right" << std::endl;
        std::cout << "2: Insert node to left" << std::endl;
        std::cout << "3: Print list" << std::endl;
        std::cout << "4: Print list in reverse" << std::endl;
        // std::cout << "5: print level order" << std::endl;
        std::cout << "10: Quit" << std::endl;
        std::cout << "Choose an option by integer value: ";
        std::cin >> option;

        switch(option){
            case 1:
                std::cout << "Enter a value: ";
                std::cin >> data;
                list.insertRight(data);
                break;
            case 2:
                std::cout << "Enter a value: ";
                std::cin >> data;
                list.insertLeft(data);
                break;
            case 3:
                std::cout << "\n" << "Current list:";
                list.printList();
                std::cout << "\n\n";
                break;
            case 4:
                std::cout << "\n" << "Current list:";
                list.printReverse();
                std::cout << "\n\n";
                break;
            case 5:

                break;
            default:
                return 0;
        }

    }while(option != 10);

    return 0;
}