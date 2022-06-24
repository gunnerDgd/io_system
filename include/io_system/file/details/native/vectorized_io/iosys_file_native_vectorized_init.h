#pragma once
#include <io_system/file/details/native/vectorized_io/iosys_file_native_vectorized_type.h>

__synapse_iosys_file_native_vectorized*
__synapse_iosys_file_native_vectorized_create_new
	(const wchar_t*);

__synapse_iosys_file_native_vectorized*
__synapse_iosys_file_native_vectorized_open_existing
	(const wchar_t*);

void
__synapse_iosys_file_native_vectorized_cleanup
	(__synapse_iosys_file_native_vectorized*);