#include "io/io.h"
#include "validation/validation.h"
#include <iostream>
#include <cstdint>

static void cleanup()
{
	io::quit::printQuitMessage(1);
}

int main()
{
	std::atexit(cleanup);

	std::uint16_t option{};
	do {
		io::menu::printMenuOptions();
		option = io::menu::getMenuOption();

		if (!validation::menu::isMenuOptionValid(option)) {
			continue;
		}

		switch (option) {
		case 1: {
			std::uint16_t itemCode{};
			while (true) {
				itemCode = io::item::getItemCode();
				if (validation::item::isItemCodeValid(itemCode)) {
					io::item::printItemCodeSuccess(itemCode);
					break;
				}

				io::item::printItemCodeError();
			}

			break;
		}
		case 2: {
			io::sessionStats::printSessionStats(1, 1);
			break;
		}
		case 3:
			break;
		default:
			continue;
		}
	} while (option != 3);

	return 0;
}