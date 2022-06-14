#include <io_system/file/details/native/vectorized_io/iosys_file_native_vector_manip.h>
#include <Windows.h>

size_t
__synapse_iosys_file_native_vector_push_vector(__synapse_iosys_file_native_vector* pVector, void* pVecPtr)
{
	if (pVector->cnt_occupied_vector >= pVector->cnt_vector)
		return pVector->cnt_occupied_vector;

	pVector->ptr_vector[pVector->cnt_occupied_vector].Buffer = pVecPtr;
	return			  ++pVector->cnt_occupied_vector;
}

size_t
__synapse_iosys_file_native_vector_read_from(__synapse_iosys_file_native* pFile, __synapse_iosys_file_native_vector* pVector, size_t pVectorOffset)
{
	OVERLAPPED win32_overlapped =
	{
		.Offset = pVectorOffset & 0xFFFFFFFF,
		.OffsetHigh = pVectorOffset >> 32
	};

	BOOL res_vecio = ReadFileScatter(pFile->hnd_file, 
							 pVector->ptr_vector, 
					  pVector->cnt_occupied_vector * 4096, 0, &win32_overlapped);

	return (res_vecio) ? pVector->cnt_occupied_vector * 4096 : 0;
}

size_t
__synapse_iosys_file_native_vector_write_to(__synapse_iosys_file_native* pFile, __synapse_iosys_file_native_vector* pVector, size_t pVectorOffset)
{
	OVERLAPPED win32_overlapped =
	{
		.Offset		= pVectorOffset & 0xFFFFFFFF,
		.OffsetHigh = pVectorOffset >> 32
	};

	BOOL res_vecio = WriteFileGather(pFile->hnd_file, 
							 pVector->ptr_vector, 
					  pVector->cnt_occupied_vector * 4096, 0, &win32_overlapped);

	return (res_vecio) ? pVector->cnt_occupied_vector * 4096 : 0;
}