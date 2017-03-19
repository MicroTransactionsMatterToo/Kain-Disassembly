#include "baseline_includes.h"
#include "registry_management.h"

int __stdcall WinMain(HINSTANCE windowInstance, HINSTANCE previousInstance, LPSTR commandLine, int nShowCmd) {
	// Internal representation of Registry Data
	AppData appDataVM(
		windowInstance,
		0,
		(void *) NULL,
		1,
		640,
		480,
		16,
		5,
		0,
		0,
		0,
		1,
		0
	);
	// Write data to registry
	HKEY registryHandle;
	DWORD registrySucceeded;
	DWORD registryBufferSize = 4;
	// Create new key if possible
	RegCreateKeyExA(HKEY_LOCAL_MACHINE, "SOFTWARE", 0, NULL, 0, KEY_EXECUTE, 0, &registryHandle, &registrySucceeded);

	// Write values
	RegQueryValueExA(registryHandle, "Windowed", 0, NULL, &appDataVM.isWindowed, &registryBufferSize);
	RegQueryValueExA(registryHandle, "RenderDeviceID", 0, NULL, &appDataVM.renderDevice, &registryBufferSize);
	RegQueryValueExA(registryHandle, "SoundDeviceID", 0, NULL, &appDataVM.soundDevice, &registryBufferSize);
	RegQueryValueExA(registryHandle, "ScreenWidth", 0, NULL, &appDataVM.screenWidth, &registryBufferSize);
	RegQueryValueExA(registryHandle, "ScreenHeight", 0, NULL, &appDataVM.screenHeight, &registryBufferSize);
	RegQueryValueExA(registryHandle, "ScreenDepth", 0, NULL, &appDataVM.colourDepth, &registryBufferSize);
	RegQueryValueExA(registryHandle, "GammaLevel", 0, NULL, &appDataVM.screenGamma, &registryBufferSize);
	RegQueryValueExA(registryHandle, "TripleBuffer", 0, NULL, &appDataVM.tripleBufferFlag, &registryBufferSize);
	RegQueryValueExA(registryHandle, "Filter", 0, NULL, &appDataVM.filteringFlag, &registryBufferSize);
	RegQueryValueExA(registryHandle, "VSync", 0, NULL, &appDataVM.filteringFlag, &registryBufferSize);
	RegCloseKey(registryHandle);

	// Copies predefined command line args to command line argument variable
	qmemcpy(&commandLineArguments, "under 1 -mainmenu -voice -inspectral", 0x25u);

	// Get name of module
	char instanceModuleName;
	GetModuleFileName(windowInstance, &instanceModuleName, 0x100u);
	strcpy(moduleFilenameContents, &instanceModuleName);

	// Loop through name
	int startOfFilename = 0;
	char currentLetter = moduleFilenameContents[0];
	int index;
	for (index = 0; currentLetter; currentLetter = moduleFilenameContents[startOfFilename]) {
		if (currentLetter == '\\') {
			i = startOfFilename;
		}
		++startOfFilename;
	}
	moduleFilenameContents[index] = 0;
	int processID = lcGetCurrentProcessId();
	
	const char kernelModule

}


int lcGetCurrentProcessId(void) { return GetCurrentProcessId(); }