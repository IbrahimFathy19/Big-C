#include "message.h"
#include "ccc_time.h"
Message::Message()
{
	Time now;
	time_stamp = std::to_string(now.get_hours()) +	" : " + 
		std::to_string(now.get_minutes());
}
Message::Message(std::string in_sender, std::string in_recipient)
{
	sender = in_sender;
	recipient = in_recipient;
	Time now;
	time_stamp = std::to_string(now.get_hours()) + " : " +
		std::to_string(now.get_minutes());
}
Message::Message(std::string in_sender, std::string in_recipient, std::string time)
{
	sender = in_sender;
	recipient = in_recipient;
	time_stamp = time;
}
void Message::append(std::string message_line)
{
	message_text = message_text + message_line;
}
std::string Message::to_string() const 
{
	std::string whole_message;
	char new_line = '\n';
	whole_message = ">From: " + sender + new_line + "To: " + recipient
		+ new_line + "At: " + time_stamp + new_line + message_text + new_line;
	return whole_message;
}
void Message::print_message() const
{
	std::cout << to_string();
}
