#include "List.h"
#include <iostream>

int main() {
    SetConsoleOutputCP(1251);
    List<int> myList;

    // Ввод элементов списка с клавиатуры
    std::cout << "Введите элементы списка (окончание ввода - любой не числовой символ): ";
    std::cin >> myList;

    std::cout << "Список: " << myList << std::endl;

    // Проверка работы итераторов
    std::cout << "Элементы списка с использованием итератора: ";
    for (auto it = myList.begin(); it != myList.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;

    // Добавление элемента по итератору
    auto it = myList.begin();
    ++it;  // Переходим ко второму элементу
    myList.insert(100, it);
    std::cout << "Список после добавления элемента: " << myList << std::endl;

    // Удаление элемента по итератору
    ++it;  // Переходим к третьему элементу
    myList.erase(it);
    std::cout << "Список после удаления элемента: " << myList << std::endl;

    // Создание второго списка
    List<int> otherList;
    otherList.insert(500, nullptr);
    otherList.insert(600, nullptr);
    otherList.insert(700, nullptr);

    std::cout << "Список 2: " << otherList << std::endl;

    // Слияние двух списков
    myList.merge(otherList);
    std::cout << "Список после слияния с другим списком: " << myList << std::endl;

    // Создание третьего списка
    List<int> sortedList;
    sortedList.insert(1, nullptr);
    sortedList.insert(3, nullptr);
    sortedList.insert(5, nullptr);

    // Слияние двух упорядоченных списков
    myList.mergeSorted(sortedList);
    std::cout << "Список после слияния с упорядоченным списком: " << myList << std::endl;

    return 0;
	return 0;
}