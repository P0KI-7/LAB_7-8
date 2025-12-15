#include "ListNode.h"

ListNode::ListNode()
    :data(), next()
{
}
ListNode::ListNode(const ListNode& other)
    :data(other.data), next(other.next)
{
}
ListNode::ListNode(PCB data, ListNode* next)
    :data(data), next(next)
{
}

// Getter/setter - методы
int  ListNode::getProcessID() const {return data.processID;};
int& ListNode::setProcessID()       {return data.processID;};
std::string  ListNode::getProcessName() const {return data.processName;};
std::string& ListNode::setProcessName()       {return data.processName;};
std::string  ListNode::getProcessStatus() const {return data.processStatus;};
std::string& ListNode::setProcessStatus()       {return data.processStatus;};
int  ListNode::getCommandCounter() const {return data.commandCounter;};
int& ListNode::setCommandCounter()       {return data.commandCounter;};
std::vector<int>  ListNode::setCpuRegisters() const {return data.cpuRegisters;};
std::vector<int>& ListNode::setCpuRegisters()       {return data.cpuRegisters;};

PCB  ListNode::getData() const {return data;};
PCB& ListNode::setData()       {return data;};    
ListNode  ListNode::getNext() const {return* next;};
ListNode& ListNode::setNext()       {return* next;};