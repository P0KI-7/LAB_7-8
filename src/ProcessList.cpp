#include "ProcessList.h"

#include <iostream>

// Конструкторы
ProcessList::ProcessList()
    :head()
{}
ProcessList::ProcessList(ListNode* head)
    :head(head)
{}
ProcessList::ProcessList(const ProcessList& other)
    :head(other.head)
{}

// Методы
ListNode*  ProcessList::getHead() const {return head;};
ListNode*& ProcessList::getHead()       {return head;};

bool ProcessList::insert(const PCB& newPCB)
{
    ListNode* newNode = new ListNode(newPCB,nullptr);

    if (head == nullptr) {
        head = newNode;
        return true;
    }
    if (newPCB.processID < head->getProcessID()) {
        newNode->setNext() = head;
        head = newNode;
        return true;
    }
    if (newPCB.processID == head->getProcessID()) {
        delete newNode;
        return false;
    }

    ListNode* current = head;
    while (current->getNext() != nullptr) {
        if (newPCB.processID == current->getNext()->getProcessID()) {
            delete newNode;
            return false;
        }

        if (newPCB.processID < current->getNext()->getProcessID()) {
            newNode->setNext() = current->getNext();
            current->setNext() = newNode;
            return true;
        }

        current = current->getNext();
    }

    current->setNext() = newNode;
    return true;
}

bool ProcessList::remove(int pid)
{
    if (head == nullptr) {
        return false;
    }
    if (head->getProcessID() == pid) {
        ListNode* toDelete = head;
        head = head->getNext();
        delete toDelete;
        return true;
    }

    ListNode* current = head;
    while (current->getNext() != nullptr) {
        if (current->getNext()->getProcessID() == pid) {
            ListNode* toDelete = current->getNext();
            current->setNext() = current->getNext()->getNext();
            delete toDelete;
            return true;
        }
        current = current->getNext();
    }

    return false;
}

void ProcessList::printList() const
{
    if (head == nullptr) {
        std::cout << "Список процессов пуст..." << std::endl;
    }
    else {
        ListNode* current = head;
        size_t count = 0;

        std::cout << "\n=== Списко процессов ===" << std::endl;
        while (current != nullptr) {
            std::cout << "--- Процесс №" << ++count << " ---" << std::endl; 
            std::cout << "ID: " << current->getProcessID() << std::endl;
            std::cout << "Имя: " << current->getProcessName() << std::endl;
            std::cout << "Статус: " << current->getProcessStatus() << std::endl;
            std::cout << "Счётчик команд: " << current->getCommandCounter() << std::endl;
            std::cout << "Регистры CPU: ";
            for (int i = 0; i < current->getCpuRegisters().size(); ++i) {
                std::cout << current->getCpuRegisters()[i] << " ";
            }
            std::cout << std::endl << std::endl;

            current = current->getNext();
        }

        std::cout << "Всего процессов: " << count << "." << std::endl;
    }
}