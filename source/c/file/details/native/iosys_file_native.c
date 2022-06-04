#include <io_system/file/native/native.h>
#include <io_system/file/details/native/iosys_file_native.h>

#include <io_system/debug/message/default.h>

#include <Windows.h>

__synapse_iosys_file_native*
__synapse_iosys_file_native_initialize_open_existing(const char* pName)
{
	__synapse_iosys_file_native* ptr_iosys			 = malloc(sizeof(__synapse_iosys_file_native));
								 ptr_iosys->hnd_file = CreateFileA(pName, GENERIC_ALL, 0, 0, OPEN_EXISTING, 0, 0);
								 ptr_iosys->ptr_file = 0;

	synapse_iosys_debug_message_value("__synapse_iosys_file_native", __FUNCTION__, "ptr_iosys->hnd_file", ptr_iosys->hnd_file);
	synapse_iosys_debug_message_value("__synapse_iosys_file_native", __FUNCTION__, "ptr_iosys->ptr_file", ptr_iosys->ptr_file);

	return ptr_iosys;
}

__synapse_iosys_file_native*
__synapse_iosys_file_native_initialize_create_new(const char* pName)
{
	__synapse_iosys_file_native* ptr_iosys			 = malloc(sizeof(__synapse_iosys_file_native));
								 ptr_iosys->hnd_file = CreateFileA(pName, GENERIC_ALL, 0, 0, CREATE_NEW, 0, 0);
								 ptr_iosys->ptr_file = 0;

	synapse_iosys_debug_message_value("__synapse_iosys_file_native", __FUNCTION__, "ptr_iosys->hnd_file", ptr_iosys->hnd_file);
	synapse_iosys_debug_message_value("__synapse_iosys_file_native", __FUNCTION__, "ptr_iosys->ptr_file", ptr_iosys->ptr_file);

	return ptr_iosys;
}


void
__synapse_iosys_file_native_cleanup(__synapse_iosys_file_native* pNative)
{
	CloseHandle(pNative->hnd_file);
	free	   (pNative);
}

size_t
__synapse_iosys_file_native_read_from(__synapse_iosys_file_native* pNative, uint8_t* pReadBuffer, size_t pReadSize)
{
	DWORD sz_rdfrom = 0;
	BOOL  sz_rdres  = ReadFile(pNative->hnd_file, pReadBuffer, pReadSize, &sz_rdfrom, 0);

	synapse_iosys_debug_message_value("__synapse_iosys_file_native", __FUNCTION__, "[READ_BYTES]"	, sz_rdfrom);
	synapse_iosys_debug_message_value("__synapse_iosys_file_native", __FUNCTION__, "[ERROR_MESSAGE]", GetLastError());

	return (sz_rdres) ? sz_rdfrom : 0;
}

size_t
__synapse_iosys_file_native_write_to(__synapse_iosys_file_native* pNative, uint8_t* pWriteBuffer, size_t pWriteSize)
{
	DWORD sz_wrto  = 0;
	BOOL  sz_wrres = WriteFile(pNative->hnd_file, pWriteBuffer, pWriteSize, &sz_wrto, 0);

	synapse_iosys_debug_message_value("__synapse_iosys_file_native", __FUNCTION__, "[WRITTEN_BYTES]", sz_wrto);
	synapse_iosys_debug_message_value("__synapse_iosys_file_native", __FUNCTION__, "[ERROR_MESSAGE]", GetLastError());

	return (sz_wrres) ? sz_wrto : 0;
}

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