#include <io_system/file/native/native_io.h>
#include <io_system/file/details/native/iosys_file_native_io.h>

size_t
synapse_iosys_file_native_read_from
	(synapse_io_system_file_handle pEntity, void* pReadBuffer, size_t pReadSize)
{
	return 
		__synapse_iosys_file_native_read_from
			(synapse_io_system_opaque_reference(pEntity), pReadBuffer, pReadSize);
}

size_t
synapse_iosys_file_native_write_to
	(synapse_io_system_file_handle pEntity, void* pWriteBuffer, size_t pWriteSize)
{
	return 
		__synapse_iosys_file_native_write_to
			(synapse_io_system_opaque_reference(pEntity), pWriteBuffer, pWriteSize);
}