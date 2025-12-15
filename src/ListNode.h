#include "PCB.h"

#ifndef ListNode_h
#define ListNode_h
class ListNode {
    PCB data;
    ListNode* next;
public:
    ListNode();
    ListNode(PCB data, ListNode* next);
    ListNode(const ListNode& other);

    int  getProcessID() const;
    int& setProcessID();
    std::string  getProcessName() const;
    std::string& setProcessName();
    std::string  getProcessStatus() const;
    std::string& setProcessStatus();
    int  getCommandCounter() const;
    int& setCommandCounter();
    std::vector<int>  setCpuRegisters() const;
    std::vector<int>& setCpuRegisters();

    PCB  getData() const;
    PCB& setData();
    ListNode*  getNext() const;
    ListNode*& setNext();
};
#endif // ListNode_h