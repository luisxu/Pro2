/**
 * @file Appointment.hpp
 * @brief Appointment specification
 */

#ifndef APPOINTMENT_HPP
#define APPOINTMENT_HPP

#include "utils.PRO2"

/**
  * An Appointment represents an event that has its own identifier, the appointment day, 
  * the appointment hour, the corresponding official identifier and the model.
  */

class Appointment {

private:
	
	/**
	 * Represents the appointment identifier
	 */
	int id_app;
	
	/**
	  * Represents the appointment day
	  */
	int app_day;

	/**
	  * Represents the hour of apppointment day
      */
	int app_hour;
	  
	/**
	  * Represents the Official identifier
	  */
	int id_offi;
	
public:
	
	/**
	  * Creates a new empty Appointment with **app_day**, **id_offi**, **app_hour**, and **id_app**
	  * \pre
	  *      - 2 <= "the register day" <= **app_day** <= "the register day"+D
	  *      - 1 <= **id_offi** <= Offis.size();
	  *      - 1 <= *app_hour* <= hours.size();
	  *      - 1 <= **id_app**
	  *
	  * \post A new empty Appointment is returned.
	  */
	Appointment(int app_day, int id_offi, int app_hour, int id_app);
	
	/**
	 * Default destructor.
	 */
	~Appointment();
	
	/**
	  * Returns the day of Appointment
	  * \pre The Appointment has been scheduled.
	  * \post The day of this Appointment is returned.
	 */
	int consult_app_day() const;

	 /**
	  * Writes Appointment information in the output stream.
	  * \pre The Appointment has a appointment identifier, the appointment day, the appointment hour, 
	  * 	 and corresponding identifier official.
	  * \post The **app_day**, **id_offi**, **app_hour**, and **id_app** have been written in the output stream.
	  */
	 void write_app() const;
	 
};

#endif 
