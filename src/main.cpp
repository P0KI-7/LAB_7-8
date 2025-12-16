#include "ProcessList.h"

#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
    // Переключаем консоль в UTF-8
    SetConsoleOutputCP(65001); 
    SetConsoleCP(65001);

    ProcessList list;
    
    // 1. Создание списка процессов
    cout << "1. Создан пустой список процессов." << endl;
    list.printList();
    
    // 2. Добавление элементов
    cout << "\n2. Добавление процессов..." << endl;
    list.insert(PCB(3, "Process3", "Running", 100));
    list.insert(PCB(1, "Process1", "Waiting", 50));
    list.insert(PCB(5, "Process5", "Stopped", 0));
    
    // 3. Вывод списка
    cout << "\n3. Список после вставок:" << endl;
    list.printList();
    
    // 4. Удаление элементов
    cout << "\n4. Удаление процесса с ID=3..." << endl;
    list.remove(3);
    
    // 5. Вывод списка
    cout << "\n5. Список после удаления:" << endl;
    list.printList();
    
    // 6. Попытки неудачной операции
    cout << "\n6. Попытка добавить дубликат (ID=1):" << endl;
    if (!list.insert(PCB(1, "Duplicate", "Running", 0))) {
        cout << "   Ошибка: процесс с ID=1 уже существует!" << endl;
    }
    
    cout << "\n   Попытка удалить несуществующий (ID=99):" << endl;
    if (!list.remove(99)) {
        cout << "   Ошибка: процесс с ID=99 не найден!" << endl;
    }
    
    // 7. Финальный вывод списка
    cout << "\n7. Финальное состояние списка:" << endl;
    list.printList();
    
    return 0;
}