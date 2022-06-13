#pragma once
#include <io_system/file/details/native/iosys_file_native_type.h>
#include <io_system/file/file_io_system.h>

__synapse_iosys_file_native_vector*
__synapse_iosys_file_native_vector_initialize(size_t);

void
__synapse_iosys_file_native_vector_cleanup   (__synapse_iosys_file_native_vector*);