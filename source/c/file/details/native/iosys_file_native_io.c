#include <io_system/file/native/native.h>
#include <io_system/file/details/native/iosys_file_native.h>

#include <Windows.h>

size_t
__synapse_iosys_file_native_read_from(__synapse_iosys_file_native* pNative, uint8_t* pReadBuffer, size_t pReadSize, size_t pReadPointer)
{
	DWORD sz_rdfrom = 0;
	BOOL  sz_rdres	   ;

	pNative->hnd_aio.Offset	    = pReadPointer;
	pNative->hnd_aio.OffsetHigh = pReadPointer >> 32;

	sz_rdres
		= ReadFile(pNative->hnd_file, pReadBuffer, pReadSize, &sz_rdfrom, &pNative->hnd_aio);

	return sz_rdfrom;
}

size_t
__synapse_iosys_file_native_write_to(__synapse_iosys_file_native* pNative, uint8_t* pWriteBuffer, size_t pWriteSize, size_t pWritePointer)
{
	DWORD sz_wrto  = 0;
	BOOL  sz_wrres	  ;

	pNative->hnd_aio.Offset		= pWritePointer;
	pNative->hnd_aio.OffsetHigh = pWritePointer >> 32;

	sz_wrres
		= WriteFile(pNative->hnd_file, pWriteBuffer, pWriteSize, &sz_wrto, &pNative->hnd_aio);

	return sz_wrres;
}