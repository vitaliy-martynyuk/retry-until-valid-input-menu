#include "io.h"
#include <iostream>
#include <cstdint>

namespace io
{
	using std::cout;
	using std::cin;
	using std::uint16_t;

	namespace menu
	{
		void printMenuOptions()
		{
			cout << "=== Warehouse Kiosk ===\n";
			cout << "1) Log item\n";
			cout << "2) View stats\n";
			cout << "3) Quit\n";
		}

		uint16_t getMenuOption()
		{
			cout << "Choose an option: ";
			uint16_t input{};
			cin >> input;

			cout << '\n';

			return input;
		}
	}

	namespace item
	{
		uint16_t getItemCode()
		{
			cout << "Enter item code (1000-9999): ";
			uint16_t input{};
			cin >> input;

			return input;
		}

		void printItemCodeError()
		{
			cout << "Invalid item code. Try again.\n";
		}

		void printItemCodeSuccess(uint16_t id)
		{
			cout << "Item " << id << " logged.\n\n";
		}
	}

	namespace sessionStats
	{
		void printSessionStats(uint16_t itemsSuccess, uint16_t itemsError)
		{
			cout << "--- View stats ---\n";
			cout << "Items logged: " << itemsSuccess << '\n';
			cout << "Failed attempts to log: " << itemsError << "\n\n";
		}
	}

	namespace quit
	{
		void printQuitMessage(uint16_t itemsSuccess, uint16_t itemsError)
		{
			cout << "Session ended. " << itemsSuccess << " item(s) logged this session (" << itemsError << " failed attempts).\n";
		}

		void printSessionLimitReachedMessage(uint16_t itemsSuccess, uint16_t itemsError)
		{
			cout << "Session limit reached. " << itemsSuccess << " item(s) logged this session (" << itemsError << " failed attempts).\n";
		}
	}
}