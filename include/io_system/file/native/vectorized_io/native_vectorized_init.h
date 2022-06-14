#pragma once
#include <io_system/file/file_io_system.h>

synapse_io_system_file_vector*
synapse_io_system_file_vector_initialize(size_t);

void
synapse_io_system_file_vector_cleanup   (synapse_io_system_file_vector*);