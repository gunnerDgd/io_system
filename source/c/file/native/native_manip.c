#include <io_system/file/native/native.h>
#include <io_system/file/details/native/iosys_file_native_manip.h>

#include <stdlib.h>

size_t
synapse_iosys_file_native_pointer_current(synapse_io_system_file_handle pEntity)
{
	return __synapse_iosys_file_native_pointer_current(pEntity.opaque);
}

size_t
synapse_iosys_file_native_pointer_set(synapse_io_system_file_handle pEntity, size_t pNewPointer)
{
	return __synapse_iosys_file_native_pointer_set(pEntity.opaque, pNewPointer);
}

void
synapse_iosys_file_native_wait_until(synapse_io_system_file_handle pHandle)
{
	__synapse_iosys_file_native_wait_until(pHandle.opaque);
}