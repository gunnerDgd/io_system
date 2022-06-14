#include <io_system/file/details/native/vectorized_io/iosys_file_native_vector_io.h>
#include <stdio.h>

size_t
__synapse_iosys_file_native_vector_read_from(__synapse_iosys_file_native* pFile, __synapse_iosys_file_native_vector* pVector, size_t pVectorOffset)
{
	BOOL  res_vecio; 
	DWORD res_vecio_read;

	pFile->hnd_aio.Offset	  = pVectorOffset	   ;
	pFile->hnd_aio.OffsetHigh = pVectorOffset >> 32;

	res_vecio = ReadFileScatter(pFile  ->hnd_file,
	 							pVector->ptr_vector, 
							    pVector->cnt_occupied_vector * 4096, 0, &pFile->hnd_aio);

	printf("%d\n", GetLastError());

	GetOverlappedResult(pFile->hnd_file,
					   &pFile->hnd_aio ,
					   &res_vecio_read, FALSE);

	return res_vecio_read;
}

size_t
__synapse_iosys_file_native_vector_write_to(__synapse_iosys_file_native* pFile, __synapse_iosys_file_native_vector* pVector, size_t pVectorOffset)
{
	BOOL  res_vecio;
	DWORD res_vecio_write;

	pFile->hnd_aio.Offset	  = pVectorOffset	   ;
	pFile->hnd_aio.OffsetHigh = pVectorOffset >> 32;

	res_vecio = WriteFileGather(pFile  ->hnd_file,
							    pVector->ptr_vector, 
								pVector->cnt_occupied_vector * 4096, 0, &pFile->hnd_aio);

	printf("%d\n", GetLastError());

	GetOverlappedResult(pFile->hnd_file,
					   &pFile->hnd_aio ,
					   &res_vecio_write, FALSE);

	return res_vecio_write;
}