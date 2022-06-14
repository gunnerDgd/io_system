#pragma once
#include <io_system/file/native/native.h>

synapse_io_system_file*
synapse_iosys_file_native_initialize_open_existing(const char*);

synapse_io_system_file*
synapse_iosys_file_native_initialize_create_new   (const char*);

void
synapse_iosys_file_native_cleanup				  (synapse_io_system_file*);