#pragma once
#include <io_system/file/details/native/async_io/iosys_file_native_aio_type.h>

__synapse_io_system_file_aio*
__synapse_io_system_file_aio_create_new
	(const wchar_t*);

__synapse_io_system_file_aio*
__synapse_io_system_file_aio_open_existing
	(const wchar_t*);

__synapse_io_system_file_aio_request*
__synapse_io_system_file_aio_request_initialize
	(void*, size_t, size_t);

__synapse_io_system_file_aio_request*
__synapse_io_system_file_aio_request_initialize_from_existing
	(__synapse_io_system_file_aio_request*, void*, size_t, size_t);

void
__synapse_io_system_file_aio_cleanup
	(__synapse_io_system_file_aio*);

void
__synapse_io_system_file_aio_request_cleanup
	(__synapse_io_system_file_aio_request*);