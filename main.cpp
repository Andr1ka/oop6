#include "List.h"
#include <iostream>

int main() {
    SetConsoleOutputCP(1251);
    List<int> myList;

    // ���� ��������� ������ � ����������
    std::cout << "������� �������� ������ (��������� ����� - ����� �� �������� ������): ";
    std::cin >> myList;

    std::cout << "������: " << myList << std::endl;

    // �������� ������ ����������
    std::cout << "�������� ������ � �������������� ���������: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // ���������� �������� �� ���������
    auto it = myList.begin();
    ++it;  // ��������� �� ������� ��������
    myList.insert(100, it);
    std::cout << "������ ����� ���������� ��������: " << myList << std::endl;

    // �������� �������� �� ���������
    ++it;  // ��������� � �������� ��������
    myList.erase(it);
    std::cout << "������ ����� �������� ��������: " << myList << std::endl;

    // �������� ������� ������
    List<int> otherList;
    otherList.insert(500, nullptr);
    otherList.insert(600, nullptr);
    otherList.insert(700, nullptr);

    std::cout << "������ 2: " << otherList << std::endl;

    // ������� ���� �������
    myList.merge(otherList);
    std::cout << "������ ����� ������� � ������ �������: " << myList << std::endl;

    // �������� �������� ������
    List<int> sortedList;
    sortedList.insert(1, nullptr);
    sortedList.insert(3, nullptr);
    sortedList.insert(5, nullptr);

    // ������� ���� ������������� �������
    myList.mergeSorted(sortedList);
    std::cout << "������ ����� ������� � ������������� �������: " << myList << std::endl;

    return 0;
	return 0;
}