#pragma once
#include <io_system/file/details/native/vectorized_io/iosys_file_native_vectorized_type.h>

__synapse_iosys_file_native_vectorized_vector*
__synapse_iosys_file_native_vector_initialize
	(size_t);

void
__synapse_iosys_file_native_vector_cleanup
	(__synapse_iosys_file_native_vectorized_vector*);