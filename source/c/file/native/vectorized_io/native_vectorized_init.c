#include <io_system/file/native/vectorized_io/native_vectorized_io.h>
#include <io_system/file/details/native/vectorized_io/iosys_file_native_vector_init.h>
#include <stdlib.h>

synapse_io_system_file_vector*
synapse_io_system_file_vector_initialize(size_t pVecCount)
{
	synapse_io_system_file_vector* ptr_vector
		= malloc(sizeof(synapse_io_system_file_vector));

	ptr_vector->handle.opaque   = __synapse_iosys_file_native_vector_initialize(pVecCount);
	
	ptr_vector->vector_push     = &synapse_io_system_file_vector_push	 ;
	ptr_vector->vector_pop      = &synapse_io_system_file_vector_pop	 ;
	
	ptr_vector->vector_retrieve = &synapse_io_system_file_vector_retrieve;
	ptr_vector->vector_count    = &synapse_io_system_file_vector_count   ;

	return ptr_vector;
}

void
synapse_io_system_file_vector_cleanup(synapse_io_system_file_vector* pVector)
{
	__synapse_iosys_file_native_vector_cleanup(pVector->handle.opaque);
	free(pVector);
}