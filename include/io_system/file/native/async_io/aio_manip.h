#pragma once
#include <stdint.h>
#include <io_system/file/file_aio_traits.h>

synapse_io_system_file_aio_request
synapse_io_system_file_aio_read_from
	(synapse_io_system_file_aio_handle, void*, size_t, size_t);

synapse_io_system_file_aio_request
synapse_io_system_file_aio_write_to
	(synapse_io_system_file_aio_handle, void*, size_t, size_t);

size_t
synapse_io_system_file_aio_wait_until
	(synapse_io_system_file_aio_handle, synapse_io_system_file_aio_request);

size_t
synapse_io_system_file_aio_poll
	(synapse_io_system_file_aio_handle, synapse_io_system_file_aio_request);