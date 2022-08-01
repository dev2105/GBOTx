#include "GDMem.h"
using namespace std; 

GDMem::GDMem(){
    // BASE ADDRESS CHANGES EACHTIME NEW LEVEL IS LOADED, BE SURE TO REFIND ALL OFFSETS ONCE THAT HAPPENS!!!!
    // - GET PROCID
    procID = getProcID("Geometry Dash");

    // - GET THE HANDLE TO THE PROCESS WITH ADMIN PERMISSIONS
    handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);
    
    // - GET BASE ADDRESS
    base = GetModuleBaseAddress(procID, name);
    uintptr_t baseBack = base;
    cout << "Base address:" << base << endl;
    // dereference the pointer to the base address to get the actual address 
    vector<uint32_t> offsets = { 0x3222D0, 0x164, 0x224};
    
    do {
        base = baseBack;

        for (auto i : offsets) {
            ReadProcessMemory(handle, (LPCVOID)(base + i), &base, sizeof(uint32_t), 0);
            
        }
    } while (!(base));
    cout << "Base address:" << base << endl;
    // add the final offset (no need to dereference further)
    base += 0x600;
    ref = memRef(base);

}

void GDMem :: hold() {
    int temp = 1;
    WriteProcessMemory(handle, (LPVOID)(ref.hold), &temp, sizeof(uint32_t), 0);
}

void GDMem::stopHold() {
    int temp = 0;
    WriteProcessMemory(handle, (LPVOID)(ref.hold), &temp, sizeof(uint32_t), 0);
}

void GDMem::jump() {
    hold();
    stopHold();
}

int GDMem::isDead() {
    int death = false; 
    ReadProcessMemory(handle, (LPCVOID)(ref.death), &death, sizeof(uint32_t), 0);
    return death;
}

int GDMem::isWave() {
    int wave = 0;
    ReadProcessMemory(handle, (LPCVOID)(ref.wave), &wave, sizeof(uint32_t), 0);
    return wave;
}

float GDMem::getX(){
    float x = 0;
    ReadProcessMemory(handle, (LPCVOID)(ref.x), &x, sizeof(uint32_t), 0);
    //cout << x << endl;
    return x;
}

float GDMem::getY(){
    float y = 0;
    ReadProcessMemory(handle, (LPCVOID)(ref.y), &y, sizeof(uint32_t), 0);
    return y;
}
void GDMem::setX(float x){
    WriteProcessMemory(handle, (LPVOID)(ref.x), &x, sizeof(uint32_t), 0);
}
void GDMem::setY(float y){
    WriteProcessMemory(handle, (LPVOID)(ref.y), &y, sizeof(uint32_t), 0);
}