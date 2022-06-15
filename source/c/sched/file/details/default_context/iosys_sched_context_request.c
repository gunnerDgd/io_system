#include <io_system/sched/file/details/default_context/iosys_sched_context_request.h>
#include <io_system/sched/file/details/default_context/iosys_sched_context_exec.h>
#include <Windows.h>

__synapse_iosys_sched_default_context_io_request*
__synapse_iosys_sched_default_context_retrive_completed
	(__synapse_iosys_sched_default_context*);

void
__synapse_iosys_sched_default_context_dispatch_read
	(__synapse_iosys_sched_default_context* pIoSched, 
	 __synapse_iosys_sched_default_context_io_request* pIoReq)
{
	pIoReq->hnd_io_context.hnd_context
		= synapse_context_default_initialize();
	pIoReq->hnd_io_context.ptr_io_context_stack
		= VirtualAlloc(NULL, 4096 * 3, MEM_COMMIT, PAGE_READWRITE);
	pIoReq->hnd_io_context.size_io_context_stack
		= 4096 * 3;

	pIoReq->hnd_io_context.hnd_context_loop
		= synapse_context_default_execute_from
			(pIoReq->hnd_io_context.hnd_context,
			&__synapse_iosys_sched_default_context_do_read,
			 pIoReq);
}

void
__synapse_iosys_sched_default_context_dispatch_write
	(__synapse_iosys_sched_default_context* pIoSched, 
	 __synapse_iosys_sched_default_context_io_request* pIoReq)
{
	pIoReq->hnd_io_context.hnd_context
		= synapse_context_default_initialize();
	pIoReq->hnd_io_context.ptr_io_context_stack
		= VirtualAlloc(NULL, 4096 * 3, MEM_COMMIT, PAGE_READWRITE);
	pIoReq->hnd_io_context.size_io_context_stack
		= 4096 * 3;

	pIoReq->hnd_io_context.hnd_context_loop
		= synapse_context_default_execute_from
			(pIoReq->hnd_io_context.hnd_context,
			&__synapse_iosys_sched_default_context_do_write,
			 pIoReq);
}