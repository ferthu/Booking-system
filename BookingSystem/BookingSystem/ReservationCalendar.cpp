/* Created by: Mattias Fredriksson
*/
#include "ReservationCalendar.h"


namespace lic {

	ReservationCalendar::ReservationCalendar(const Date d)
	:	_timeslots(DAYPERMONTH[d._month]), _reservations(d._month)
	{
		for (int i = 0; i < DAYPERMONTH[d._month]; i++) {
			_timeslots[i].resize(SLOTPERDAY);
		}
	}


	ReservationCalendar::~ReservationCalendar()
	{
	}
	/* Access calendar date
	*/
	Date ReservationCalendar::getDate() {
		return _date;
	}

	/* Calculates a index for the reservation arrays from a specified date.
	*/
	int ReservationCalendar::dateToIndex(const Date& d) {

		//Find month count between current and the specified date:
		int monthsBetween = d._month - _date._month;
		//Find the number of days on each month between the two dates (including current):
		int monthDayDisparity = 0;
		if(monthsBetween > 0)
			//Adds all months forward to the specified date
			for (int i = 0; i < monthsBetween; i++)
				monthDayDisparity += DAYPERMONTH[_date._month + i];
		else
			//Subtracts all months backward to the specified date
			for (int i = 0; i > monthsBetween; --i)
				monthDayDisparity -= DAYPERMONTH[_date._month + i];

		return //Calculate number of days between the years:
			(d._year - _date._year) * DAYPERYEAR +
			//Calculates number of days between the dates:
			monthDayDisparity + d._day - _date._day; 
	}
	/* Converts time to a slot index
	*/
	int ReservationCalendar::timeToSlotIndex(const Time t) {
		return t._hour * SLOTSPERHOUR + t._minute / MINPERSLOT;
	}
	/* Converts a slot index to time
	*/
	Time ReservationCalendar::slotIndexToTime(int i) {
		return Time(i / SLOTSPERHOUR, (i % SLOTSPERHOUR) * MINPERSLOT);
	}

	bool ReservationCalendar::slotAvailable(const std::string& serviceName, int maxReservationCount, int dateIndex, int slotIndex, int playerCount) {

			int reservedCount = 0;
			const std::vector<int>& slotlist = _timeslots[dateIndex][slotIndex];
			for (unsigned int resIndex = 0; resIndex < slotlist.size(); resIndex++) {
				Reservation& res = _reservations[dateIndex][slotlist[resIndex]];
				for (unsigned int i = 0; i < res._services.size(); i++) {	
					if (res._services[i] == serviceName)
						reservedCount++;
				}
			}
			//If there are more reservations then available services the booking cannot be made.
			return reservedCount + playerCount > maxReservationCount;
	}
	/* Sort availability for a specified service from a available time slots.
	Given a reservation date and number of players.
	*/
	void ReservationCalendar::sortAvailable(const std::string& serviceName, int playerCount, int dateIndex, std::vector<Time>& available) {
		//Number of services available:
		int serviceCount = SERVICECOUNT;

		for (unsigned int i = 0; i < available.size(); i++) {
			//Calculate available slot
			int slotIndex = timeToSlotIndex(available[i]);
			if (slotAvailable(serviceName, serviceCount, dateIndex, slotIndex, playerCount)) {
				//Remove the available time and decrement the loop to accomodate the removed value.
				available.erase(available.begin() + slotIndex);
				slotIndex--;
			}
		}

	}

	/* Fetches a set of available time slots from a reservation setting and a date
	*/
	std::shared_ptr<std::vector<Time>> ReservationCalendar::freeReservations(const Reservation& res, const Date date) {
		//Populate an array of available times:
		std::shared_ptr<std::vector<Time>> free(new std::vector<Time>(SLOTPERDAY));
		for (int i = 0; i < SLOTPERDAY; i++)
			(*free)[i] = slotIndexToTime(i);
		int dateIndex = dateToIndex(res._date);
		//For each service booked sort away un-availabel time slots:
		for (unsigned int i = 0; i < res._services.size(); i++)
			sortAvailable(res._services[i], res._players, dateIndex, *free);
		return free;
	}
	/* Reserve the time slot specified for the date, the reservations date/time parameters will be updated.
	*/
	bool ReservationCalendar::reserve(Reservation& res, const Date date, const Time time) {
		//Convert the time variables to indices in the data arrays:
		int dateIndex = dateToIndex(date);
		int beginSlotIndex = timeToSlotIndex(time);
		int endSlotIndex = timeToSlotIndex(time); //Reservation can only represent a single slot for now...
		if (endSlotIndex < beginSlotIndex)
			return false; //Error, reservation cannot end before it begins...

		//Validate reservation still valid:
		for (unsigned int i = 0; i < res._services.size(); i++) {
			//Loop over every slot the reservation wants to reserve and validate availability:
			for (int slotIndex = beginSlotIndex; slotIndex <= endSlotIndex; slotIndex++) {
				if (!slotAvailable(res._services[i], SERVICECOUNT, dateIndex, slotIndex, res._players))
					return false;
			}
		}

		int reservationIndex = (int)_reservations.size();
		//Set reservation date/time
		res._date = date;
		res._time = time;
		_reservations[dateIndex].push_back(res);

		//Reserve the slots linked with reservation:
		for (int slotIndex = beginSlotIndex; slotIndex <= endSlotIndex; slotIndex++) 
			_timeslots[dateIndex][slotIndex].push_back(reservationIndex);
		//Reservation successfull
		return true;
	}

