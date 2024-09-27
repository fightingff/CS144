#include "byte_stream.hh"

using namespace std;

ByteStream::ByteStream( uint64_t capacity ) : 
  capacity_( capacity ), error_(false), bytes_pushed_(0), bytes_popped_(0), end_(false), buffer_("") {}

bool Writer::is_closed() const
{
  // Your code here.
  return end_;
}

void Writer::push( string data )
{
  // Your code here.
  uint64_t available_capacity_ = min(available_capacity(), data.size());
  buffer_ += data.substr(0, available_capacity_);
  bytes_pushed_ += available_capacity_;
  if (data.size() > available_capacity_) {
    set_error();
  }
  return;
}

void Writer::close()
{
  // Your code here.
  end_ = true;
}

uint64_t Writer::available_capacity() const
{
  // Your code here.
  return capacity_ - buffer_.size();
}

uint64_t Writer::bytes_pushed() const
{
  // Your code here.
  return bytes_pushed_;
}

bool Reader::is_finished() const
{
  // Your code here.
  return end_ && !bytes_buffered();
}

uint64_t Reader::bytes_popped() const
{
  // Your code here.
  return bytes_popped_;
}

string_view Reader::peek() const
{
  // Your code here.
  return std::string_view(buffer_);
}

void Reader::pop( uint64_t len )
{
  // Your code here.
  len = min(len, buffer_.size());
  buffer_.erase(0, len);
  bytes_popped_ += len;
}

uint64_t Reader::bytes_buffered() const
{
  // Your code here.
  return buffer_.size();
}
