#pragma once
extern "C"
{
#include <io_system/file/native/vectorized_io/native_vectorized_io.h>
}

#include <cstdint>
#include <type_traits>

#include <io_system/file/native/cpp/native_declare.hpp>

namespace io_system::file::vectorized {
	class io_vector
	{
		friend class io_system::file::native_vectorized;
	public:
		using native_handle_type
			= synapse_io_system_file_vector*;
		using size_type		  = std::size_t;
		using difference_type = std::ptrdiff_t;
		using pointer		  = void*;

	public:
		class vector
		{
			friend class io_vector;

			pointer   __M_iovec_ptr ;
			size_type __M_iovec_size;

			vector(pointer, size_type);
		public:
			pointer   get_pointer();
			size_type size	     ();
		};

	public:
		io_vector (size_type);
		~io_vector();

	public:
		size_type push		 (size_t);
		size_type pop		 ();
		size_type count	     ();
		vector    operator[] (size_type);

	private:
		native_handle_type
			__M_iovec_handle;
	};
}