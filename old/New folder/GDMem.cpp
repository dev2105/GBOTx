#include "GDMem.h"
using namespace std; 

GDMem::GDMem() {
    // - GET PROCID
    procID = getProcID("Geometry Dash");

    // - GET THE HANDLE TO THE PROCESS WITH ADMIN PERMISSIONS
    handle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procID);

}

void GDMem::setBase(uintptr_t baseAddy) {

    cout << "Base address:" << base << endl;
    // add the final offset (no need to dereference further)
 
    base = baseAddy;
    if (base){ 
        base += 0x600; 
        ref = memRef(base); }
}

uintptr_t GDMem::getBase() {
    // BASE ADDRESS CHANGES EACHTIME NEW LEVEL IS LOADED, BE SURE TO REFIND ALL OFFSETS ONCE THAT HAPPENS!!!!
    // - GET BASE ADDRESS

    // Check if the baseBack is already assigned

    if (!baseBack) {
        base = GetModuleBaseAddress(procID, name);
        baseBack = base;
    }

    // dereference the pointer to the base address to get the actual address 
    vector<uint32_t> offsets = { 0x3222D0, 0x164, 0x224 };
    // 3,286,616
    int x = 0x1E6DA0;

    // set the base address to default value if level is not loaded
    base = baseBack;
    for (auto i : offsets) {
        ReadProcessMemory(handle, (LPCVOID)(base + i), &base, sizeof(uint32_t), 0);
    }
    return base;
}
void GDMem :: hold() {
    bool temp = true;
    WriteProcessMemory(handle, (LPVOID)(ref.hold), &temp, sizeof(bool), 0);
}

void GDMem::stopHold() {
    bool temp = false;
    WriteProcessMemory(handle, (LPVOID)(ref.hold), &temp, sizeof(bool), 0);
}

void GDMem::jump() {
    hold();
    stopHold();
}

bool GDMem::isDead() {
    bool death = false; 
    ReadProcessMemory(handle, (LPCVOID)(ref.death), &death, sizeof(bool), 0);
    return death;
}

bool GDMem::isWave() {
    bool wave = false;
    ReadProcessMemory(handle, (LPCVOID)(ref.wave), &wave, sizeof(bool), 0);
    return wave;
}

float GDMem::getX(){
    float x = 0;
    ReadProcessMemory(handle, (LPCVOID)(ref.x), &x, sizeof(float), 0);
    //cout << x << endl;
    return x;
}

float GDMem::getY(){
    float y = 0;
    ReadProcessMemory(handle, (LPCVOID)(ref.y), &y, sizeof(float), 0);
    return y;
}
void GDMem::setX(float x){
    WriteProcessMemory(handle, (LPVOID)(ref.x), &x, sizeof(float), 0);
    WriteProcessMemory(handle, (LPVOID)(ref.x2), &x, sizeof(float), 0);

}
void GDMem::setY(float y){
    WriteProcessMemory(handle, (LPVOID)(ref.y), &y, sizeof(float), 0);
    WriteProcessMemory(handle, (LPVOID)(ref.y2), &y, sizeof(float), 0);
}



void GDMem::setDeath(bool isDead) {
    WriteProcessMemory(handle, (LPVOID)(ref.death), &isDead, sizeof(bool), 0);
}