#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;


class PCB{
public:
    string name;        //进程名
    int runnigTime;     //要求运行时间
    int priority;       //优先级
    char state;          //状态

    void PrintPCB(){
        cout << "进程" << name << " 状态" << state << " 剩余时间" << runnigTime << " 优先级" << priority << endl;
    }
};

bool cmp(PCB x, PCB y){
    return x.priority > y.priority;
}

int main() {
    PCB a[5];
    string _name;
    int _time;
    int _priority;
    char _state;

    cout << "请输入 进程名 状态 运行时间 优先级" <<endl;
    for(int i = 0; i < 5; i++){
        cout << i+1 << ":";
        cin >> _name >> _state >> _time >> _priority;
        a[i].name = _name;
        a[i].runnigTime = _time;
        a[i].priority = _priority;
        a[i].state = _state;
        a[i].PrintPCB();
    }
    sort(a, a+5, cmp);

    vector<PCB> pcb;
    cout << "--------------------------" << endl;
    for(int i = 0; i < 5; i++){
        a[i].PrintPCB();
        pcb.push_back(a[i]);
    }
    cout << "--------------------------" << endl;
    int index = 0;
    while(!pcb.empty()){
        PCB processNow = pcb.front();
        pcb.erase(pcb.begin());
        cout << index++ << ": 进程" << processNow.name << " 状态：" << processNow.state
             << " 当前剩余时间：" << processNow.runnigTime << " 当前优先级：" << processNow.priority
             << " 运行后剩余时间：" << processNow.runnigTime-1 << " 运行后优先级：" << processNow.priority-1 << endl;
        processNow.priority--;
        processNow.runnigTime--;
        if(processNow.runnigTime > 0){
            pcb.push_back(processNow);
        }
        sort(pcb.begin(), pcb.end(), cmp);

    }

    return 0;
}
