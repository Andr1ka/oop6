#include "List.h"
#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1251);
    List<int> myList;

    
    std::cout << "Введите элементы списка: ";
    std::cin >> myList;

    std::cout << "Список: " << myList << std::endl;

   
    std::cout << "Элементы списка с использованием итератора: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    auto it = myList.begin();
    ++it; 
    myList.insert(100, it);
    std::cout << "Список после добавления элемента: " << myList << std::endl;

  
    ++it;  
    myList.erase(it);
    std::cout << "Список после удаления элемента: " << myList << std::endl;

   
    List<int> otherList;
    otherList.insert(100);
    otherList.insert(101);
    otherList.insert(503);

    std::cout << "Список 2: " << otherList << std::endl;

    
    myList.merge(otherList);
    std::cout << "Список после слияния с другим списком: " << myList << std::endl;

    
    List<int> sortedList;
    sortedList.insert(1);
    sortedList.insert(3);
    sortedList.insert(5);

    
    myList.mergeSorted(sortedList);
    std::cout << "Список после слияния с упорядоченным списком: " << myList << std::endl;

    return 0;
	
}