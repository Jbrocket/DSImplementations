#include "dllist.cpp"

int main(){
    int option, data, reverse = 0;

    dllist<int> list;

    std::system("clear");
    do{
        if(!reverse){
            std::cout << "\n";
            list.printList();
            std::cout << "\n\n";
        }
        else{
            std::cout << "\n";
            list.printReverse();
            std::cout << "\n\n";
        }
        std::cout << "1: Insert node to right" << std::endl;
        std::cout << "2: Insert node to left" << std::endl;
        std::cout << "3: Forward print list" << std::endl;
        std::cout << "4: Reverse print list" << std::endl;
        std::cout << "5: Reverse connections on list" << std::endl;
        std::cout << "10: Quit" << std::endl;
        std::cout << "Choose an option by integer value: ";
        std::cin >> option;
        std::system("clear");

        switch(option){
            case 1:
                std::cout << "Enter a value: ";
                std::cin >> data;
                std::system("clear");
                list.insertRight(data);
                break;
            case 2:
                std::cout << "Enter a value: ";
                std::cin >> data;
                std::system("clear");
                list.insertLeft(data);
                break;
            case 3:
                reverse = 0;
                break;
            case 4:
                reverse = 1;
                break;
            case 5:

                break;
            default:
                return 0;
        }

    }while(option != 10);

    return 0;
}