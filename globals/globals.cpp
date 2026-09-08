#include "globals.h"
#include <cstdint>

namespace globals
{
	using std::uint16_t;

	static uint16_t itemsSuccess{ 0 };
	static uint16_t itemsError{ 0 };

	void incrementItemsSuccess()
	{
		++itemsSuccess;
	}

	void incrementItemsError()
	{
		++itemsError;
	}

	uint16_t getItemsSuccess()
	{
		return itemsSuccess;
	}

	uint16_t getItemsError()
	{
		return itemsError;
	}
}
