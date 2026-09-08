#include "io.h"
#include <iostream>

namespace io
{
	using std::cout;
	using std::cin;

	namespace menu
	{
		void printMenuOptions()
		{
			cout << "=== Warehouse Kiosk ===\n";
			cout << "1) Log item\n";
			cout << "2) View stats\n";
			cout << "3) Quit\n";
		}

		int getMenuOption()
		{
			cout << "Choose an option: ";
			int input{};
			cin >> input;

			cout << '\n';

			return input;
		}
	}

	namespace item
	{
		int getItemCode()
		{
			cout << "--- Log item ---\n";
			cout << "Enter item code (1000-9999): ";
			int input{};
			cin >> input;

			return input;
		}

		void printItemCodeError()
		{
			cout << "Invalid item code. Try again.\n";
		}

		void printItemCodeSuccess(int id)
		{
			cout << "Item " << id << " logged.\n\n";
		}
	}

	namespace sessionStats
	{
		void printSessionStats(int itemsSuccess, int itemsError)
		{
			cout << "--- View stats ---\n";
			cout << "Items logged: " << itemsSuccess << '\n';
			cout << "Failed attempts to log: " << itemsError << "\n\n";
		}
	}

	namespace quit
	{
		void printQuitMessage(int totalItems)
		{
			cout << "Session ended. " << totalItems << " item(s) logged this session.\n";
		}
	}
}