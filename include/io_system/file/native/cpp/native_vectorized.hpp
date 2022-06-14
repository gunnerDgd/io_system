#pragma once
extern "C"
{
#include <io_system/file/native/native.h>
}

#include <io_system/file/native/cpp/native_declare.hpp>
#include <io_system/file/native/cpp/native_openmode.hpp>
#include <io_system/file/native/cpp/native_io_vector.hpp>

#include <string>
#include <cassert>

namespace io_system::file {
	class native_vectorized
	{
	public:
		using native_handle_type
			= synapse_io_system_file_vectorized*;
		using value_type
			= vectorized::io_vector;
		using pointer   = value_type*;
		using reference = value_type&;

		using size_type		  = std::size_t;
		using difference_type = std::ptrdiff_t;

	public:
		native_vectorized (std::wstring, __create_new)   ;
		native_vectorized (std::wstring, __open_existing);
		~native_vectorized();
	
	public:
		size_type
			read_from(reference);
		size_type
			read_from(reference, difference_type);

		size_type
			write_to (reference);
		size_type
			write_to (reference, difference_type);

	private:
		native_handle_type
			__M_iosys_file_vectorized;
		size_type
			__M_iosys_file_vectorized_offset;
	};
}