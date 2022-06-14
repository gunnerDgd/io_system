#include <io_system/file/details/native/vectorized_io/iosys_file_native_vector_init.h>

__synapse_iosys_file_native_vector*
__synapse_iosys_file_native_vector_initialize(size_t pVecCount)
{
	__synapse_iosys_file_native_vector* ptr_vector
		= malloc(sizeof(__synapse_iosys_file_native_vector));

	ptr_vector->cnt_vector			= pVecCount;
	ptr_vector->cnt_occupied_vector = 0		   ;
	ptr_vector->ptr_vector			= malloc(sizeof(FILE_SEGMENT_ELEMENT) * (pVecCount + 1));

	memset(ptr_vector->ptr_vector, 0x00, sizeof(FILE_SEGMENT_ELEMENT) * (pVecCount + 1));
	return ptr_vector;
}

void
__synapse_iosys_file_native_vector_cleanup(__synapse_iosys_file_native_vector* pVector)
{
	free(pVector->ptr_vector);
	free(pVector);
}