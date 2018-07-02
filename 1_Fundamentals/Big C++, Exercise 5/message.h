#ifndef MESSAGE_H
#define MESSAGE_H

#include <string>
#include <ctime>
#include <iostream>

class Message
{
public:
	/**
		Constructs the message time with the current time 
	*/
	Message();

	/**
		Constructs the message time with the current time, and the message's sender 
		and the message's recipient
		@param in_sender is the sender of the message
		@param in_recipent is the recipient of the message
	*/
	Message(std::string in_sender, std::string in_recipient);

	/**
		Constructs the message time with a given time, and the message's sender
		and the message's recipient
		@param in_sender is the sender of the message
		@param in_recipent is the recipient of the message
		@param t The Time of the message
	*/
	Message(std::string in_sender, std::string in_recipient, std::string time);
	/**
		Appends a line of text to the message body
		@param message_line is the line of the message to be added
	*/
	void append(std::string message_line);

	/**
		Makes the message into one long string like this:
		"From: Harry Hacker\nTo: Rudolf Reindeer\n ..."
		@return the complete message with the sender information and the recipient and
		the time the message was constructed
	*/
	std::string to_string() const;

	/**
		Prints the whole message to a user of GUI.
	*/
	void print_message() const;


private:
	std::string sender, recipient, message_text;
	std::string time_stamp;
};

#endif
