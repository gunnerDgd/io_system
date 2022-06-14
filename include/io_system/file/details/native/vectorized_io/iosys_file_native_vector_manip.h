#pragma once
#include <io_system/file/details/native/iosys_file_native_type.h>

void*
__synapse_iosys_file_native_vector_push    (__synapse_iosys_file_native_vector*, size_t);

void
__synapse_iosys_file_native_vector_pop	   (__synapse_iosys_file_native_vector*);

size_t
__synapse_iosys_file_native_vector_count   (__synapse_iosys_file_native_vector*);

void*
__synapse_iosys_file_native_vector_retrieve(__synapse_iosys_file_native_vector*, size_t);