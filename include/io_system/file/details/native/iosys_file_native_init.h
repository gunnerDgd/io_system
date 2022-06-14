#pragma once
#include <io_system/file/details/native/iosys_file_native_type.h>

__synapse_iosys_file_native*
__synapse_iosys_file_native_initialize_open_existing(const wchar_t*);

__synapse_iosys_file_native*
__synapse_iosys_file_native_initialize_create_new   (const wchar_t*);

void
__synapse_iosys_file_native_cleanup					(__synapse_iosys_file_native*);