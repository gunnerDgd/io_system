#include <io_system/file/native/native.h>
#include <io_system/file/details/native/iosys_file_native.h>

#include <io_system/debug/message/default.h>

#include <Windows.h>

size_t
__synapse_iosys_file_native_read_from(__synapse_iosys_file_native* pNative, uint8_t* pReadBuffer, size_t pReadSize)
{
	DWORD sz_rdfrom = 0;
	BOOL  sz_rdres  = ReadFile(pNative->hnd_file, pReadBuffer, pReadSize, &sz_rdfrom, 0);

	return (sz_rdres) ? sz_rdfrom : 0;
}

size_t
__synapse_iosys_file_native_write_to(__synapse_iosys_file_native* pNative, uint8_t* pWriteBuffer, size_t pWriteSize)
{
	DWORD sz_wrto  = 0;
	BOOL  sz_wrres = WriteFile(pNative->hnd_file, pWriteBuffer, pWriteSize, &sz_wrto, 0);

	return (sz_wrres) ? sz_wrto : 0;
}