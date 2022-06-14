#pragma once
#include <stdint.h>
#include <io_system/file/details/native/iosys_file_native_type.h>

size_t
__synapse_iosys_file_native_read_from(__synapse_iosys_file_native*, uint8_t*, size_t, size_t);

size_t
__synapse_iosys_file_native_write_to (__synapse_iosys_file_native*, uint8_t*, size_t, size_t);