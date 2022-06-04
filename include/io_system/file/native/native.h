#pragma once
#include <io_system/interface/base.h>
#include <io_system/file/native/native_option.h>

synapse_iosys_base*
synapse_iosys_file_native_initialize_open_existing(const char*);

synapse_iosys_base*
synapse_iosys_file_native_initialize_create_new  (const char*);

void
synapse_iosys_file_native_cleanup		   (synapse_iosys_base*);

size_t
synapse_iosys_file_native_read_from(void*, void*, size_t);

size_t
synapse_iosys_file_native_write_to (void*, void*, size_t);

size_t
synapse_iosys_file_native_pointer_current(void*);

size_t
synapse_iosys_file_native_pointer_set	 (void*, size_t);