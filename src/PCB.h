#include <string>
#include <vector>

#ifndef PCB_h
#define PCB_h
struct PCB {
    int processID;
    std::string processName;
    std::string processStatus;
    int commandCounter;
    std::vector<int> cpuRegisters;

    PCB();
    PCB(int processID,std::string processName,\
        std::string processStatus,int commandCounter);
    PCB(const PCB& other);
};
#endif //PCB_h