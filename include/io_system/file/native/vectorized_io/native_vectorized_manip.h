#pragma once
#include <io_system/file/file_io_system.h>

void*
synapse_io_system_file_vector_push	  (synapse_io_system_file_vector_handle, size_t);

void
synapse_io_system_file_vector_pop	  (synapse_io_system_file_vector_handle);

void*
synapse_io_system_file_vector_retrieve(synapse_io_system_file_vector_handle, size_t);

size_t
synapse_io_system_file_vector_count   (synapse_io_system_file_vector_handle);