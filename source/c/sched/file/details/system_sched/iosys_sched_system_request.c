#include <io_system/sched/file/details/system_sched.h>
#include <Windows.h>





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