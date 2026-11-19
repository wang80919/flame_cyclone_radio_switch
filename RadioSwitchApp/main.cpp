#include <iostream>
#include "RadioSwitchLib/RadioSwitchLib.h"
#pragma comment(lib, "RadioSwitchLib/RadioSwitchLib.lib")

int main()
{
	RadiosSetBlueToothState(false);
	RadiosSetBlueToothState(true);
	return 0;
}
