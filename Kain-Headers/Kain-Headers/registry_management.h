#ifndef REG_MANAGEMENT
struct AppData {
	HINSTANCE instanceHandle;
	int value3;
	void *empty1;
	BYTE screenWidth;
	BYTE screenHeight;
	BYTE colourDepth;
	BYTE screenGamma;
	BYTE isWindowed;
	BYTE renderDevice;
	BYTE tripleBufferFlag;
	BYTE vsyncEnabled;
	BYTE filteringFlag;
	BYTE soundDevice;

	AppData(HINSTANCE handle, 
		int value3, 
		void *empty,
		BYTE screenWidth,
		BYTE screenHeight, 
		BYTE colourDepth,
		BYTE screenGamma,
		BYTE isWindowed,
		BYTE renderDevice,
		BYTE tripleBufferFlag,
		BYTE vsyncEnabled,
		BYTE filteringFlag,
		BYTE soundDevice) :
		instanceHandle(handle), 
		value3(value3), 
		empty1(empty),
		screenWidth(screenWidth),
		screenHeight(screenHeight),
		colourDepth(colourDepth),
		screenGamma(screenGamma),
		isWindowed(isWindowed),
		renderDevice(renderDevice),
		tripleBufferFlag(tripleBufferFlag),
		vsyncEnabled(vsyncEnabled),
		filteringFlag(filteringFlag),
		soundDevice(soundDevice)
	{}
};

#define REG_MANAGEMENT
#endif
