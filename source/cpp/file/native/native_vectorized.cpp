#include <io_system/file/native/cpp/native_vectorized.hpp>

io_system::file::native_vectorized::native_vectorized(std::wstring pName, __create_new)
	: __M_iosys_file_vectorized
		(synapse_iosys_file_vectorized_initialize_create_new(pName.c_str())),
	  __M_iosys_file_vectorized_offset
		(0)	{  }

io_system::file::native_vectorized::native_vectorized(std::wstring pName, __open_existing)
	: __M_iosys_file_vectorized
		(synapse_iosys_file_vectorized_initialize_open_existing(pName.c_str())),
	  __M_iosys_file_vectorized_offset
		(0) {  }

io_system::file::native_vectorized::~native_vectorized()
{
	synapse_iosys_file_vectorized_cleanup(__M_iosys_file_vectorized);
}

typename io_system::file::native_vectorized::size_type
		 io_system::file::native_vectorized::read_from(reference pVector)
{
	size_t sz_read
		= synapse_io_system_file_vectorized_read_from(
				__M_iosys_file_vectorized,
				pVector.__M_iovec_handle,
				__M_iosys_file_vectorized_offset
		);

	__M_iosys_file_vectorized_offset += sz_read;
	return								sz_read;
}

typename io_system::file::native_vectorized::size_type
		 io_system::file::native_vectorized::read_from(reference pReadVector, difference_type pReadOffset)
{
	return
		synapse_io_system_file_vectorized_read_from(
			__M_iosys_file_vectorized,
			pReadVector.__M_iovec_handle,
			pReadOffset
		);
}

typename io_system::file::native_vectorized::size_type
		 io_system::file::native_vectorized::write_to(reference pWriteVector)
{
	size_t sz_write
		= synapse_io_system_file_vectorized_write_to(
			__M_iosys_file_vectorized,
			pWriteVector.__M_iovec_handle,
			__M_iosys_file_vectorized_offset
		);

	__M_iosys_file_vectorized_offset += sz_write;
	return								sz_write;
}

typename io_system::file::native_vectorized::size_type
		 io_system::file::native_vectorized::write_to(reference pWriteVector, difference_type pWriteOffset)
{
	return synapse_io_system_file_vectorized_write_to(
		__M_iosys_file_vectorized,
		pWriteVector.__M_iovec_handle,
		pWriteOffset
	);
}
