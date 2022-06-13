#include <io_system/file/details/native/vectorized_io/iosys_file_native_vector_manip.h>

size_t
__synapse_iosys_file_native_vector_push_vector(__synapse_iosys_file_native_vector* pVector, void* pVecPtr, size_t pVecSize)
{
	if (pVector->cnt_occupied_vector >= pVector->cnt_vector)
		return pVector->cnt_occupied_vector;

	pVector->ptr_vector[pVector->cnt_occupied_vector].Alignment = 
}