#include <stdio.h>
#include <Windows.h>
#include <tlhelp32.h>
#include <processthreadsapi.h>
#pragma comment( lib, "Kernel32.lib" )


void DetectSuspiciousFunction(DWORD processId) {
	HANDLE hpOpenProcess = OpenProcess(0x0010 | 0x0020, FALSE, processId);


}


//1. Loop Through all processes via snapshot

void LoopThroughAllMemoryProcesses() {
	HANDLE allprocess = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, NULL);
	PROCESSENTRY32 pe;
	pe.dwSize = sizeof(PROCESSENTRY32);
	
	BOOL p = Process32First(allprocess, &pe);

	while (p) {
		
		printf("the process Name %d\n", pe.th32ProcessID);
		DetectSuspiciousFunction(pe.th32ProcessID);
		p = Process32Next(allprocess, &pe);
	}
		
	CloseHandle(allprocess);
	
}



int main() {
	LoopThroughAllMemoryProcesses();




	return 0;
}