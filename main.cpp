#include "io/io.h"
#include <iostream>

int main()
{
	io::menu::printMenuOptions();
	io::sessionStats::printSessionStats(0, 0);
	io::quit::printQuitMessage(1);

	return 0;
}