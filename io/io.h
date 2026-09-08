#ifndef IO_H
#define IO_H

#include <cstdint>

namespace io
{
	using std::uint16_t;

	namespace menu
	{
		void printMenuOptions();
		uint16_t getMenuOption();
	}

	namespace item
	{
		uint16_t getItemCode();
		void printItemCodeError();
		void printItemCodeSuccess(uint16_t id);
	}

	namespace sessionStats
	{
		void printSessionStats(uint16_t itemsSuccess, uint16_t itemsError);
	}

	namespace quit
	{
		void printQuitMessage(uint16_t itemsSuccess, uint16_t itemsError);
	}
}

#endif
