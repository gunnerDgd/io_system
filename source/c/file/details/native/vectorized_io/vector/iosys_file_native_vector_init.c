#include <io_system/file/details/native/vectorized_io/vector/iosys_file_native_vector_init.h>

__synapse_iosys_file_native_vectorized_vector*
__synapse_iosys_file_native_vector_initialize
	(size_t pVecCount)
{
	__synapse_iosys_file_native_vectorized_vector* ptr_vector
		= malloc(sizeof(__synapse_iosys_file_native_vectorized_vector));

	ptr_vector->cnt_vector			= pVecCount;
	ptr_vector->cnt_occupied_vector = 0		   ;
	ptr_vector->ptr_vector			= malloc(sizeof(FILE_SEGMENT_ELEMENT) * (pVecCount + 1));

	memset(ptr_vector->ptr_vector, 0x00, sizeof(FILE_SEGMENT_ELEMENT) * (pVecCount + 1));
	return ptr_vector;
}

void
__synapse_iosys_file_native_vector_cleanup
	(__synapse_iosys_file_native_vectorized_vector* pVector)
{
	for(size_t cnt_cleanup = 0 ;
			   cnt_cleanup < pVector->cnt_occupied_vector;
			   cnt_cleanup)
		VirtualFree(pVector->ptr_vector[cnt_cleanup].Buffer, 0, MEM_RELEASE);

	free(pVector->ptr_vector);
	free(pVector);
}