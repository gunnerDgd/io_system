#pragma once
extern "C"
{
#include <io_system/sched/file/system_sched/system_sched_type.h>
#include <io_system/sched/file/system_sched/system_sched_request.h>
}

#include <io_system/sched/file/system_sched/cpp/system_sched_declare.hpp>

#include <type_traits>
#include <chrono>

namespace io_system::schedule::system_scheduler {
	class io_request
	{
		friend class scheduler;
	public:
		using native_handle_type
			= synapse_iosys_sched_system_io_request;
		
		using pointer   = void*;
		using size_type = std::size_t;

	private:
		io_request(native_handle_type);
		
	public:
		io_request (pointer, size_type, size_type);

		io_request (io_request&) ;
		io_request (io_request&&);
		~io_request();

	public:
		template <typename IoReq, typename InClock, typename InDuration>
		static bool 
			wait_until(IoReq&&, std::chrono::time_point<InClock, InDuration>&);
		template <typename IoReq>
		static bool 
			wait	  (IoReq&&);

	private:
		native_handle_type
			__M_iosys_req_handle;
	};
}

template <typename IoReq, typename InClock, typename InDuration>
bool 
	io_system::schedule::system_scheduler::io_request::wait_until(IoReq&& pIoReq, std::chrono::time_point<InClock, InDuration>& pClock)
{
	return synapse_iosys_sched_system_wait_until (
		pIoReq.__M_iosys_req_handle,
		std::chrono::duration_cast<std::chrono::milliseconds>(pClock).count()
	);
}

template <typename IoReq>
bool 
	io_system::schedule::system_scheduler::io_request::wait(IoReq&& pIoReq)
{
	return
		synapse_iosys_sched_system_wait(pIoReq.__M_iosys_req_handle);
}