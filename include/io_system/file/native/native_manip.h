#pragma once
#include <io_system/file/file_io_system.h>

size_t
synapse_iosys_file_native_pointer_current(synapse_io_system_file_handle);

size_t
synapse_iosys_file_native_pointer_set    (synapse_io_system_file_handle, size_t);

void
synapse_iosys_file_native_wait_until	 (synapse_io_system_file_handle);