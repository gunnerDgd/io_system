#pragma once
#include <io_system/file/details/native/iosys_file_native_type.h>

__synapse_iosys_file_native*
__synapse_iosys_file_native_initialize_open_existing(const char*);

__synapse_iosys_file_native*
__synapse_iosys_file_native_initialize_create_new   (const char*);

void
__synapse_iosys_file_native_cleanup					(__synapse_iosys_file_native*);

size_t
__synapse_iosys_file_native_read_from				(__synapse_iosys_file_native*, uint8_t*, size_t);

size_t
__synapse_iosys_file_native_write_to				(__synapse_iosys_file_native*, uint8_t*, size_t);

size_t
__synapse_iosys_file_native_pointer_current		    (__synapse_iosys_file_native*);

size_t
__synapse_iosys_file_native_pointer_set			    (__synapse_iosys_file_native*, size_t);