#pragma once
#include <io_system/file/file_io_system.h>

size_t
synapse_iosys_file_native_read_from		  (synapse_io_system_file_handle, void*, size_t, size_t);

size_t
synapse_iosys_file_native_read_from_vector(synapse_io_system_file_handle, synapse_io_system_file_vector*, size_t);

size_t
synapse_iosys_file_native_write_to		  (synapse_io_system_file_handle, void*, size_t, size_t);

size_t
synapse_iosys_file_native_write_to_vector(synapse_io_system_file_handle, synapse_io_system_file_vector*, size_t);