#include "bst.cpp"

int main(){
    int option = 0;
    bst<int> myBST;
    int data;

    do{
        std::cout << "1: Insert Node" << std::endl;
        std::cout << "2: Print preorder" << std::endl;
        std::cout << "3: Print inorder" << std::endl;
        std::cout << "4: Print postorder" << std::endl;
        std::cout << "5: print level order" << std::endl;
        std::cout << "6: Quit" << std::endl;
        std::cout << "Choose an option by integer value: ";
        std::cin >> option;

        switch(option){
            case 1:
                std::cout << "What value will the node have: ";
                std::cin >> data;
                myBST.insertNode(data);
                break;
            case 2:
                std::cout << std::endl;
                myBST.preOrder();
                std::cout << std::endl;
                break;
            case 3:
                std::cout << std::endl;
                myBST.inOrder();
                std::cout << std::endl;
                break;
            case 4:
                std::cout << std::endl;
                myBST.postOrder();
                std::cout << std::endl;
                break;
            case 5:
            
                break;
            default:
                return 0;
                break;
        }
    }while(option != 6);

    return 0;
}