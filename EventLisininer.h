
#include <windows.h> // for GetAsyncKeyState() and VK_ESCAPE


//#include <winable.h> // For INPUT
//#include <Winuser.h>
//#include <string>
//#include <stdio.h> // sprintf, _sprintf_l
//#include <iostream> //
//#include <sstream>


#define WM_KEYDOWN   0x0100   // Key pressing
#define WM_KEYUP     0x0101  // Key pressed
using std::string;
using namespace std;

// Capture global keys appear in main window/dekstop
class EventLisinner {
private:
public:

	//Contructor
  	EventLisinner() {};


	

	// Lissen virtual key  was represented
	bool KeyLissinerVK(byte VK_input) {
		return GetAsyncKeyState(VK_input);
	};

	

	bool KeyLissinerF1() { return GetAsyncKeyState(VK_F1); }
	bool KeyLissinerF2() { return GetAsyncKeyState(VK_F2); }
	bool KeyLissinerF3() { return GetAsyncKeyState(VK_F3); }
	bool KeyLissinerF4() { return GetAsyncKeyState(VK_F4); }
	bool KeyLissinerF5() { return GetAsyncKeyState(VK_F5); }
	bool KeyLissinerF6() { return GetAsyncKeyState(VK_F6); }
	bool KeyLissinerF7() { return GetAsyncKeyState(VK_F7); }
	bool KeyLissinerF8() { return GetAsyncKeyState(VK_F8); }
	bool KeyLissinerF9() { return GetAsyncKeyState(VK_F9); }
	bool KeyLissinerF10() { return GetAsyncKeyState(VK_F10); }
	bool KeyLissinerF111() { return GetAsyncKeyState(VK_F11); }
	bool KeyLissinerF12() { return GetAsyncKeyState(VK_F12); }
	bool KeyLissinerF13() { return GetAsyncKeyState(VK_F13); }
	bool KeyLissinerF14() { return GetAsyncKeyState(VK_F14); }
	bool KeyLissinerF15() { return GetAsyncKeyState(VK_F15); }
	bool KeyLissinerF16() { return GetAsyncKeyState(VK_F16); }
	bool KeyLissinerF17() { return GetAsyncKeyState(VK_F17); }
	bool KeyLissinerF18() { return GetAsyncKeyState(VK_F18); }
	bool KeyLissinerF19() { return GetAsyncKeyState(VK_F19); }
	
	bool KeyLissinerSHIFT() { return GetAsyncKeyState(VK_SHIFT); }
	bool KeyLissinerALT() { return GetAsyncKeyState(VK_MENU); }
	bool KeyLissinerCTRL() { return GetAsyncKeyState(VK_CONTROL); }
	bool KeyLissinerESCAPE() { return GetAsyncKeyState(VK_ESCAPE); }
	bool KeyLissinerENTER() { return GetAsyncKeyState(VK_RETURN); }


		
	

	
};


// Class that takes key event  input or  output

