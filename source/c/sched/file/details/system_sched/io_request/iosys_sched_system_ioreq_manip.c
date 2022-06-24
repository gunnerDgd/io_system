#include <io_system/sched/file/details/system_sched/io_request/iosys_sched_system_ioreq_manip.h>

void
__synapse_iosys_sched_system_io_request_do_completion
	(DWORD pErrorCode, DWORD pIoBytes, LPOVERLAPPED pAioHnd)
{
	__synapse_iosys_sched_system_io_request* pIoReq
		= pAioHnd;

	pIoReq->req_io_completion_routine
		(pIoReq->req_io_completion_param);
}

void
__synapse_iosys_sched_system_io_request_dispatch_read
	(__synapse_iosys_sched_system_io_session* pSession, __synapse_iosys_sched_system_io_request* pIoReq)
{
	ReadFileEx(pSession->hnd_sched_file->aio_hnd,
			   pIoReq->req_io_buffer		    ,
			   pIoReq->req_io_size			    ,
			  &pIoReq->hnd_sched_req		    ,
			  &__synapse_iosys_sched_system_io_request_do_completion);
}

void
__synapse_iosys_sched_system_io_request_dispatch_write
	(__synapse_iosys_sched_system_io_session* pSession, __synapse_iosys_sched_system_io_request* pIoReq)
{
	DWORD dummy;
	WriteFile(pSession->hnd_sched_file->aio_hnd,
			  pIoReq->req_io_buffer,
			  pIoReq->req_io_size,
			  &dummy,
			  &pIoReq->hnd_sched_req);
}