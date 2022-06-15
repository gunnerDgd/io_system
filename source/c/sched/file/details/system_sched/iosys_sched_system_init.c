#include <io_system/sched/file/details/system_sched/iosys_sched_system_init.h>
#include <Windows.h>

__synapse_iosys_sched_system*
__synapse_iosys_sched_system_initialize(size_t pSchedThreadCount)
{
	__synapse_iosys_sched_system* ptr_sched
		= malloc(sizeof(__synapse_iosys_sched_system));

	ptr_sched->hnd_sched
		= CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, pSchedThreadCount);
	ptr_sched->hnd_sched_thread
		= pSchedThreadCount;

	return ptr_sched;
}
__synapse_iosys_sched_system*
__synapse_iosys_sched_system_initialize_default()
{
	__synapse_iosys_sched_system* ptr_sched
		= malloc(sizeof(__synapse_iosys_sched_system));
	
	SYSTEM_INFO				 ptr_sysinfo;
	GetSystemInfo(&ptr_sysinfo);

	ptr_sched->hnd_sched_thread
		= ptr_sysinfo.dwNumberOfProcessors * 2;
	ptr_sched->hnd_sched
		= CreateIoCompletionPort(INVALID_HANDLE_VALUE, 0, 0, ptr_sched->hnd_sched_thread);

	return ptr_sched;
}

void
__synapse_iosys_sched_system_cleanup(__synapse_iosys_sched_system* pSched)
{
	CloseHandle(pSched->hnd_sched);
	free	   (pSched);
}

__synapse_iosys_sched_system_io_session*
__synapse_iosys_sched_system_io_session_initialize
	(__synapse_iosys_sched_system* pSched, __synapse_iosys_file_native* pNative)
{
	__synapse_iosys_sched_system_io_session* ptr_io_session
		= malloc(sizeof(__synapse_iosys_sched_system_io_session));

	pSched->hnd_sched
		= CreateIoCompletionPort(pNative->hnd_file,
								 pSched->hnd_sched,
								 ptr_io_session,
								 pSched->hnd_sched_thread);

	ptr_io_session->hnd_sched	   = pSched;
	ptr_io_session->hnd_sched_file = pNative;

	return ptr_io_session;
}

void
__synapse_iosys_sched_system_io_session_cleanup(__synapse_iosys_sched_system_io_session* pSession)
{
	free(pSession);
}