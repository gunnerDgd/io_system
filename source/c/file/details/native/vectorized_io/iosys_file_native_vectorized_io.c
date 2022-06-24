#include <io_system/file/details/native/vectorized_io/iosys_file_native_vectorized_io.h>

size_t
__synapse_iosys_file_native_vector_read_from
	(__synapse_iosys_file_native_vectorized		    *pFile, 
	 __synapse_iosys_file_native_vectorized_request *pVectorReq)
{
	BOOL  res_vecio = ReadFileScatter(
						pFile->hnd_file,
						pVectorReq->hnd_vec->ptr_vector,
						pVectorReq->hnd_vec->cnt_vector * 4096,
						0,
						&pVectorReq->hnd_vec_aio);

	return 0;
}

size_t
__synapse_iosys_file_native_vector_write_to
	(__synapse_iosys_file_native_vectorized		    *pFile,
	 __synapse_iosys_file_native_vectorized_request *pVectorReq)
{
	BOOL  res_vecio = WriteFileGather(
						pFile->hnd_file,
						pVectorReq->hnd_vec->ptr_vector,
						pVectorReq->hnd_vec->cnt_vector * 4096,
						0,
						&pVectorReq->hnd_vec_aio);

	return 0;
}

size_t
__synapse_iosys_file_native_vector_wait_until
	(__synapse_iosys_file_native_vectorized* pVecHnd,
	 __synapse_iosys_file_native_vectorized_request* pVecReq)
{
	DWORD res_vecio;
	GetOverlappedResult
		(pVecHnd->hnd_file, &pVecReq->hnd_vec_aio, &res_vecio, TRUE);

	return
		res_vecio;
}

size_t
__synapse_iosys_file_native_vector_poll
	(__synapse_iosys_file_native_vectorized* pVecHnd,
	 __synapse_iosys_file_native_vectorized_request* pVecReq)
{
	DWORD res_vecio;
	GetOverlappedResult
		(pVecHnd->hnd_file, &pVecReq->hnd_vec_aio, &res_vecio, FALSE);

	return
		res_vecio;
}