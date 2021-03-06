//数据处理  在消息前加入四个字节的消息头来标识消息长度
//来源于asio 官方示例 src\examples\cpp11\chat\chat_message.hpp
#ifndef _SocketMessage_H__
#define _SocketMessage_H__

#include <cstdio>
#include <cstdlib>
#include <cstring>

class socket_message
{
public:
	enum{header_length = 4};
	enum{max_body_length = 8192};
	socket_message()
		: body_length_(0)
	{
	}
	const char* data() const                                    //获取全部消息
	{
		return data_;
	}
	char* data()                                                //获取可改变的消息
	{
		return data_;
	}
	size_t length() const                                       //获取消息长度
	{
		return header_length + body_length_;
	}
	const char* body() const                                    //获取消息内容
	{
		return data_ + header_length;
	}
	char* body()                                                //获取可改变的消息内容
	{
		return data_ + header_length;
	}
	size_t body_length() const                                  //获取内容长度
	{
		return body_length_;
	}
	void body_length(size_t new_length)                         //设置内容长度
	{
		body_length_ = new_length;
		if (body_length_ > max_body_length)
			body_length_ = max_body_length;
	}
	bool decode_header()                                        //解码头
	{
		using namespace std; // For strncat and atoi.
		char header[header_length + 1] = "";
		strncat(header, data_, header_length);
		body_length_ = atoi(header);
		if (body_length_ > max_body_length)
		{
			body_length_ = 0;
			return false;
		}
		return true;
	}
	void encode_header()                                         //编码头（将内容长度写在消息头）
	{
		using namespace std; // For sprintf and memcpy.
		char header[header_length + 1] = "";
		sprintf(header, "%4d", static_cast<int>(body_length_));
		memcpy(data_, header, header_length);
	}
private:
	char data_[header_length + max_body_length];
	size_t body_length_;
};

#endif // !_SocketMessage_H__
