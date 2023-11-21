#include "List.h"
#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1251);
    List<int> myList;

    
    std::cout << "������� �������� ������ (��������� ����� - ����� �� �������� ������): ";
    std::cin >> myList;

    std::cout << "������: " << myList << std::endl;

   
    std::cout << "�������� ������ � �������������� ���������: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    
    auto it = myList.begin();
    ++it; 
    myList.insert(100, it);
    std::cout << "������ ����� ���������� ��������: " << myList << std::endl;

  
    ++it;  
    myList.erase(it);
    std::cout << "������ ����� �������� ��������: " << myList << std::endl;

   
    List<int> otherList;
    otherList.insert(500);
    otherList.insert(600);
    otherList.insert(700);

    std::cout << "������ 2: " << otherList << std::endl;

    
    myList.merge(otherList);
    std::cout << "������ ����� ������� � ������ �������: " << myList << std::endl;

    
    List<int> sortedList;
    sortedList.insert(1);
    sortedList.insert(3);
    sortedList.insert(5);

    
    myList.mergeSorted(sortedList);
    std::cout << "������ ����� ������� � ������������� �������: " << myList << std::endl;

    return 0;
	
}