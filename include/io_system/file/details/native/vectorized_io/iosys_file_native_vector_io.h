#pragma once
#include <io_system/file/details/native/iosys_file_native_type.h>
#include <io_system/file/file_io_system.h>

size_t
__synapse_iosys_file_native_vector_read_from
	(__synapse_iosys_file_native*, __synapse_iosys_file_native_vector*, size_t);

size_t
__synapse_iosys_file_native_vector_write_to 
	(__synapse_iosys_file_native*, __synapse_iosys_file_native_vector*, size_t);