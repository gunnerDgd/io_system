#include <io_system/file/native/cpp/native_nonvec_raw.hpp>

io_system::file::native<>::native(std::wstring pName, __open_existing)
	: __M_iosys_file_native
		(synapse_iosys_file_native_initialize_open_existing(pName.c_str())),
	  __M_iosys_file_native_offset
		(0) {}

io_system::file::native<>::native(std::wstring pName, __create_new)
	: __M_iosys_file_native
		(synapse_iosys_file_native_initialize_create_new(pName.c_str())),
	  __M_iosys_file_native_offset
		(0) {}

typename io_system::file::native<>::native_handle_type
		 io_system::file::native<>::native_handle() { return __M_iosys_file_native; }

typename io_system::file::native<>::size_type
		 io_system::file::native<>::read_from(pointer pRead, size_type pReadSize)
{
	size_t sz_read
		= synapse_io_system_file_read_from(__M_iosys_file_native, pRead, pReadSize, __M_iosys_file_native_offset);

	__M_iosys_file_native_offset += sz_read;
	return							sz_read;
}

typename io_system::file::native<>::size_type
		 io_system::file::native<>::read_from(pointer pRead, size_type pReadSize, difference_type pReadOffset)
{
	return
		synapse_io_system_file_read_from(__M_iosys_file_native, pRead, pReadSize, pReadOffset);
}

typename io_system::file::native<>::size_type
		 io_system::file::native<>::write_to(pointer pWrite, size_type pWriteSize)
{
	size_type sz_write
		= synapse_io_system_file_write_to(__M_iosys_file_native, pWrite, pWriteSize, __M_iosys_file_native_offset);
	
	__M_iosys_file_native_offset += sz_write;
	return							sz_write;
}

typename io_system::file::native<>::size_type
		 io_system::file::native<>::write_to(pointer pWrite, size_type pWriteSize, difference_type pWriteOffset)
{
	return
		synapse_io_system_file_write_to(__M_iosys_file_native, pWrite, pWriteSize, pWriteOffset);
}