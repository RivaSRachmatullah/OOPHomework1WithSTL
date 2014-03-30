/**
 * @file
 * @brief Implementation Event Class
 * 
 */
#include "Event.h"

int Event::ID = 0;

Event::Event() {
	T = new Teller();
}

Event::Event(int N) {
	T = new Teller(N);
}

Event::~Event() {
	delete T;
}

DateTime Event::GetDateTime() {
	return DT;
}

DateTime Event::GetDeadline() {
	return Deadline;
}

void Event::SetDeadline(DateTime Deadline) {
	this->Deadline = Deadline;
}

void Event::Close() {
	cout << "Loop terminate" << endl;
	T->DepartureAll();
}

