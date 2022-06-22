#pragma once
#include <Windows.h>

typedef struct __synapse_io_system_file_aio_request
{
	OVERLAPPED aio_syshnd;
	size_t	   aio_size  ;
	void*	   aio_ptr   ;
} __synapse_io_system_file_aio_request;

typedef struct __synapse_io_system_file_aio
{
	HANDLE aio_hnd;
} __synapse_io_system_file_aio;