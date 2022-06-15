#include <io_system/sched/file/default_context/default_context_init.h>
#include <io_system/sched/file/details/default_context/iosys_sched_context_init.h>

synapse_iosys_sched_default_context
synapse_iosys_sched_default_context_initialize()
{
	synapse_iosys_sched_default_context ptr_sched =
		{ .opaque = __synapse_iosys_sched_default_context_initialize() };

	return ptr_sched;
}

synapse_iosys_sched_default_context_io_request
synapse_iosys_sched_default_context_io_request_initialize
	(synapse_io_system_file* pFile, void* pIoPtr, size_t pIoSize, size_t pIoOffset)
{
	synapse_iosys_sched_default_context_io_request ptr_sched =
	{ .opaque = __synapse_iosys_sched_default_context_io_request_initialize
					(pFile, pIoPtr, pIoSize, pIoOffset) };

	return ptr_sched;
}

synapse_iosys_sched_default_context_io_request
synapse_iosys_sched_default_context_io_request_initialize_from_existing
	(synapse_iosys_sched_default_context_io_request pIoReq,
	 synapse_io_system_file* pFile,
	 void*  pIoPtr ,
	 size_t pIoSize, 
	 size_t pIoOffset)
{
	synapse_iosys_sched_default_context_io_request ptr_ioreq
		= { .opaque = __synapse_iosys_sched_default_context_io_request_initialize_from_existing
						(pIoReq.opaque, pFile, pIoPtr, pIoSize, pIoOffset) };

	return ptr_ioreq;
}

void
synapse_iosys_sched_default_context_cleanup
	(synapse_iosys_sched_default_context pIoSched)
{
	__synapse_iosys_sched_default_context_cleanup
		(pIoSched.opaque);
}

void
synapse_iosys_sched_default_context_io_request_cleanup
	(synapse_iosys_sched_default_context_io_request pIoReq)
{
	__synapse_iosys_sched_default_context_io_request_cleanup
		(pIoReq.opaque);
}