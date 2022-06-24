#include <io_system/file/details/native/async_io/iosys_file_native_aio_manip.h>

__synapse_io_system_file_aio_request*
__synapse_io_system_file_aio_read_from
	(__synapse_io_system_file_aio* pAio, __synapse_io_system_file_aio_request* pAioReq)
{
	DWORD res_aioreq_sz;
	BOOL  res_aioreq_suc
		= ReadFile(pAio->aio_hnd, 
				   pAioReq->aio_ptr, 
				   pAioReq->aio_size, 
					&res_aioreq_sz, 
					&pAioReq->aio_syshnd);

	return pAioReq;
}

__synapse_io_system_file_aio_request*
__synapse_io_system_file_aio_write_to
	(__synapse_io_system_file_aio* pAio, __synapse_io_system_file_aio_request* pAioReq)
{
	DWORD res_aioreq_sz;
	BOOL  res_aioreq_suc
		= WriteFile (pAio->aio_hnd,
				   pAioReq->aio_ptr, 
				   pAioReq->aio_size, 
					&res_aioreq_sz, 
					&pAioReq->aio_syshnd);

	return pAioReq;
}

size_t
__synapse_io_systesm_file_aio_wait_until
	(__synapse_io_system_file_aio* pAio, __synapse_io_system_file_aio_request* pAioReq)
{
	DWORD res_aio_sz;
	GetOverlappedResult
		(pAio->aio_hnd, &pAioReq->aio_syshnd, &res_aio_sz, TRUE);

	return
		res_aio_sz;
}

size_t
__synapse_io_system_file_aio_poll
	(__synapse_io_system_file_aio* pAioHnd, __synapse_io_system_file_aio_request* pAioReq)
{
	DWORD res_aio = 0;
	GetOverlappedResult
		(pAioHnd->aio_hnd, &pAioReq->aio_syshnd, &res_aio, FALSE);

	return res_aio;
}