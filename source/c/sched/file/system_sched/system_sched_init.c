#include <io_system/sched/file/system_sched/system_sched_init.h>

#include <io_system/sched/file/details/system_sched/iosys_sched_system_request.h>
#include <io_system/sched/file/details/system_sched/iosys_sched_system_init.h>

synapse_iosys_sched_system
synapse_iosys_sched_system_initialize(size_t pIoThreadCount)
{
	synapse_iosys_sched_system ptr_iosys
		= { .opaque = __synapse_iosys_sched_system_initialize(pIoThreadCount) };

	return
		ptr_iosys;
}

synapse_iosys_sched_system
synapse_iosys_sched_system_initialize_default()
{
	synapse_iosys_sched_system ptr_iosys
		= { .opaque = __synapse_iosys_sched_system_initialize_default() };

	return
		ptr_iosys;
}

synapse_iosys_sched_system_io_request
synapse_iosys_sched_system_io_request_initialize(void* pIoPtr, size_t pIoSize, size_t pIoOffset)
{
	synapse_iosys_sched_system_io_request ptr_ioreq
		= { .opaque = __synapse_iosys_sched_system_io_request_initialize(pIoPtr, pIoSize, pIoOffset) };

	return ptr_ioreq;
}

synapse_iosys_sched_system_io_session
synapse_iosys_sched_system_io_session_initialize(synapse_iosys_sched_system pIoSys, synapse_io_system_file* pFile)
{
	synapse_iosys_sched_system_io_session ptr_iosess
		= { .opaque = __synapse_iosys_sched_system_io_session_initialize(pIoSys.opaque, pFile->handle.opaque) };

	return ptr_iosess;
}

void
synapse_iosys_sched_system_cleanup(synapse_iosys_sched_system pIoSys)
{
	__synapse_iosys_sched_system_cleanup(pIoSys.opaque);
}

void
synapse_iosys_sched_system_io_session_cleanup(synapse_iosys_sched_system_io_session pIoSession)
{
	__synapse_iosys_sched_system_io_session_cleanup(pIoSession.opaque);
}


void
synapse_iosys_sched_system_io_request_cleanup(synapse_iosys_sched_system_io_request pIoReq)
{
	__synapse_iosys_sched_system_io_request_cleanup(pIoReq.opaque);
}