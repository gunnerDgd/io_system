#include <io_system/file/native/vectorized_io/native_vectorized_init.h>
#include <io_system/file/details/native/vectorized_io/iosys_file_native_vectorized_init.h>

#include <stdint.h>

synapse_io_system_file_vectorized_handle
synapse_io_system_file_vectorized_open_existing
	(const wchar_t* pName)
{
	synapse_io_system_opaque_init
		(synapse_io_system_file_vectorized_handle,
		 ptr_vechnd,
		 __synapse_iosys_file_native_vectorized_open_existing(pName)
		);

	return ptr_vechnd;
}

synapse_io_system_file_vectorized_handle
synapse_io_system_file_vectorized_create_new
	(const wchar_t* pName)
{
	synapse_io_system_opaque_init
		(synapse_io_system_file_vectorized_handle,
		 ptr_vechnd,
		 __synapse_iosys_file_native_vectorized_create_new(pName)
		);

	return ptr_vechnd;
}

void
synapse_io_system_file_vectorized_cleanup
	(synapse_io_system_file_vectorized_handle pVecHnd)
{
	__synapse_iosys_file_native_vectorized_cleanup
		(synapse_io_system_opaque_reference(pVecHnd));
}