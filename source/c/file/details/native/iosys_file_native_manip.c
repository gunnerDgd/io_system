#include <io_system/file/native/native.h>
#include <io_system/file/details/native/iosys_file_native.h>

#include <io_system/debug/message/default.h>

#include <Windows.h>

size_t
__synapse_iosys_file_native_pointer_current(__synapse_iosys_file_native* pNative)
{
	LARGE_INTEGER								   ptr_size = { .QuadPart = 0 };
	SetFilePointerEx(pNative->hnd_file, ptr_size, &ptr_size, FILE_CURRENT);

	return ptr_size.QuadPart;
}

size_t
__synapse_iosys_file_native_pointer_set(__synapse_iosys_file_native* pNative, size_t pNewPointer)
{
	LARGE_INTEGER								   ptr_size = { .QuadPart = pNewPointer };
	SetFilePointerEx(pNative->hnd_file, ptr_size, &ptr_size, FILE_BEGIN);

	return ptr_size.QuadPart;
}

void
__synapse_iosys_file_native_wait_until(__synapse_iosys_file_native* pNative)
{
	WaitForSingleObject(pNative->hnd_aio.hEvent, INFINITE);
}