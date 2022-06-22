#pragma once
#include <io_system/file/native/async_io/aio_type.h>
#include <io_system/file/file_handle_type.h>

typedef struct synapse_io_system_file_aio
{
	synapse_io_system_file_handle
		aio_hnd;
	
	synapse_io_system_file_aio_request
		(*aio_read_from) (synapse_io_system_file_handle, synapse_io_system_file_aio_request);
	synapse_io_system_file_aio_request
		(*aio_write_to)  (synapse_io_system_file_handle, synapse_io_system_file_aio_request);
	size_t
		(*aio_wait_until)(synapse_io_system_file_handle, synapse_io_system_file_aio_request);
} synapse_io_system_file_aio;