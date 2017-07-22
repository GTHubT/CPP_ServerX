#include "GT_IOBuffer.h"

namespace GT {

	namespace NET {

		GT_IOBuffer::GT_IOBuffer(size_t len) {
			Internal = InternalHigh = 0;
			Offset = OffsetHigh = 0;
			hEvent = NULL;
			io_buffer_size_ = len;
			io_wsa_buf_.buf = io_buffer_;
			io_wsa_buf_.len = io_buffer_size_;
		}

		GT_IOBuffer::~GT_IOBuffer() {
			delete[] io_buffer_;
		}

		bool GT_IOBuffer::AllocateIOBuffer() {
			io_buffer_ = new char[io_buffer_size_];
			return io_buffer_ == nullptr ? false : true;
		}

		void GT_IOBuffer::SetIOBufferSocket(SOCKET s) {
			io_socket_ = s;
		}

		void GT_IOBuffer::ResetBuffer() {
			memset(io_buffer_, 0, io_buffer_size_);
		}
	}
}