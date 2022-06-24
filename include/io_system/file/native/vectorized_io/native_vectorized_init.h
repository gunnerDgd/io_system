#pragma once
#include <io_system/file/file_vectorized_traits.h>

synapse_io_system_file_vectorized_handle
synapse_io_system_file_vectorized_open_existing
	(const wchar_t*);

synapse_io_system_file_vectorized_handle
synapse_io_system_file_vectorized_create_new
	(const wchar_t*);

void
synapse_io_system_file_vectorized_cleanup
	(synapse_io_system_file_vectorized_handle);