/*
 * main.cpp
 *
 *  Created on: 13.12.2023
 *      Author: User
 */


#include<iostream>
#include "SortedList.h"
#include <memory>
#include <stdexcept>
#include <concepts>
#include"SortedList.h"

using namespace std;

int main() {
    try {
        SortedList<int> myList;
        myList.insert(3);
        myList.insert(1);
        myList.insert(4);
        myList.insert(2);

        std::cout << "Sorted List: " << myList << std::endl;

        std::cout << "First element: " << myList.getFirst() << std::endl;
    } catch (const std::out_of_range& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}


