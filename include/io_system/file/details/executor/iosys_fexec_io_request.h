#pragma once
#include <io_system/file/details/executor/iosys_fexec_io_type.h>
#include <io_system/file/details/executor/iosys_fexec_type.h>

__synapse_iosys_fexec_io_request*
__synapse_iosys_fexec_io_request_initialize_standard_read   (synapse_io_system_file*, size_t, size_t);

__synapse_iosys_fexec_io_request*
__synapse_iosys_fexec_io_request_initialize_vectorized_read (synapse_io_system_file*, size_t, size_t);

__synapse_iosys_fexec_io_request*
__synapse_iosys_fexec_io_request_initialize_standard_write  (synapse_io_system_file*, size_t, size_t);

__synapse_iosys_fexec_io_request*
__synapse_iosys_fexec_io_request_initialize_vectorized_write(synapse_io_system_file*, size_t, size_t);

void
__synapse_iosys_fexec_io_request_cleanup				    (__synapse_iosys_fexec_io_request*);


size_t
__synapse_iosys_fexec_io_request_read_standard   (synapse_context_default_entity, void*);

size_t
__synapse_iosys_fexec_io_request_read_vectorized (synapse_context_default_entity, void*);

size_t
__synapse_iosys_fexec_io_request_write_standard  (synapse_context_default_entity, void*);

size_t
__synapse_iosys_fexec_io_request_write_vectorized(synapse_context_default_entity, void*);