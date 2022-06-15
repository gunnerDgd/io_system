#include <io_system/sched/file/details/system_sched/iosys_sched_system_request.h>
#include <Windows.h>

__synapse_iosys_sched_system_io_request*
__synapse_iosys_sched_system_io_request_initialize
	(__synapse_iosys_file_native* pFile, size_t pIoSize, size_t pIoOffset)
{
	__synapse_iosys_sched_system_io_request* ptr_req
		= malloc(sizeof(__synapse_iosys_sched_system_io_request));

	ptr_req->hnd_sched_file			  = pFile;
	ptr_req->hnd_sched_req.hEvent	  = CreateEvent(NULL, FALSE, FALSE, NULL);
	
	ptr_req->hnd_sched_req.Offset	  = pIoOffset;
	ptr_req->hnd_sched_req.OffsetHigh = pIoOffset >> 32;

	return ptr_req;
}

void
__synapse_iosys_sched_system_io_request_cleanup
	(__synapse_iosys_sched_system_io_request* pIoReq)
{
	CloseHandle(pIoReq->hnd_sched_req.hEvent);
	free	   (pIoReq);
}

bool
__synapse_iosys_sched_system_io_request_poll
	(__synapse_iosys_sched_system_io_request* pIoReq)
{

}

void
__synapse_iosys_sched_system_io_request_register
	(__synapse_iosys_sched_system* pSched, __synapse_iosys_file_native* pFile)
{
	pSched->hnd_sched
		= CreateIoCompletionPort(
			pFile->hnd_file  ,
			pSched->hnd_sched,
			pFile			 ,
			pSched->hnd_sched_thread);
}

void
__synapse_iosys_sched_system_io_request_dispatch_read
	(__synapse_iosys_sched_system* pSched, __synapse_iosys_sched_system_io_request* pIoReq)
{
	DWORD dummy;
	ReadFile(pIoReq->hnd_sched_file->hnd_file,
			 pIoReq->req_io_buffer,
			 pIoReq->req_io_size  ,
			 &dummy,
			 &pIoReq->hnd_sched_req);
}

void
__synapse_iosys_sched_system_io_request_dispatch_write
	(__synapse_iosys_sched_system* pSched, __synapse_iosys_sched_system_io_request* pIoReq)
{
	DWORD dummy;
	WriteFile(pIoReq->hnd_sched_file->hnd_file,
			  pIoReq->req_io_buffer,
			  pIoReq->req_io_size,
			  &dummy,
			   &pIoReq->hnd_sched_req);
}

void
__synapse_iosys_sched_system_io_request_cancel
	(__synapse_iosys_sched_system* pSched, __synapse_iosys_sched_system_io_request* pIoReq)
{
	CancelIo(pIoReq->hnd_sched_file);
}

void
__synapse_iosys_sched_system_io_request_wait
	(__synapse_iosys_sched_system* pSched, __synapse_iosys_sched_system_io_request* pIoReq)
{
	__synapse_iosys_sched_system_io_request_wait_until(pSched, pIoReq, INFINITE);
}

void
__synapse_iosys_sched_system_io_request_wait_until
	(__synapse_iosys_sched_system* pSched, __synapse_iosys_sched_system_io_request* pIoReq, uint64_t pIoReqWaitTime)
{
	LPOVERLAPPED ptr_hnd_ioreq  ;
	DWORD		 sz_io_processed;

	GetQueuedCompletionStatus(pSched->hnd_sched,
							  &sz_io_processed,
							  pIoReq,
							  &ptr_hnd_ioreq,
							  pIoReqWaitTime);
}