#pragma once
#include <stdint.h>
#include <Windows.h>

#include <io_system/file/file_traits.h>
#include <io_system/file/file_aio_traits.h>
#include <io_system/file/details/native/async_io/iosys_file_native_aio_type.h>

typedef struct __synapse_iosys_sched_system
{
	HANDLE hnd_sched	   ;
	size_t hnd_sched_thread;
} __synapse_iosys_sched_system;

typedef struct __synapse_iosys_sched_system_io_session
{
	__synapse_io_system_file_aio *hnd_sched_file;
	__synapse_iosys_sched_system *hnd_sched;
} __synapse_iosys_sched_system_io_session;

typedef struct __synapse_iosys_sched_system_io_request
{
	OVERLAPPED hnd_sched_req;

	void*	   req_io_buffer;
	size_t	   req_io_size  ;
	size_t	   req_io_result;

	void     (*req_io_completion_routine)(void*);
	void      *req_io_completion_param;
} __synapse_iosys_sched_system_io_request;