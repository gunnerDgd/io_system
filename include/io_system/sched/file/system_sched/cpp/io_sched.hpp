#pragma once
extern "C"
{
#include <io_system/sched/file/system_sched/system_sched_type.h>
#include <io_system/sched/file/system_sched/system_sched_init.h>
#include <io_system/sched/file/system_sched/system_sched_request.h>
}

#include <chrono>
#include <io_system/sched/file/system_sched/cpp/io_request.hpp>
#include <io_system/sched/file/system_sched/cpp/io_session.hpp>

namespace io_system::schedule::system_scheduler {
	class scheduler
	{
		friend class io_session;
	public:
		using native_handle_type
			= synapse_iosys_sched_system;
		using count_type
			= std::uint32_t;

	public:
		scheduler (count_type); 
		scheduler ();
		~scheduler();
		
	public:
		io_request
			retrive_completed();
		template <typename InClock, typename InDuration>
		static io_request
			retrieve_completed_until
				(std::chrono::time_point<InClock, InDuration>&);
		
	private:
		native_handle_type
			__M_iosys_sched_hnd;
	};
}

template <typename InClock, typename InDuration>
io_system::schedule::system_scheduler::io_request
	io_system::schedule::system_scheduler::scheduler::retrieve_completed_until
		(std::chrono::time_point<InClock, InDuration>& pWaitTime)
{
	return io_request(
		synapse_iosys_sched_system_retrieve_completed_until(
			__M_iosys_sched_hnd,
			std::chrono::duration_cast<std::chrono::milliseconds>(pWaitTime).count()
		)
	);
}