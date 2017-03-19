#if !defined(_WIN32_WINNT) && !defined(_CHICAGO_)
#define  _WIN32_WINNT   0x0603
#endif
#ifndef WINVER
#define WINVER _WIN32_WINNT
#endif

#ifdef STRICT
typedef void *HANDLE;
#if 0 && (_MSC_VER > 1000)
#define DECLARE_HANDLE(name) struct name##__; typedef struct name##__ *name
#else
#define DECLARE_HANDLE(name) struct name##__{int unused;}; typedef struct name##__ *name
#endif
#else
typedef PVOID HANDLE;
#define DECLARE_HANDLE(name) typedef HANDLE name;
#endif
typedef HANDLE *PHANDLE;


#if __MACH__ && __APPLE__ || __gnu_linux__
#define POSIXCOMPLIANT 1
#define WINDOWS 0
#include <stdint.h>
#define FAR
typedef uint64_t __uint64;
typedef int64_t  __int64;
#elif _WIN32
#define WINDOWS 1
#define POSIXCOMPLIANT 0
#define UNK 0
#define FAR far
typedef unsigned __int64 __uint64;
#else //! _WIN32
#define UNK 1
#define WINDOWS 0
#define POSIXCOMPLIANT 0
#define FAR
#endif //! __MACH__ && __APPLE__ || __gnu_linux__


#ifndef _M_IX86
typedef __int64 _ix64;
typedef __uint64 _uix64;
#else
typedef double _ix64;
typedef double _uix64;
#endif

#ifndef WINDOWS_BASE_TYPES
#define WINDOWS_BASE_TYPES

// Others
typedef unsigned char BYTE;
typedef int BOOL;
typedef BYTE BOOLEAN;

// Character types
typedef char CHAR;
typedef unsigned char UCHAR;
typedef wchar_t WCHAR;
typedef char CCHAR;

// Strict bit width types
typedef unsigned short WORD;
typedef unsigned long DWORD;
typedef __uint64 QWORD;

// Generic data types
typedef float FLOAT;
typedef int INT;
typedef long LONG;
typedef short SHORT;

// Unsigned variations
typedef unsigned int UINT;
typedef unsigned long ULONG;
typedef unsigned short USHORT;

// #defines
#define CONST const

#define CALLBACK __stdcall
#define WINAPI __stdcall
#define APIENTRY WINAPI

#define POINTER_SIGNED __sptr
#define POINTER_UNSIGNED __uptr

#define VOID void
#endif /* WINDOWS_BASE_TYPES */

#ifndef INT_VARIATIONS
#define INT_VARIATIONS
typedef signed char INT8;
typedef signed short INT16;
typedef signed int INT32;
typedef __int64 INT64;
#endif /* INT_VARIATIONS */

#ifndef UINT_VARIATIONS
#define UINT_VARIATIONS
typedef unsigned char UINT8;
typedef unsigned short UINT16;
typedef unsigned int UINT32;
typedef __uint64 UINT64;
#endif /* UINT_VARIATIONS */

#ifndef LONG_VARIATIONS
#define LONG_VARIATIONS
typedef _ix64 LONGLONG;
typedef signed int LONG32;
typedef __int64 LONG64;
#endif /* LONG_VARIATIONS */

#ifndef ULONG_VARIATIONS
#define ULONG_VARIATIONS
typedef _uix64 ULONGLONG;
typedef unsigned int ULONG32;
typedef __uint64 ULONG64;
#endif /* ULONG_VARIATIONS */

#ifndef DWORD_VARIATIONS
#define DWORD_VARIATIONS
typedef __uint64 DWORDLONG;
typedef unsigned int DWORD32;
typedef __uint64 DWORD64;
#endif /* DWORD_VARIATIONS */

#ifndef X_BASIC_PTR_POINTERS
#define X_BASIC_PTR_POINTERS
#if defined(_WIN64)
typedef __int64 INT_PTR;
typedef __uint64 UINT_PTR
typedef __int64 LONG_PTR;
typedef __uint64 ULONG_PTR;
typedef int HALF_PTR;
typedef unsigned int HALF_PTR;
#else /* _WIN64 */
typedef int INT_PTR;
typedef unsigned int UINT_PTR;
typedef long LONG_PTR;
typedef unsigned long ULONG_PTR;
typedef short HALF_PTR;
typedef unsigned short UHALF_PTR;
#endif /* _WIN64 */

typedef ULONG_PTR DWORD_PTR;
#endif /* X_BASIC_PTR_POINTERS */

#ifndef LP_BASIC_TYPE_POINTERS
#define LP_BASIC_TYPE_POINTERS
typedef BOOL FAR *LPBOOL;
typedef BYTE FAR *LPBYTE;
typedef DWORD *LPCOLORREF;

typedef DWORD *LPDWORD;
typedef int *LPINT;
typedef long *LPLONG;

typedef void *LPVOID;
typedef CONST void *LPCVOID;

