#pragma once
#include <type_traits>

namespace io_system::file {
	struct __create_new    {};
	struct __open_existing {};

	static constexpr __create_new	 create_new    {  };
	static constexpr __open_existing open_existing {  };
}