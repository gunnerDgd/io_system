#pragma once
#include <io_system/interface/base.h>

synapse_iosys_base*
synapse_iosys_file_native_initialize_open_existing(const char*);

synapse_iosys_base*
synapse_iosys_file_native_initialize_create_new(const char*);

void
synapse_iosys_file_native_cleanup(synapse_iosys_base*);