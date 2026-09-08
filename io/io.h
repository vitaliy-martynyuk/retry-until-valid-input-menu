#ifndef IO_H
#define IO_H

namespace io
{
	namespace menu
	{
		void printMenuOptions();
		int getMenuOption();
	}

	namespace item
	{
		int getItemCode();
		void printItemCodeError();
		void printItemCodeSuccess(int id);
	}

	namespace sessionStats
	{
		void printSessionStats(int itemsSuccess, int itemsError);
	}

	namespace quit
	{
		void printQuitMessage(int totalItems);
	}
}

#endif
