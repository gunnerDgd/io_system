#pragma once
#include <io_system/file/file_aio_traits.h>

synapse_io_system_file_aio_handle
synapse_io_system_file_aio_create_new
	(const wchar_t*);

synapse_io_system_file_aio_handle
synapse_io_system_file_aio_open_existing
	(const wchar_t*);

synapse_io_system_file_aio_request
synapse_io_system_file_aio_request_initialize
	(void*, size_t, size_t);

synapse_io_system_file_aio_request
synapse_io_system_file_aio_request_initialize_from_existing
	(synapse_io_system_file_aio_request, void*, size_t, size_t);

void
synapse_io_system_file_aio_cleanup
	(synapse_io_system_file_aio_handle);

void
synapse_io_system_file_aio_request_cleanup
	(synapse_io_system_file_aio_request);