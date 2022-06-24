#pragma once
#include <stdint.h>
#include <io_system/defines/opaque/opaque.h>

synapse_io_system_opaque_define
	(synapse_io_system_file_aio_handle)

synapse_io_system_opaque_define
	(synapse_io_system_file_aio_request)

typedef struct synapse_io_system_file_aio_traits
{
	synapse_io_system_file_aio_handle
		aio_hnd;
	
	synapse_io_system_file_aio_request
		(*aio_create_request)
			(void*, size_t, size_t);
	synapse_io_system_file_aio_request
		(*aio_create_request_from_existing)
			(synapse_io_system_file_aio_request, void*, size_t, size_t);
	void
		(*aio_delete_request)
			(synapse_io_system_file_aio_request);

	synapse_io_system_file_aio_request
		(*aio_read_from) (synapse_io_system_file_aio_handle, synapse_io_system_file_aio_request);
	synapse_io_system_file_aio_request
		(*aio_write_to)  (synapse_io_system_file_aio_handle, synapse_io_system_file_aio_request);
	size_t
		(*aio_wait_until)(synapse_io_system_file_aio_handle, synapse_io_system_file_aio_request);
	size_t
		(*aio_poll)		 (synapse_io_system_file_aio_handle, synapse_io_system_file_aio_request);
} synapse_io_system_file_aio_traits;