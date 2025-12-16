#include "PCB.h"

PCB::PCB()
    :processID(0), processName(""), processStatus(""),\
        commandCounter(0), cpuRegisters()
{}

PCB::PCB(int processID,std::string processName,std::string processStatus,\
        int commandCounter)
    :processID(processID), processName(processName),\ 
    processStatus(processStatus), commandCounter(commandCounter)
{}

PCB::PCB(const PCB& other)
    :processID(other.processID), processName(other.processName),\ 
    processStatus(other.processStatus), commandCounter(other.commandCounter),\
    cpuRegisters(other.cpuRegisters)
{}