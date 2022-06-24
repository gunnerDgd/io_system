#pragma once
#include <io_system/file/details/native/vectorized_io/iosys_file_native_vectorized_type.h>
#include <io_system/file/file_vectorized_traits.h>

size_t
__synapse_iosys_file_native_vector_read_from
	(__synapse_iosys_file_native_vectorized*, 
	 __synapse_iosys_file_native_vectorized_request*);

size_t
__synapse_iosys_file_native_vector_write_to 
	(__synapse_iosys_file_native_vectorized*, 
	 __synapse_iosys_file_native_vectorized_request*);

size_t
__synapse_iosys_file_native_vector_wait_until
	(__synapse_iosys_file_native_vectorized*,
	 __synapse_iosys_file_native_vectorized_request*);

size_t
__synapse_iosys_file_native_vector_poll
	(__synapse_iosys_file_native_vectorized*,
	 __synapse_iosys_file_native_vectorized_request*);