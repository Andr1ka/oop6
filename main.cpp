#include "List.h"
#include <iostream>
#include <Windows.h>

int main() {
    SetConsoleOutputCP(1251);
    List <int> ls;
    ls.insert(1);
    ls.insert(2);
    ls.insert(3);
    List <int> ls2(ls);
    std::cout << ls2;
    std::cout << std::endl;

    List <int> ls3;
    ls3.insert(1);
    ls3.insert(2);
    ls3.insert(3);
    List <int> ls4;
    ls4.insert(1231);
    ls4 = ls3;
    std::cout << ls3;
    return 0;
	
}