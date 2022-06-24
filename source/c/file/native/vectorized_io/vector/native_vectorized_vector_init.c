#include <io_system/file/details/native/vectorized_io/vector/iosys_file_native_vector_init.h>
#include <io_system/file/native/vectorized_io/vector/native_vectorized_vector_init.h>
#include <stdlib.h>

synapse_io_system_file_vector_handle
synapse_io_system_file_vector_initialize
	(size_t pVecCount)
{
	synapse_io_system_opaque_init
		(synapse_io_system_file_vector_handle,
		 ptr_vector,
		 __synapse_iosys_file_native_vector_initialize(pVecCount)
		);
	
	return ptr_vector;
}

void
synapse_io_system_file_vector_cleanup
	(synapse_io_system_file_vector_handle pVector)
{
	__synapse_iosys_file_native_vector_cleanup
		(synapse_io_system_opaque_reference(pVector));
}