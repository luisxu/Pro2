/**
 * @file Organigram.hpp
 * @brief Organigram specification
 */
#ifndef ORGANIGRAM_HPP
#define ORGANIGRAM_HPP

#include "Agenda.hpp"
#include "Appointment.hpp"
#include "Arbre.hpp"

/**
 * An Organigram is a diagram that shows the structure of managment organization and the relationships between officials
 */

class Organigram
{
  
private:
	
	/**
	 * Represents the Appointment identifier 
	 */
	int id_app;
	
	/**
	 * Binary tree of officials relationships. Each nodes represents 
	 * the position in the organigram
	 */
	Arbre<int> nodes;
	
	/**
	 * Private function used to get the subtree of tree general, with id_offi
	 * as root of the subtree.
	 * \pre a = A
	 * \post The tree a consists the id_offi as root. 
	 */
	void cut_tree(Arbre<int>& a, int id_offi);
	
	/**
	  * Each Official of the list **path** passes the its own Appointment to another, except the last one of the list. 
	  *
	  * \pre The list path is not empty, 2 <= **can_day**, 1 <= **can_hour** <= H
	  * \post The officials with identifier of the list path has updated appointment themselves in this moment.
	 */
	void move_apps(Agenda& agenda, list<int>& path, int can_day, int can_hour);
	
	/**
	  * Given a list que contains the Officials identifiers, the cancellation day and the cancellation hour, and obtains
	  * a list without the Officials unavaliables.
	  * \pre
	  *      - 2 <= L.size()
	  *      - 2 <= "the register day" <= **can_day**
	  *      - 1 <= **can_hour** <= H
	  * \post The list L contains the Officials whose theirs appointments has been scheduled in **can_hour** of **can_day**.
	  */
	void remove_offis(Agenda& agenda, list<int>& L, int can_day, int can_hour);

	/**
	 * Assigns an Official who has less level and leftmost in the Organigram and 
	 * is free in this moment, otherwise, means that has not candidate and found es false. 
	 * \pre 
	 * 	- a = A
	 * 	- 2 <= **app_day** <= D + "register day" + 1 
	 * 	- 1 <= **app_hour** <= H 
	 * 	- 0 <= **depth**
	 * 		
	 * \post 
	 * 	- If found is true, returns the Official identifier
	 * 	- Otherwise, found is false and return -1. 
	 */
	int assign_candidate_less_level(Arbre<int>& a, Agenda& agenda, int app_hour, int app_day, bool& found, int &depth);
	
	/**
	 * Assigns an Official who has less level and leftmost in the Organigram and 
	 * is free in this moment, further, the candidate should have the level itself **level** at most.   
	 * Otherwise, found is false.  
	 * \pre 
	 * 	- a = A
	 * 	- 2 <= **app_day** <= D
	 * 	- 1 <= **app_hour** <= H
	 *	- **level_aux** = 0
	 *	- **level_aux** <= **level** 
	 *	- 0 <= **depth** 
	 * \post
	 * 	- If found is true, return the Official identifier. 
	 * 	- Otherwise, found is false and return -1.
	 */
	int assign_candidate_maximum_n_level(Arbre<int>& a, Agenda& agenda, int app_day, int app_hour, int& level_aux, int level, bool& found, int& depth);
	
	/**
	 * System searches an Official, who is free in this moment(**can_hour**, **can_day**), then creates a path where starts 
	 * from the root of the tree to this candidate identifier. 
	 *
	 * \pre 
	 * 	- a = A
	 * 	- 2 <= **can_day** <= D + "register day" + 1;
	 * 	- 1 <= **can_hour** <= H
	 * 	- 0 <= **depth**
	 * \post  If found is true, the list contains Offcials identifiers, otherwise found is false.  
	 */
	void make_path(Arbre<int>& a, Agenda& agenda, list<int>& L, int can_hour, int can_day, bool& found, int& depth);
	
	/**
	 * Private function that reads recursively a binary tree structure, using **mark** 
	 * as non-children indicator.
	 * \pre The input stream is prepared with a binary tree sequence in preorder.
	 * \post The final result of tree structure es a binary tree that represents the 
	 * 		data read from the input stream.
	 */
	void read_structure(Arbre<int>& a, int mark);

	
public:
	/** 
	 * Creates a new system of Organigram, default constructor
	 * \pre True
	 * \post Initiates **id_app** to zero. 
	 */
	Organigram();

	/**
	 * Default destructor
	 */
	~Organigram();

	/**
	  * Adds the new appointment into the Management Agenda, using the model 1(Day priority), based on
	  *     - The appointment day (favorite day)
	  *     - The appointment hour
	  *     - The day limit  
	  *
	  * If can't find the candidate, adds one to the **app_day**, successively until find one available day before 
	  * the **limit_day**.
	  * 
	  * \pre 
	  *      - 1 < **app_day** <= **limit_day**
	  *      - 1 <= **app_hour** <= H
	  * \post 
	  *      - If find the candidate, the Agenda has assigned the new request. 
	  *      - Otherwise, the Appointment will be refused, and has not produced any effect
	 */
	void new_app_req_day(Agenda& agenda, int app_day, int app_hour, int limit_day);
	
	/**
	  * Adds the new appointment into the Management Agenda, using the model 2(Level priority), based on
	  *       - The appointment day (favorite day)
	  *       - The appointment hour
	  *       - The level maximum 
	  *
	  * If can't find the candidate, adds one to **app_day** until to find one available day before 
	  * the **limit_day**.
	  * 
	  * \pre 
	  *       - 1 <= **app_hour** <= H
	  *       - **app_day** < **limit_day**
	  * \post 
	  *       - If find, the Agenda has assigned the new request, the Agenda has assigned the new request. 
	  *       - Otherwise, it has not produced any effect. 
	 */
	void new_app_req_level(Agenda& agenda, int app_day, int app_hour, int level, int limit_day);
	
	/**
	 * Requests free days in a range, using the model 1(Free days), based on 
	 *        - The official identifier
	 *        - The first day of the 'holiday'
	 *        - The last day of the 'holiday'
	 * 
	 * The request always will be performed, saving it had some appointment in this interval of days. 
	 *
	 * \pre 
	 *        - 2 <= **first_day** <= **limit_day**
	 *        - 1 <= **id_offi**
	 *        - 1 <= **H**
	 * \post The request has been performed.
	 */ 
	void can_req_offi_range(Agenda& agenda, int id_offi, int first_day, int limit_day, int H);
	
	/**
	 * Requests an hour free in a determinated day, using the model 2(Cancellation an hour), based on 
	 *         - The official identifier 
	 *         - The day of cancellation
	 *         - The hour of cancellation
	 *         - The day limit
	 *
	 * The requst always will be performed, saving it have exceeded the **limit_day**. 
	 *
	 * \pre  
	 *        - 1 <= **id_offi** 
	 *        - 2 <= **can_day** <= **limit_day**
	 *        - 1 <= **can_hour <= **H**
	 * \post The request has been performed.
	 */
	void can_req_offi_day_hour(Agenda& agenda, int id_offi, int can_day, int can_hour, int limit_day);
	
	/**
	 * Reads an Organigram 
	 * \pre The input stream is prepared for read the identifier of each officials.
	 * \post The Organigram has been read from the input stream.
	 */
	void read_organigram();	
	 
};

#endif 
	
