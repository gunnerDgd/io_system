#include <io_system/file/details/native/vectorized_io/iosys_file_native_vector_manip.h>
#include <Windows.h>

void*
__synapse_iosys_file_native_vector_push(__synapse_iosys_file_native_vector* pVector, size_t pVecCount)
{
	if (pVector->cnt_occupied_vector >= pVector->cnt_vector)
		return NULL;

	pVector->ptr_vector[pVector->cnt_occupied_vector].Buffer 
		= VirtualAlloc(NULL, pVecCount * 4096 * 4, MEM_COMMIT, PAGE_READWRITE);

	return pVector->ptr_vector[pVector->cnt_occupied_vector++].Buffer;
}

void
__synapse_iosys_file_native_vector_pop(__synapse_iosys_file_native_vector* pVector)
{
	if (!pVector->cnt_occupied_vector)
		return;

	VirtualFree(
		pVector->ptr_vector[pVector->cnt_occupied_vector].Buffer,
		0, MEM_FREE);

	--pVector->cnt_occupied_vector;
}

size_t
__synapse_iosys_file_native_vector_count(__synapse_iosys_file_native_vector* pVector)
{
	return pVector->cnt_occupied_vector;
}

void*
__synapse_iosys_file_native_vector_retrieve(__synapse_iosys_file_native_vector* pVector, size_t pVectorIndex)
{
	return pVector->ptr_vector[(pVectorIndex >= pVector->cnt_occupied_vector) ?
								pVector->cnt_occupied_vector
							  : pVectorIndex].Buffer;
}
