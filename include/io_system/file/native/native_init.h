#pragma once
#include <io_system/file/file_traits.h>

synapse_io_system_file_handle
synapse_iosys_file_native_initialize_open_existing
	(const wchar_t*);

synapse_io_system_file_handle
synapse_iosys_file_native_initialize_create_new
	(const wchar_t*);

void
synapse_iosys_file_native_cleanup
	(synapse_io_system_file_handle);