	/* Finds a reference for a reservation in the calendar equal to the specified reservation data.
	*/
	int ReservationCalendar::findReservation(const Reservation& res, Reservation* ref){
		//Convert the time variables to indices in the data arrays:
		int dateIndex = dateToIndex(res._date);
		int slotIndex = timeToSlotIndex(res._time);
		//Loop over the time slots and compare the reservations linked from them:
		for (unsigned int i = 0; i < _timeslots[dateIndex][slotIndex].size(); i++) {
			int resIndex = _timeslots[dateIndex][slotIndex][i];
			Reservation& reserved = _reservations[dateIndex][resIndex];
			//Check if equal
			if (res == reserved) {
				//The reservation is found!
				ref = &reserved;
				return resIndex;
			}
		}
		return -1;
	}
	/*	Finalizes the reservation. Confirming the reservation date & time reserved.
	The reservation will be bound to the specified account.
	*/
	void ReservationCalendar::finalize(const Reservation& res, const std::string& accountName) {
		Reservation* ref = nullptr;
		if (findReservation(res, ref) != -1) {
			ref->_accountName = accountName;
		}
	}
	/* Deletes a reserved reservation in the calendar.
	*/
	void ReservationCalendar::editReservation(const Reservation& res) {
		//Convert the time variables to indices in the data arrays:
		int dateIndex = dateToIndex(res._date);
		int beginSlotIndex = timeToSlotIndex(res._time);
		int endSlotIndex = timeToSlotIndex(res._time);
		if (dateIndex < 0)
			return; //Date has passed!

		//Fetch the reservation list
		std::vector<Reservation>& resList = _reservations[dateIndex];

		//Find the reservation index:
		Reservation* ref = nullptr;
		int resIndex = findReservation(res, ref);
		if (resIndex == -1)
			return; //Reservation was not found
		//Loop over every time slot for the date and check if the linked reservation matches:
		for (int slotIndex = beginSlotIndex; slotIndex <= endSlotIndex; slotIndex++) {
			//Fetch slot list for the actual date and slot:
			std::vector<int>& slotList = _timeslots[dateIndex][slotIndex];
			//Loop over every reservation link of the slot list
			for (unsigned int i = 0; i < slotList.size(); i++) {
				//Check if it's the matching reservation index:
				if (slotList[i] == resIndex) {
					//Erase slots related to the reservation:
					slotList.erase(slotList.begin() + i);
					break; //Each slot only has one reservation link!
				}
			}
		}
		//Erase the reservation, first swap it with the last Reservation element
		int lastIndex = (int)_reservations.size() - 1;
		std::swap(resList[resIndex], resList[lastIndex]);
		//Erase Reservation obj, it's now the last element in the vector:
		_reservations[dateIndex].erase(resList.begin() + lastIndex);

		//Find the begin and end slot index of the swapped reservation:
		beginSlotIndex = timeToSlotIndex(resList[resIndex]._time);
		endSlotIndex = timeToSlotIndex(resList[resIndex]._time);
		//Update the swapped reservations time slots with the new reservation index: 
		for (int slotIndex = 0; slotIndex <= endSlotIndex; slotIndex++) {
			//Fetch slot list for the date and slot:
			std::vector<int>& slotList = _timeslots[dateIndex][slotIndex];
			//Loop over every reservation link to find the old index:
			for (unsigned int i = 0; i < slotList.size(); i++) {
				if (slotList[i] == lastIndex) //Match with the old
					slotList[i] = resIndex; //Update the index to the index of the swapped slot
			}
		}

	}
	/* Fetches the reservations reserved by the specified account.
	*/
	std::shared_ptr<std::vector<Reservation>> ReservationCalendar::getReservations(const std::string& accountName) {
		//Loop over all reservations and check if the account is linked with the reservation:
		std::shared_ptr<std::vector<Reservation>> reservations(new std::vector<Reservation>());
		for (unsigned int date = 0; date < _reservations.size(); date++) {
			for (unsigned int i = 0; i < _reservations.size(); i++) {
				if (_reservations[date][i]._accountName == accountName)
					reservations->push_back(_reservations[date][i]);
			}
		}
		return reservations;
	}

}