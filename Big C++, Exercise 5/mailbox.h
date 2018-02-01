#ifndef MAILBOX_H
#define MAILBOX_H

#include "message.h"

class Mailbox
{
public:
	/**
		Constructs Mailbox with number of messages equals to the actually
		number of it currently
	*/
	Mailbox();
	
	/**
		Adds new message to the end of the Mailbox string
		@param m is the message to be added
	*/
	void add_message(Message m);
	
	/**
		Gets a message from the Mailbox, which its order is the integer i
		@param i is the order of the message in the mailbox, i.e. first message
		or second or .... etc.
		@return the message which order is i
	*/
	Message get_message(int i) const;
	
	/**
		Removes a message from the mailbox which its order is the intger i
		@param i is the order of the message in the mailbox, i.e. first message
		or second or .... etc.
	*/
	//void remove_message(int i);

private:
	std::string mailbox_string;
	int number_messages;
};



#endif