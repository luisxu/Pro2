/**
 * @file Agenda.hpp
 * @brief Agenda specification
 */

#ifndef AGENDA_HPP
#define AGENDA_HPP

#include "Appointment.hpp"
#include <vector>
#include <list> 

/**
 * An Agenda represents a collections of appointments, as well as appointments "alive" and appointments done.
*/

typedef vector< pair<int, int> > hours;   // H
typedef vector<hours> Offis;   // N
typedef vector<Offis> Notebook;  // D

typedef list<Appointment>::iterator Iterator;

class Agenda {
	
private:
	
	/**
	  * Represents a collection of requests done sorted by increasing.
	 */
	list<Appointment> reqs_done;
	
	/**
	  * A Three-dimensional Matrix for future appointments
	  * The first references array dimension 1, which represents a vector of hours, and each hour is a pair of integers:
	  * - The first integer could be -1, 0 or more than 0
	  *      - Integer -1 represents the Official is not avaliable in this hour
	  *      - Integer 0 represents the Official is avaliable in this hour
	  *      - Integer more than 0 represents has have some appointment, and this integer consists the Appointment identifier
	  *
	  * - The segon interger could be -1 or is different than -1
	  *      - If integer is -1, represents this Appointment has been scheduled from model 1.
	  *      - Else this Appointment has been scheduled from model 2, furthermore this integer consists the level maximum
	  *
	  * The second references dimension 2, which represents a vector of Officials identifiers.
	  *
	  * The third references dimension 3, which represents a vector of days.
	 */
	Notebook notebook;

    
public:
	
	/**
	 * Creates a new Agenda using H, N, and D.
	 * 
	 * \pre 
	 *       - 1 <= H
	 *       - 1 <= N
	 *       - 1 <= D
	 * \post Returns a new Agenda.
	 */
	Agenda(int H, int N, int D);
	
	/**
	 * Default destructor.
	 */
	~Agenda();

	/**
	* Returns the model with **app_day**, **id_offi**, and **app_hour**.
	*
	* \pre
	*       - 2 <= "the register day" <= **app_day** <= "the register day"+D
	*       - 1 <= **id_offi** <= Offis.size();
	*       - 1 <= *app_hour* <= hours.size();
	*
	* \post The model with **app_day**, **id_offi**, and **app_hour** is returned.
	*/
	int consult_model(int app_day, int id_offi, int app_hour) const;

	/**
	  * Returns the first value of object pair with **app_day**, **id_offi**, and **app_hour**.
	  *
	  * \pre
	  *      - 2 <= "the register day" <= **app_day** <= "the register day"+D
	  *      - 1 <= **id_offi** <= Offis.size();
	  *      - 1 <= **app_hour** <= hours.size();
	  *
	  * \post An interge with **app_day**, **id_offi**, and **app_hour** is returned.
	  */
	int consult_first_value(int app_day, int id_offi, int app_hour) const;

	/**
	  * Returns the level with **app_day**, **id_offi**, and **app_hour**.
	  *
	  * \pre
	  *      - 2 <= "the register day" <= **app_day** <= "the register day"+D
	  *      - 1 <= **id_offi** <= Offis.size();
	  *      - 1 <= *app_hour* <= hours.size();
	  *
	  * \post The level of Appointment with **app_day**, **id_offi**, and **app_hour** is returned.
	  */
	int consult_second_value(int app_day, int id_offi, int app_hour) const;
    
	/**
	  * Modifies the first value of pair object using the parameters **first_value**, **can_day**, **id_offi**, and **can_hour**
	  * \pre 
	  *       - 2 <= "the register day" <= **app_day** <= "the register day"+D
	  *       - 1 <= **id_offi**
	  *       - -1 <= **first_value** 
	  *       - 1 <= *can_hour**
	  * \post The first value of pair object with the implicit parameter of this, it has been substitued 
	  *         for **first_value** 
	  */
	void modify_first_value(int first_value, int can_day, int id_offi, int can_hour);

	/**
	  * Modifies the second value of pair object using the parameters **first_value**, **can_day**, **id_offi**, and **can_hour**
	  * \pre 
	  *       - 2 <= "the register day" <= **app_day** <= "the register day"+D
	  *       - 1 <= **id_offi**
	  *       - -1 <= **second_value** 
	  *       - 1 <= *can_hour**
	  * \post The second value of pair object with the implicit parameter of this, it has been 
	  *         substituted for **second_value**. 
	*/
	void modify_second_value(int second_value, int can_day, int id_offi, int can_hour);

	/**
	* Inserts the appointments done to the list **reqs_done**, keeping in mind that the appointments day of list must not pass K days.
	*
	* \pre
	*      - 1 <= **limit_day**, **limit_day** == **pre_reg_day** - **K**
	*      - **pre_reg_day** < **reg_day**
	*      - 1 <= **K**
	*
	* \post The appointments done has been inserted to the list, and the appointments has been erased if the appointment day
	*          is less than **limit_day**.
	*/
	void advance_days(int limit_day, int pre_reg_day, int reg_day, int K);
	
	/**
	  * Sets the Official with **id_offi** is not avaliable in the **app_hour** of **app_day**.
	  * 
	  * \pre
	  *      - 2 <= "the register day" <= **app_day** <= "the register day"+D
	  *      - 1 <= **id_offi** <= Offis.size();
	  *      - 1 <= *app_hour** <= hours.size();
	  *
	  * \post The Official with the identifier **id_offi** has been unavailable int this moment, and any Appointment couldn't be scheduled
	  *         for this Official.
	*/
	void set_non_working(int app_day, int id_offi, int app_hour);
	
	/**
	  * Adds an Appointment to the Agenda using **app_day**, **id_offi**, **app_hour**, **id_app**, and **second_value**.
	  * The second value could be -1 or more than -1 depends on the model itself, which -1 represents the model 1, othewise represents 
	  * the level maximum of request.  
	  *
	  * \pre
	  *      - 2 <= "the register day" <= **app_day** <= "the register day"+D
	  *      - 1 <= **id_offi** <= Offis.size();
	  *      - 1 <= *app_hour** <= hours.size();
	  *      - 1 <= **id_app**
	  *      - -1 <= **second_value**
	  *
	  * \post The Appointment has been scheduled in the Agenda.
	  */
	void add_apps_alive(int app_day, int id_offi, int app_hour, int& id_app, int second_value);
	
	/**
	  * Consults the appointments done between the **d1** day and **d2** day.
	  *
	  * \pre 1 <= **d1** <= K, **d2** = "the register day" -1 
	  *
	  * \post Information about the requests is printed in the output stream:
	  *          - app_day
	  *          - id_offi
	  *          - app_hour
	  *          - id_app 
	  */
	void consult_app_done(int d1, int d2);
	
	/**
	  * Consults the appointments alive between the **d1** day and **d2** day.
	  *
	  * \pre **d1** = "register day" + 1, **d2** = **d1** + D.
	  *
	  * \post  Information about the requests is printed in the output stream:
	  *           - app_day
	  *           - id_offi
	  *           - app_hour
	  *           - id_app 
	 */
	void consult_app_alive(int d1, int d2);
	
};

#endif
	
