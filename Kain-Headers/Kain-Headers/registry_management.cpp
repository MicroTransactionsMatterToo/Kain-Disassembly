#include <winnt.h>
#include <windef.h>
#include <basetsd.h>

struct AppData {
	HINSTANCE instanceHandle;
	int value3;
	void *empty1;
	LPBYTE screenWidth;
	LPBYTE screenHeight;
	LPBYTE colourDepth;
	LPBYTE screenGamma;
	LPBYTE isWindowed;
	LPBYTE renderDevice;
	LPBYTE tripleBufferFlag;
	LPBYTE vsyncEnabled;
	LPBYTE filteringFlag;
	LPBYTE soundDevice;
};