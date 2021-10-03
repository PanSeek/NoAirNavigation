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

		fill(0x588543, 0x90, 0x2);
		fill(0x588545, 0x90, 0x1);
		fill(0x588546, 0x90, 0x5);
		fill(0x58854B, 0x90, 0x3);
		fill(0x58854E, 0x90, 0x2);
		fill(0x588550, 0x90, 0x2);
		fill(0x588552, 0x90, 0x2);
		fill(0x588554, 0x90, 0x1);
		fill(0x588555, 0x90, 0x5);
		fill(0x58855A, 0x90, 0x6);
		fill(0x588560, 0x90, 0x3);
		fill(0x588563, 0x90, 0x3);
		fill(0x588566, 0x90, 0x2);
		fill(0x588568, 0x90, 0x2);
		fill(0x58856A, 0x90, 0x1);
		fill(0x58856B, 0x90, 0x5);
		fill(0x588570, 0x90, 0x3);
		fill(0x588573, 0x90, 0x4);
		fill(0x588577, 0x90, 0x6);
	};
	~CMain() {
		raw(0x5880B1, "\xE8\x6A\xFC\xFF\xFF", 0x5);
		raw(0x584ABD, "\xD9\x1D\x20\x09\x8D\x00", 0x6);
		raw(0x584AC7, "\xD9\x1D\x28\x09\x8D\x00", 0x6);

		raw(0x588543, "\x6A\x00", 0x2);
		raw(0x588545, "\x56", 0x1);
		raw(0x588546, "\xE8\x85\x5B\xFE\xFF", 0x5);
		raw(0x58854B, "\x83\xC4\x08", 0x3);
		raw(0x58854E, "\x85\xC0", 0x2);
		raw(0x588550, "\x74\x2B", 0x2);
		raw(0x588552, "\x6A\x00", 0x2);
		raw(0x588554, "\x56", 0x1);
		raw(0x588555, "\xE8\x76\x5B\xFE\xFF", 0x5);
		raw(0x58855A, "\x8B\x88\x94\x05\x00\x00", 0x6);
		raw(0x588560, "\x83\xC4\x08", 0x3);
		raw(0x588563, "\x83\xF9\x04", 0x3);
		raw(0x588566, "\x75\x15", 0x2);
		raw(0x588568, "\x6A\x00", 0x2);
		raw(0x58856A, "\x56", 0x1);
		raw(0x58856B, "\xE8\x60\x5B\xFE\xFF", 0x5);
		raw(0x588570, "\x83\xC4\x08", 0x3);
		raw(0x588573, "\x66\x39\x58\x22", 0x4);
		raw(0x588577, "\x0F\x85\xAD\x01\x00\x00", 0x6);
	};
}; CMain plugin;