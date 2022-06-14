#include <io_system/file/details/native/vectorized_io/iosys_file_native_vector_io.h>
#include <Windows.h>

size_t
__synapse_iosys_file_native_vector_push_vector(__synapse_iosys_file_native_vector* pVector, void* pVecPtr)
{
	if (pVector->cnt_occupied_vector >= pVector->cnt_vector)
		return pVector->cnt_occupied_vector;

	pVector->ptr_vector[pVector->cnt_occupied_vector].Buffer = pVecPtr;
	return			  ++pVector->cnt_occupied_vector;
}

