#include <io_system/file/details/executor/iosys_fexec_io_request.h>
#include <context/all.h>

#include <stdlib.h>

__synapse_iosys_fexec_io_request*
__synapse_iosys_fexec_io_request_initialize_vectorized_write(synapse_io_system_file, size_t, size_t);

__synapse_iosys_fexec_io_request*
__synapse_iosys_fexec_io_request_initialize_vectorized_read(synapse_io_system_file, size_t, size_t);

size_t
__synapse_iosys_fexec_io_request_read_vectorized(__synapse_iosys_fexec*, void*);

size_t
__synapse_iosys_fexec_io_request_write_vectorized(__synapse_iosys_fexec*, void*);