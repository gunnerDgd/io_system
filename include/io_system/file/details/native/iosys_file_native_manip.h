#pragma once
#include <io_system/file/details/native/iosys_file_native_type.h>

size_t
__synapse_iosys_file_native_pointer_current(__synapse_iosys_file_native*);

size_t
__synapse_iosys_file_native_pointer_set	   (__synapse_iosys_file_native*, size_t);

void
__synapse_iosys_file_native_wait_until	   (__synapse_iosys_file_native*);