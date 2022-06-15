#include <io_system/sched/file/system_sched/system_sched_request.h>

synapse_iosys_sched_system_io_request
synapse_iosys_sched_system_retrieve_completed(synapse_iosys_sched_system pIoSys)
{
	synapse_iosys_sched_system_io_request ptr_io_req
		= { .opaque = __synapse_iosys_sched_system_io_request_retrive_completed(pIoSys.opaque) };

	return
		ptr_io_req;
}

synapse_iosys_sched_system_io_request
synapse_iosys_sched_system_retrieve_completed_until(synapse_iosys_sched_system pIoSys, uint32_t pIoWaitTime)
{
	synapse_iosys_sched_system_io_request ptr_io_req
		= { .opaque 
				= __synapse_iosys_sched_system_io_request_retrieve_completed_until(pIoSys.opaque, pIoWaitTime) };

	return
		ptr_io_req;
}

void
synapse_iosys_sched_system_dispatch_read
	(synapse_iosys_sched_system_io_session pIoSession, synapse_iosys_sched_system_io_request pIoReq)
{
	__synapse_iosys_sched_system_io_request_dispatch_read(
		pIoSession.opaque, 
		pIoReq	  .opaque
	);
}

void
synapse_iosys_sched_system_dispatch_write
	(synapse_iosys_sched_system_io_session pIoSession, synapse_iosys_sched_system_io_request pIoReq)
{
	__synapse_iosys_sched_system_io_request_dispatch_read(
		pIoSession.opaque,
		pIoReq	  .opaque
	);
}

bool
synapse_iosys_sched_system_wait(synapse_iosys_sched_system_io_request pIoReq)
{
	return
		__synapse_iosys_sched_system_io_request_wait(pIoReq.opaque);
}

bool
synapse_iosys_sched_system_wait_until(synapse_iosys_sched_system_io_request pIoReq, uint32_t pIoWaitTime)
{
	return
		__synapse_iosys_sched_system_io_request_wait_until(pIoReq.opaque, pIoWaitTime);
}