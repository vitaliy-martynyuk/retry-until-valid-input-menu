#ifndef GLOBALS_H
#define GLOBALS_H

#include <cstdint>

namespace globals
{
	using std::uint16_t;

	inline constexpr uint16_t maxSessionItems{ 999 };

	void incrementItemsSuccess();
	void incrementItemsError();
	uint16_t getItemsSuccess();
	uint16_t getItemsError();
}

#endif
