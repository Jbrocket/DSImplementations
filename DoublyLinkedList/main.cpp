#include "dllist.cpp"

int main(){
    int option, data, reverse = 0, pos, length = 0;

    dllist<int> list;

    std::system("clear");
    do{
        std::system("clear");
        if(!reverse){
            std::cout << "\n" << list.printList();
            if(length)
                std::cout << "\nLength of list: " << list.size();
            std::cout << "\n\n";
        }
        else{
            std::cout << "\n" << list.printReverse();
            if(length)
                std::cout << "\nLength of list: " << list.size();
            std::cout << "\n\n";
        }
        std::cout << "1: Insert node to right" << std::endl;
        std::cout << "2: Insert node to left" << std::endl;
        std::cout << "3: Forward print list" << std::endl;
        std::cout << "4: Reverse print list" << std::endl;
        std::cout << "5: Reverse connections on list" << std::endl;
        std::cout << "6: Insert at Index (0 indexing)" << std::endl;
        std::cout << "7: Remove by Value" << std::endl;
        std::cout << "8: Remove by Index (0 indexing)" << std::endl;
        std::cout << "9: Toggle print size" << std::endl;
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
                list.reverseList();
                break;
            case 6:
                std::cout << "Enter the position: ";
                std::cin >> pos;
                std::cout << "\nEnter the data of the node: ";
                std::cin >> data;
                list.insertAt(pos, data);
                break;
            case 7:
                std::cout << "Enter the data of the node to delete: ";
                std::cin >> data;
                list.removeNodeByValue(data);
                break;
            case 8:
                std::cout << "Enter the position of the node to delete: ";
                std::cin >> pos;
                list.removeNodeByIndex(pos);
                break;
            case 9:
                if(!length)
                    length = 1;
                else
                    length = 0;
                break;
            default:
                return 0;
        }

    }while(option != 10);

    return 0;
}