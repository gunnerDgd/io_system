#pragma once
#include <stdint.h>
#include <Windows.h>

#include <io_system/file/details/native/iosys_file_native.h>

typedef struct __synapse_iosys_sched_system
{
	HANDLE hnd_sched	   ;
	size_t hnd_sched_thread;
} __synapse_iosys_sched_system;

typedef struct __synapse_iosys_sched_system_io_request
{
	OVERLAPPED					 hnd_sched_req ;
	__synapse_iosys_file_native* hnd_sched_file;

	void*						 req_io_buffer;
	size_t						 req_io_size  ;
	size_t						 req_io_result;
} __synapse_iosys_sched_system_io_request;