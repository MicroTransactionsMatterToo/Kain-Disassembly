#ifndef BASELINE_INC
#include <windef.h>
#include <winnt.h>
#include <basetsd.h>
#include <windows.h>
#include <vcruntime.h>
#include "globals.h"
// IDA qmemcpy
void __fastcall qmemcpy (void* dst, const void* src, UINT count) {};
#define BASELINE_INC
#endif