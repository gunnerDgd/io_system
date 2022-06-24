#include <io_system/file/native/native_init.h>
#include <io_system/file/details/native/iosys_file_native.h>

#include <stdlib.h>

synapse_io_system_file_handle
synapse_iosys_file_native_initialize_open_existing
	(const wchar_t* pName)
{
	synapse_io_system_opaque_init
		(synapse_io_system_file_handle,
		 ptr_fhnd,
		 __synapse_iosys_file_native_initialize_open_existing(pName));

	return ptr_fhnd;
}

synapse_io_system_file_handle
synapse_iosys_file_native_initialize_create_new
	(const wchar_t* pName)
{
	synapse_io_system_opaque_init
		(synapse_io_system_file_handle,
		 ptr_fhnd,
		 __synapse_iosys_file_native_initialize_create_new(pName));

	return ptr_fhnd;
}

void
synapse_iosys_file_native_cleanup
	(synapse_io_system_file_handle pFileHandle)
{
	__synapse_iosys_file_native_cleanup
		(synapse_io_system_opaque_reference(pFileHandle));
}
