#include <io_system/sched/file/details/system_sched/io_request/iosys_sched_system_ioreq_init.h>

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

__synapse_iosys_sched_system_io_request*
__synapse_iosys_sched_system_io_request_initialize_from_existing
	(__synapse_iosys_sched_system_io_request* pIoReq, void* pIoPtr, size_t pIoSize, size_t pIoOffset)
{
	pIoReq->req_io_buffer = pIoPtr ;
	pIoReq->req_io_size	  = pIoSize;

	pIoReq->hnd_sched_req.Offset
		= pIoOffset;
	pIoReq->hnd_sched_req.OffsetHigh
		= pIoOffset >> 32;

	return pIoReq;
}

void
__synapse_iosys_sched_system_io_request_cleanup
	(__synapse_iosys_sched_system_io_request* pIoReq)
{
	CloseHandle(pIoReq->hnd_sched_req.hEvent);
	free	   (pIoReq);
}