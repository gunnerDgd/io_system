#include <io_system/file/native/vectorized_io/native_vectorized_io.h>
#include <io_system/file/details/native/vectorized_io/iosys_file_native_vector_manip.h>

void*
synapse_io_system_file_vector_push(synapse_io_system_file_vector_handle pVector, size_t pVectorSize)
{
	return __synapse_iosys_file_native_vector_push(pVector.opaque, pVectorSize);
}

void
synapse_io_system_file_vector_pop(synapse_io_system_file_vector_handle pVector)
{
	__synapse_iosys_file_native_vector_pop(pVector.opaque);
}

void*
synapse_io_system_file_vector_retrieve(synapse_io_system_file_vector_handle pVector, size_t pVectorIndex)
{
	return __synapse_iosys_file_native_vector_retrieve(pVector.opaque, pVectorIndex);
}

size_t
synapse_io_system_file_vector_count(synapse_io_system_file_vector_handle pVector)
{
	return __synapse_iosys_file_native_vector_count(pVector.opaque);
}