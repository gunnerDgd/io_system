#pragma once
extern "C"
{
#include <io_system/file/native/native.h>
}

#include <io_system/file/native/cpp/native_declare.hpp>
#include <io_system/file/native/cpp/native_openmode.hpp>

#include <string>
#include <cassert>

namespace io_system::file {
	template <>
	class native<void>
	{
	public:
		using native_handle_type = synapse_io_system_file*;
		using size_type			 = std::size_t	 ;
		using difference_type    = std::ptrdiff_t;

		using value_type		 = void;
		using reference			 = void;
		using pointer			 = void*;

	public:
		template <typename AnyOption>
		native(std::wstring, AnyOption&&) {
			fprintf(stderr, "[io_system::file::native][Critical] Invalid Creation Parameter\n");
			assert (false);
		}
		
		native (std::wstring, __open_existing);
		native (std::wstring, __create_new)   ;

	public:
		size_type
			read_from(pointer, size_type);
		size_type
			read_from(pointer, size_type, difference_type);

		size_type
			write_to (pointer, size_type);
		size_type
			write_to (pointer, size_type, difference_type);

		native_handle_type
			native_handle();

	private:
		native_handle_type
			__M_iosys_file_native;
		difference_type
			__M_iosys_file_native_offset;
	};
}