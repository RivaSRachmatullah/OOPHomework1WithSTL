/**
 * @file
 * @brief Header Teller Class
 * 
 */
/**
 * \class Teller
 * 
 * @brief Teller Class
 * @details Represent a Teller
 * @note Using STL queue
 * 
 * @author Indam Muhammad (13512026)
 *
 * @version v1.1
 * 
 */
#ifndef TELLER_H
#define TELLER_H

#include <queue>
#include <iostream>

using namespace std;

class Teller
{
private:
	int NumberofTeller;
	bool *TellerServingStatus;
	queue<int> *T;

public:
	/**
	 * @brief Initializes a new instance of Teller class with 5 block Queue.
	 */
	Teller();

	/**
	 * @brief Initializes a new instance of Teller class with NumberofTeller block Queue.
	 * 
	 * @param[in] NumberofTeller The number of teller.
	 */
	Teller(int NumberofTeller);

	/**
	 * @brief Initializes a new instance of the Teller class with all the content of specified Teller.
	 * 
	 * @param[in] T The object Teller that will be copied.
	 */
	Teller(const Teller &T);

	/**
	 * @brief Copy all content of specified Teller to current Teller.
	 * 
	 * @param[in] T The object Teller that will be copied.
	 */
	Teller& operator=(const Teller &T);

	/**
	 * @brief Clear an instance of Teller from memory.
	 */
	~Teller();
	
	
	/**
	 * @brief Delete element with the value ID from certain Queue.
	 * @details This method does searching ID on Queue's head address. If the ID isn't found then it will give a message and return 0.
	 * 
	 * @param[in] ID The element to delete.
	 * @return ID of element if found; 0 if not found.
	 */
	int DepartureofAnElement(int ID);

	/**
	 * @brief Add element with the value ID to certain Queue.
	 * @details It will add element ID to the Queue who has the least number of element in Queue.
	 * 
	 * @param[in] ID The element to add.
	 */
	void ArriveofAnElement(int ID);

	/**
	 * @brief Delete all element from all Queue and Print the element to console.
	 */
	void DepartureAll();
	
	/**
	 * @brief Print all the Queue in Teller.
	 * @details Print will be printed like Qi = {x1,x2,...,xn}
	 */
	void Print();

private:
	/**
	* @brief Jockeying function.
	* @details Jockeying will happen if origin Queue has element that are more than two elements from others Queue.
	*
	* @param[in] iOrigin Queue's Number that will do Jockeying.
	* @return -1 if Jockeying isn't happening, Queue's number if Jockeying is happening.
	*/
	int Jockeying(int iOrigin);

	/**
	 * @brief Print queue on a certain index of Teller.
	 * @details on STL, there is no method for printing all elements on Queue. This method does copy a queue to temporary queue for printing
	 * 
	 * @param index Queue's number on Teller
	 */
	void PrintQueue(int index);
};

#endif