typedef CONST CHAR *LPCSTR;
typedef CONST WCHAR *LPCWSTR;
typedef CHAR *LPSTR;
typedef WCHAR *LPWSTR;
#ifdef UNICODE
typedef LPCWSTR LPCTSTR;
typedef LPWSTR LPTSTR;
#else /* UNICODE */
typedef LPCSTR LPCTSTR;
typedef LPSTR LPTSTR;
#endif /* UNICODE */


#endif /* LP_BASIC_TYPE_POINTERS */

#ifndef P_BASIC_TYPE_POINTERS
#define P_BASIC_TYPE_POINTERS
typedef BOOL *PBOOL;
typedef BOOLEAN *PBOOLEAN;

typedef BYTE *PBYTE;

typedef int *PINT;
typedef INT8 *PINT8;
typedef INT16 *PINT16;
typedef INT32 *PINT32;
typedef INT64 *PINT64;
typedef INT_PTR *PINT_PTR;

typedef UINT *PUINT;
typedef UINT8 *PUINT8;
typedef UINT16 *PUINT16;
typedef UINT32 *PUINT32;
typedef UINT64 *PUINT64;
typedef UINT_PTR *PUINT_PTR;

typedef LONG *PLONG;
typedef LONGLONG *PLONGLONG;
typedef LONG32 *PLONG32;
typedef LONG64 *PLONG64;
typedef LONG_PTR *PLONG_PTR;

typedef ULONG *PULONG;
typedef ULONGLONG *PULONGLONG;
typedef ULONG32 *PULONG32;
typedef ULONG64 *PULONG64;
typedef ULONG_PTR *PULONG_PTR;

typedef DWORD *PDWORD;
typedef DWORD32 *PDWORD32;
typedef DWORD64 *PDWORD64;
typedef DWORDLONG *PDWORDLONG;
typedef DWORD_PTR *PDWORD_PTR;

typedef FLOAT *PFLOAT;

typedef SHORT *PSHORT;

typedef HALF_PTR *PHALF_PTR;

typedef void *PVOID;

typedef CHAR *PCHAR;
typedef UCHAR *PUCHAR;
typedef WCHAR *PWCHAR;
typedef WCHAR *PWSTR;
typedef CONST CHAR *PCSTR;
typedef CONST WCHAR *PCWSTR;

#ifdef UNICODE
typedef LPCWSTR PCTSTR;
#else /* UNICODE */
typedef LPCSTR PCTSTR;
#endif /* UNICODE */
#endif /* P_BASIC_TYPE_POINTERS */

#ifndef WINDOWS_ADV_TYPES
typedef PVOID HANDLE;
DECLARE_HANDLE(HBITMAP)
DECLARE_HANDLE(HBRUSH)
DECLARE_HANDLE(HCOLORSPACE)
DECLARE_HANDLE(HCONV)
DECLARE_HANDLE(HCONVLIST)
DECLARE_HANDLE(HCURSOR)
DECLARE_HANDLE(HDC)
DECLARE_HANDLE(HDDEDATA)
DECLARE_HANDLE(HDESK)
DECLARE_HANDLE(HDROP)
DECLARE_HANDLE(HDWP)
DECLARE_HANDLE(HENHMETAFILE)
DECLARE_HANDLE(HFONT)
DECLARE_HANDLE(HGDIOBJ)
DECLARE_HANDLE(HGLOBAL)
DECLARE_HANDLE(HHOOK)
DECLARE_HANDLE(HICON)
DECLARE_HANDLE(HINSTANCE)
DECLARE_HANDLE(HKEY)
DECLARE_HANDLE(HKL)
DECLARE_HANDLE(HLOCAL)
DECLARE_HANDLE(HMENU)
DECLARE_HANDLE(HMETAFILE)
DECLARE_HANDLE(HPALLETE)
DECLARE_HANDLE(HPEN)
DECLARE_HANDLE(HRGN)
DECLARE_HANDLE(HRSRC)
DECLARE_HANDLE(HSZ)
DECLARE_HANDLE(HWINSTA)
DECLARE_HANDLE(HWND)
DECLARE_HANDLE(SC_HANDLE)
DECLARE_HANDLE(SERVICE_STATUS_HANDLE)

#if (WINVER >= 0x0500) 
typedef HANDLE HMONITOR;
#endif
typedef int HFILE;
typedef HINSTANCE HMODULE;

typedef WORD LANGID;
typedef DWORD LCID;
typedef DWORD LCTYPE;
typedef DWORD LGRPID;

typedef LPVOID SC_LOCK;

typedef ULONG_PTR SIZE_T;
typedef LONG_PTR SSIZE_T;

typedef struct _UNICODE_STRING {
	USHORT Length;
	USHORT MaximumLength;
	PWSTR Buffer;
} UNICODE_STRING;
typedef UNICODE_STRING *PUNICODE_STRING;
typedef const UNICODE_STRING *PCUNICODE_STRING;

typedef UINT_PTR WPARAM;

#endif /* WINDOWS_ADV_TYPES */


