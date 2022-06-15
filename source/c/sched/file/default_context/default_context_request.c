#include <io_system/sched/file/default_context/default_context_request.h>
#include <io_system/sched/file/details/default_context/iosys_sched_context_request.h>

void
synapse_iosys_sched_default_context_dispatch_read
	(synapse_iosys_sched_default_context* pIoSched, synapse_iosys_sched_default_context_io_request* pIoReq)
{
	__synapse_iosys_sched_default_context_dispatch_read
		(pIoSched->opaque, pIoReq->opaque);
}

void
synapse_iosys_sched_default_context_dispatch_write
	(synapse_iosys_sched_default_context* pIoSched, synapse_iosys_sched_default_context_io_request* pIoReq)
{
	__synapse_iosys_sched_default_context_dispatch_write
		(pIoSched->opaque, pIoReq->opaque);
}