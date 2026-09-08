#ifndef VALIDATION_H
#define VALIDATION_H

#include <cstdint>

namespace validation
{
	using std::uint16_t;

	namespace menu
	{
		inline bool isMenuOptionValid(uint16_t option)
		{
			return (option >= 1) && (option <= 3);
		}
	}

	namespace item
	{
		inline bool isItemCodeValid(uint16_t id)
		{
			return (id >= 1000) && (id <= 9999);
		}
	}
}

#endif
