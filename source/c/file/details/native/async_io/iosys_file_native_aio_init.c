#include <io_system/file/details/native/async_io/iosys_file_native_aio_init.h>

__synapse_io_system_file_aio*
__synapse_io_system_file_aio_create_new
	(const wchar_t* pName)
{
	__synapse_io_system_file_aio* ptr_aio
		= malloc(sizeof(__synapse_io_system_file_aio));

	ptr_aio->aio_hnd
		= CreateFile(pName, GENERIC_ALL, 0, 0, CREATE_NEW, FILE_FLAG_OVERLAPPED, 0);
	return
		ptr_aio;
}

__synapse_io_system_file_aio*
__synapse_io_system_file_aio_open_existing
	(const wchar_t* pName)
{
	__synapse_io_system_file_aio* ptr_aio
		= malloc(sizeof(__synapse_io_system_file_aio));

	ptr_aio->aio_hnd
		= CreateFile(pName, GENERIC_ALL, 0, 0, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, 0);
	return
		ptr_aio;
}

__synapse_io_system_file_aio_request*
__synapse_io_system_file_aio_request_initialize
	(void* pAioPtr, size_t pAioSize, size_t pAioOffset)
{
	__synapse_io_system_file_aio_request* ptr_req
		= malloc(sizeof(__synapse_io_system_file_aio_request));

	ptr_req->aio_ptr  = pAioPtr;
	ptr_req->aio_size = pAioSize;
	
	ptr_req->aio_syshnd.Offset
		= pAioOffset;
	ptr_req->aio_syshnd.OffsetHigh
		= pAioOffset >> 32;
	ptr_req->aio_syshnd.hEvent
		= CreateEvent(NULL, FALSE, FALSE, NULL);

	return
		ptr_req;
}

__synapse_io_system_file_aio_request*
__synapse_io_system_file_aio_request_initialize_from_existing
	(__synapse_io_system_file_aio_request* pAioReq, void* pAioPtr, size_t pAioSize, size_t pAioOffset)
{
	pAioReq->aio_ptr  = pAioPtr;
	pAioReq->aio_size = pAioSize;
	
	pAioReq->aio_syshnd.Offset
		= pAioOffset;
	pAioReq->aio_syshnd.OffsetHigh
		= pAioOffset >> 32;

	return
		pAioReq;
}

void
__synapse_io_system_file_aio_cleanup
	(__synapse_io_system_file_aio* pAio)
{
	CloseHandle(pAio->aio_hnd);
	free	   (pAio);
}