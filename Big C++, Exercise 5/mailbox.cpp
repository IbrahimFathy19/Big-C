#include "mailbox.h"

Mailbox::Mailbox()
{
	number_messages = 0;

	//We Can use this method, but there's a better methode
	for (int i = 0, n = mailbox_string.length(); i < n; i++)
	{
		if (mailbox_string[i] == '>')
			number_messages++;
	}
#if 0
	int pos;
	for (int i = 1; (pos = mailbox_string.find(">From:")) != std::string::npos; i++)
	{
		mailbox_string = mailbox_string.substr(++pos);
		number_messages++;
	}
#endif
}

void Mailbox::add_message(Message m)
{
	mailbox_string = mailbox_string + m.to_string();
}

Message Mailbox::get_message(int i) const
{
	int x = 0, n = mailbox_string.length(), begin = 0; 
	std::size_t found_at, end_at;
	std::string msg, sender, recipient, time, Message_body;
	for (int j = 0; j < n, j <= i; j++)
	{
		if (j < i)
			found_at = mailbox_string.find(">From", begin);//calculate the beginning
		//of the message

		if (j == i)
		{
			end_at = mailbox_string.find(">From", begin);//calculate the end
		//of the message
			if (end_at == 0)
				end_at = mailbox_string.length() - 1;
		}
		begin = begin + found_at;
	}
	msg = mailbox_string.substr(found_at, end_at - found_at);
	//std::cout << msg << "\n";
	int j, l, count_new_lines = 0;
	for (j = found_at; j < end_at; j++)
	{
		if (mailbox_string[j] == '\n')
			count_new_lines++;

		if (count_new_lines == 2)
			l = j;//start of message body
	}
	for (j = found_at; j < end_at; j++)
	{
		if (mailbox_string[j] == '\n')
		{
			sender = msg.substr(found_at + 7, j - 1- found_at);//+7 to remove '>From'
			break;
		}
	}
	x = j; count_new_lines = 0;
	for (j; j < end_at; j++)
	{
		if (mailbox_string[j] == '\n')
		{
			recipient = msg.substr(x + 5, j - (x + 5));
			count_new_lines++;
			if (count_new_lines == 2)
				break;
		}
	}
	x = j;
	for (j; j < end_at; j++)
	{
		if (mailbox_string[j] == '\n')
		{
			time = msg.substr(x + 5, j - (x + 5));
			count_new_lines++;
			if (count_new_lines == 2)
				break;
		}
	}
	x = j;

	Message_body = msg.substr(l + 2, end_at - found_at);
	//std::cout << "Message body=" << Message_body << "\n";

	Message m(sender, recipient, time);
	m.append(Message_body);
	return m;
}
