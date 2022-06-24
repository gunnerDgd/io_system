#include <io_system/file/native/vectorized_io/vector/native_vectorized_vector_manip.h>
#include <io_system/file/details/native/vectorized_io/vector/iosys_file_native_vector_manip.h>

void*
synapse_io_system_file_vector_push
	(synapse_io_system_file_vector_handle pVector, size_t pVectorSize)
{
	return 
		__synapse_iosys_file_native_vector_push
			(synapse_io_system_opaque_reference(pVector), pVectorSize);
}

void
synapse_io_system_file_vector_pop
	(synapse_io_system_file_vector_handle pVector)
{
	__synapse_iosys_file_native_vector_pop
		(synapse_io_system_opaque_reference(pVector));
}

void*
synapse_io_system_file_vector_retrieve
	(synapse_io_system_file_vector_handle pVector, size_t pVectorIndex)
{
	return 
		__synapse_iosys_file_native_vector_retrieve
			(synapse_io_system_opaque_reference(pVector), pVectorIndex);
}

size_t
synapse_io_system_file_vector_count
	(synapse_io_system_file_vector_handle pVector)
{
	return 
		__synapse_iosys_file_native_vector_count
			(synapse_io_system_opaque_reference(pVector));
}