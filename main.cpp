#include "io/io.h"
#include "validation/validation.h"
#include "globals/globals.h"
#include <iostream>
#include <cstdint>

int main()
{
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
					globals::incrementItemsSuccess();
					io::item::printItemCodeSuccess(itemCode);
					break;
				}

				globals::incrementItemsError();
				io::item::printItemCodeError();
			}

			break;
		}
		case 2: {
			io::sessionStats::printSessionStats(globals::getItemsSuccess(), globals::getItemsError());
			break;
		}
		case 3: {
			io::quit::printQuitMessage(globals::getItemsSuccess(), globals::getItemsError());
			break;
		}
		default:
			continue;
		}
	} while (option != 3 && globals::getItemsSuccess() < globals::maxSessionItems);

	if (globals::getItemsSuccess() > globals::maxSessionItems) {
		io::quit::printSessionLimitReachedMessage(globals::getItemsSuccess(), globals::getItemsError());
	}

	return 0;
}