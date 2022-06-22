#include <io_system/file/native/native_io.h>
#include <io_system/file/details/native/iosys_file_native_io.h>
#include <io_system/file/details/native/vectorized_io/iosys_file_native_vector_io.h>

size_t
synapse_iosys_file_native_read_from(synapse_io_system_file_handle pEntity, void* pReadBuffer, size_t pReadSize)
{
	return __synapse_iosys_file_native_read_from(pEntity.opaque, pReadBuffer, pReadSize);
}

size_t
synapse_iosys_file_native_write_to(synapse_io_system_file_handle pEntity, void* pWriteBuffer, size_t pWriteSize)
{
	return __synapse_iosys_file_native_write_to (pEntity.opaque, pWriteBuffer, pWriteSize);
}

size_t
synapse_iosys_file_native_read_from_vector(synapse_io_system_file_handle pFile, synapse_io_system_file_vector* pVector, size_t pVectorOffset)
{
	return __synapse_iosys_file_native_vector_read_from(pFile.opaque, pVector->handle.opaque, pVectorOffset);
}

size_t
synapse_iosys_file_native_write_to_vector(synapse_io_system_file_handle pFile, synapse_io_system_file_vector* pVector, size_t pVectorOffset)
{
	return __synapse_iosys_file_native_vector_write_to (pFile.opaque, pVector->handle.opaque, pVectorOffset);
}