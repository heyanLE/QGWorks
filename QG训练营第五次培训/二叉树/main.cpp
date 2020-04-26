#include <iostream>
#include <cstdlib>
#include <ctime>
#include "inc/qgsort.h"
#include "inc/largearray.h"
#include "inc/smallarray.h"

int start(){
    system("cls");
    std:: cout << "What would you like to do ?" << std::endl
            << "1. Sort large array ;"  << std::endl
            << "2. Sort large number of small arrays ;"  << std::endl
            << "3. Exit ;"  << std::endl;;

    int input;
    std::cin >> input;

    if(input == 1){
        testLargeArray();
        return 1;
    }else if(input == 2){
        testSmallArray();
        return 1;
    } else if(input == 3){
        std:: cout << "Bye ~~" << std::endl;
        system("pause");
        return 0;
    }else{
        std:: cout << "Please enter the right number" << std::endl;
        system("pause");
        return 1;
    }

}

int main() {
    std::cout << "Welcome !! I am Guangchuan Lin" << std::endl
                << "This is my forth homework !" << std::endl
                << "Hope it can satisfy you ! " << std::endl;
    system("pause");

    while(start());



    return 0;
}
