#include <Windows.h>

auto __cdecl fill(unsigned __int32 address, unsigned __int8 value, unsigned __int32 size) -> void {
	DWORD oldProt{ 0 };
	VirtualProtect(reinterpret_cast<LPVOID>(address), size, PAGE_READWRITE, &oldProt);
	memset(reinterpret_cast<void*>(address), value, size);
	VirtualProtect(reinterpret_cast<LPVOID>(address), size, oldProt, &oldProt);
	return;
}

auto __cdecl raw(unsigned __int32 address, const char* RawData, unsigned __int16 size) -> void {
	DWORD oldProt{ 0 };
	VirtualProtect(reinterpret_cast<LPVOID>(address), size, PAGE_READWRITE, &oldProt);
	memcpy(reinterpret_cast<void*>(address), RawData, size);
	VirtualProtect(reinterpret_cast<LPVOID>(address), size, oldProt, &oldProt);
	return;
}

class CMain {
public:
	CMain() {
		fill(0x5880B1, 0x90, 0x5);
		fill(0x584ABD, 0x90, 0x6);
		fill(0x584AC7, 0x90, 0x6);
	};
	~CMain() {
		raw(0x5880B1, "\xE8\x6A\xFC\xFF\xFF", 0x5);
		raw(0x584ABD, "\xD9\x1D\x20\x09\x8D\x00", 0x6);
		raw(0x584AC7, "\xD9\x1D\x28\x09\x8D\x00", 0x6);
	};
}; CMain plugin;

//mem.fill(0x5880B1, 0x90, 5, true) \xE8\x6A\xFC\xFF\xFF
//mem.fill(0x584ABD, 0x90, 6, true) \xD9\x1D\x20\x09\x8D\x00
//mem.fill(0x584AC7, 0x90, 6, true) \xD9\x1D\x28\x09\x8D\x00