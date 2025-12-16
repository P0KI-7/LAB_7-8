#include "ListNode.h"

#ifndef ProcessList_h
#define ProcessList_h
class ProcessList
{
    ListNode* head;
public:
    // Конструкторы
    ProcessList();
    ProcessList(ListNode* head);
    ProcessList(const ProcessList& other);

    // get/set методы
    ListNode*  getHead() const;
    ListNode*& getHead();

    // Основной функицонал
    bool insert(const PCB& newPCB);   // вставляет новый PCB в список
    bool remove(int pid);  // удаляет PCB из списка по идентификатору
    void printList() const; // выводит информацию о всех процессах в списке
};
#endif  //ProcessList_h