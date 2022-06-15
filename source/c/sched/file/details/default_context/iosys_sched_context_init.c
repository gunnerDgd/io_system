#include <io_system/sched/file/details/default_context/iosys_sched_context_init.h>

#include <Windows.h>
#include <stdlib.h>

__synapse_iosys_sched_default_context*
__synapse_iosys_sched_default_context_initialize()
{
	__synapse_iosys_sched_default_context* ptr_sched
		= malloc(sizeof(__synapse_iosys_sched_default_context));

	ptr_sched->hnd_queue_processing
		= synapse_structure_linear_queue_initialize_default();
	ptr_sched->hnd_queue_completed
		= synapse_structure_linear_queue_initialize_default();

	return ptr_sched;
}

void
__synapse_iosys_sched_default_context_cleanup(__synapse_iosys_sched_default_context* pIoSched)
{
	synapse_structure_linear_queue_cleanup
		(pIoSched->hnd_queue_processing);
	synapse_structure_linear_queue_cleanup
		(pIoSched->hnd_queue_completed);

	free(pIoSched);
}

__synapse_iosys_sched_default_context_io_request*
__synapse_iosys_sched_default_context_io_request_initialize
	(synapse_io_system_file* pFile, void* pIoPtr, size_t pIoSize, size_t pIoOffset)
{
	__synapse_iosys_sched_default_context_io_request*
		ptr_io_req = malloc(sizeof(__synapse_iosys_sched_default_context_io_request));

	ptr_io_req->io_req_offset = pIoOffset;
	ptr_io_req->io_req_size   = pIoSize  ;
	ptr_io_req->io_req_ptr    = pIoPtr   ;
	ptr_io_req->hnd_file      = pFile    ;

	ptr_io_req->hnd_io_context.hnd_context
		= synapse_context_default_initialize();
	ptr_io_req->hnd_io_context.ptr_io_context_stack
		= VirtualAlloc(NULL, 4096 * 3, MEM_COMMIT, PAGE_READWRITE);
	ptr_io_req->hnd_io_context.size_io_context_stack
		= 4096 * 3;

	synapse_context_default_attach_stack
		(ptr_io_req->hnd_io_context.hnd_context			  ,
		 ptr_io_req->hnd_io_context.ptr_io_context_stack  ,
		 ptr_io_req->hnd_io_context.size_io_context_stack);

	return ptr_io_req;
}

__synapse_iosys_sched_default_context_io_request*
__synapse_iosys_sched_default_context_io_request_initialize_from_existing
	(__synapse_iosys_sched_default_context_io_request* pIoReq,
	 synapse_io_system_file* pIoFile,
	 void*  pIoPtr ,
	 size_t pIoSize,
	 size_t pIoOffset)
{
	pIoReq->hnd_file      = pIoFile;
	pIoReq->io_req_ptr    = pIoPtr ;
	pIoReq->io_req_size   = pIoSize;
	pIoReq->io_req_offset = pIoOffset;
	pIoReq->hnd_io_context.hnd_context
		= synapse_context_default_initialize_from_existing
			(pIoReq->hnd_io_context.hnd_context);

	return pIoReq; 
}

void
__synapse_iosys_sched_default_context_io_request_cleanup
	(__synapse_iosys_sched_default_context_io_request* pIoReq)
{
	VirtualFree(pIoReq->hnd_io_context.ptr_io_context_stack, 0, MEM_FREE);
	synapse_context_default_cleanup(pIoReq->hnd_io_context.hnd_context)		;
	synapse_context_default_cleanup(pIoReq->hnd_io_context.hnd_context_loop);

	free(pIoReq);
}