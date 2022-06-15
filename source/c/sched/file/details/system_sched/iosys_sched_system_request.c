#include <io_system/sched/file/details/system_sched/iosys_sched_system_request.h>
#include <Windows.h>

__synapse_iosys_sched_system_io_request*
__synapse_iosys_sched_system_io_request_initialize
	(void* pIoPtr, size_t pIoSize, size_t pIoOffset)
{
	__synapse_iosys_sched_system_io_request* ptr_req
		= malloc(sizeof(__synapse_iosys_sched_system_io_request));

	ptr_req->hnd_sched_req.hEvent	  = CreateEvent(NULL, FALSE, FALSE, NULL);
	ptr_req->hnd_sched_req.Offset	  = pIoOffset	   ;
	ptr_req->hnd_sched_req.OffsetHigh = pIoOffset >> 32;

	ptr_req->req_io_size			  = pIoSize;
	ptr_req->req_io_buffer			  = pIoPtr ;

	return ptr_req;
}

void
__synapse_iosys_sched_system_io_request_cleanup
	(__synapse_iosys_sched_system_io_request* pIoReq)
{
	CloseHandle(pIoReq->hnd_sched_req.hEvent);
	free	   (pIoReq);
}

void
__synapse_iosys_sched_system_io_request_dispatch_read
	(__synapse_iosys_sched_system_io_session* pSession, __synapse_iosys_sched_system_io_request* pIoReq)
{
	DWORD dummy;
	ReadFile(pSession->hnd_sched_file->hnd_file,
			 pIoReq->req_io_buffer,
			 pIoReq->req_io_size  ,
			 &dummy,
			 &pIoReq->hnd_sched_req);
}

void
__synapse_iosys_sched_system_io_request_dispatch_write
	(__synapse_iosys_sched_system_io_session* pSession, __synapse_iosys_sched_system_io_request* pIoReq)
{
	DWORD dummy;
	WriteFile(pSession->hnd_sched_file->hnd_file,
			  pIoReq->req_io_buffer,
			  pIoReq->req_io_size,
			  &dummy,
			   &pIoReq->hnd_sched_req);
}

__synapse_iosys_sched_system_io_request*
__synapse_iosys_sched_system_io_request_retrive_completed
	(__synapse_iosys_sched_system* pSched)
{
	return
		__synapse_iosys_sched_system_io_request_retrieve_completed_until(pSched, INFINITE);
}

__synapse_iosys_sched_system_io_request*
__synapse_iosys_sched_system_io_request_retrieve_completed_until
	(__synapse_iosys_sched_system* pSched, uint64_t pIoReqWaitTime)
{
	__synapse_iosys_sched_system_io_request* ptr_hnd_io_request	  ;
	LPOVERLAPPED							 ptr_hnd_io_overlapped;
	DWORD									 sz_io_processed	  ;
	
	GetQueuedCompletionStatus(pSched->hnd_sched     ,
							  &sz_io_processed      ,
							  &ptr_hnd_io_request   ,
							  &ptr_hnd_io_overlapped,
							  pIoReqWaitTime);

	ptr_hnd_io_request->req_io_result
		= sz_io_processed;
	return ptr_hnd_io_request;
}

bool
__synapse_iosys_sched_system_io_request_wait
	(__synapse_iosys_sched_system_io_request* pIoReq)
{
	return
		__synapse_iosys_sched_system_io_request_wait_until(pIoReq, INFINITE);
}

bool
__synapse_iosys_sched_system_io_request_wait_until
	(__synapse_iosys_sched_system_io_request* pIoReq, uint32_t pIoWait)
{
	return
		(WaitForSingleObject(pIoReq->hnd_sched_req.hEvent, pIoWait) == WAIT_OBJECT_0)
			? true
			: false;
}