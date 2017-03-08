#ifndef _KAIN_MONLIB
	#define _KAIN_MONLIB
#include <cstdint>
#endif

/*
Compiler Tricks:
True = 1
False = xor al, al

int8_t = al register
int16+ = eax register


Return Values can be discovered by investigating register written to
*H, *L = 8 bits
*X = 16 bits
*** = 32 bits
char_array      = dword ptr  8
single_char     = byte ptr  0Ch
bool_arg        = byte ptr  10h
i8_arg          = byte ptr  14h
i16_arg         = word ptr  18h
i32_arg         = dword ptr  1Ch
native_int      = dword ptr  20h
short_int       = word ptr  24h
long_ing        = dword ptr  28h
ll_int          = qword ptr  2Ch


Function Returns:
char () = mov al, charCode
...
retn

char (...) = mov al, charCode
...
retn [address of last argument]

void () = 
...
retn

void (...) =
...
retn [address of last argument]

int () = mov eax, int
...
retn

int (...) = mov eax, int
...
return [address of last argument]

bool () = mov al, bool // True return
...
retn

bool (...) = mov al, bool // True Return
...
retn [address of last argument]

bool () = xor al, al // False return
...
retn

bool (...) = xor al, al // False return
...
retn [address of last argument]

*/

class MON
{
public:

	int AnimInit(int monsterID) {
		int idStore = monsterID;
		int zeroValue = 0;
		int32_t pointerToSomething = *(int32_t *)(monsterID + 332);
		int32_t var4 = pointerToSomething;
		int8_t anotherPointer = *(int8_t *)(*(int32_t *)(pointerToSomething + 340) + 42);

		*(int32_t *)(pointerToSomething + 188) = 0;
		int32_t var10 = var4;
		AnimG2.G2EmulationInstanceSetTotalSections(idStore, var4);
		char var5 = 0;
		char var9 = 0;

		if (var4 > 0) {
			int var6 = pointerToSomething + 148;
			int var7 = idStore + 440;
			while (true) {
				if (*(bool *)(anotherPointer + 340) + 43) {
				AnimG2.G2EmulationInstanceSetStartAndEndSegment(idStore, zeroValue, var5, *(bool *)(zeroValue + *(int32_t *)(anotherPointer + 340)));
				}
			}
		}
	}
	// Returns EAX
	int32_t TurnOffWeaponSpheres(int32_t arg0) {};

	// Returns EAX
	int32_t TurnOnWeaponSpheres(int32_t arg0) {};
	int32_t TurnOnWeaponSphere(int32_t arg0, int32_t sphereID) {};

	void TurnOffBodySpheres(int32_t arg0) {};
	void TurnOnBodySpheres(int32_t arg0) {};

	void TurnOffAllSpheres(int32_t arg0) {};
	void TurnOnAllSpheres(int32_t arg0) {};

	int16_t SwitchState(int32_t arg0, int32_t arg1) {};
	int16_t SwitchStateDoEntry(int32_t arg0, int32_t arg1) {};

	int16_t TransNodeAnimation(int32_t arg0) {
		return arg0 + 0x194; 
		// I think this might be right. I'll look into it more
	}

	void GetAnim(int32_t arg0, int32_t arg1, int32_t arg2) {};
	
	int32_t PlayAnimID(int32_t arg0, int32_t arg1, int32_t arg2) {};
	void PlayAnimFromList(int32_t )
};