#include <io_system/file/native/native.h>
#include <io_system/file/details/native/iosys_file_native_manip.h>

size_t
synapse_iosys_file_native_pointer_current
	(synapse_io_system_file_handle pEntity)
{
	return 
		__synapse_iosys_file_native_pointer_current
			(synapse_io_system_opaque_reference(pEntity));
}

size_t
synapse_iosys_file_native_pointer_set
	(synapse_io_system_file_handle pEntity, size_t pNewPointer)
{
	return 
		__synapse_iosys_file_native_pointer_set
			(synapse_io_system_opaque_reference(pEntity), pNewPointer);
}