#include "GeniusBar.hpp"

//Initializes the class
GeniusBar::GeniusBar(): current_wait_time_(0), number_of_available_geniuses_(TOTAL_NUMBER_OF_GENIUSES),
                        number_of_customers_(0){}

bool GeniusBar::addWaitingCustomer(Customer& new_customer){
	if(number_of_customers_ < MAX_NUMBER_OF_CUSTOMERS){
		genius_bar_[number_of_customers_] = new_customer;
		current_wait_time_ += WAIT_TIME_INCREMENT;

		new_customer.updateWaitTime(current_wait_time_);
		number_of_customers_++;
		return true;
	} else{
		return false;
	}
}

//Decreases the number of Customers AS WELL as the number of Geniuses by 1
bool GeniusBar::assignGeniusToCustomer(){
	if((number_of_customers_ > 0) && (number_of_available_geniuses_ > 0)){
		number_of_customers_--;
		number_of_available_geniuses_--;
		return true;
	}

	return false;
}
//Increases the value of available geniuses by 1
bool GeniusBar::releaseGenius(){
	if(number_of_available_geniuses_ < TOTAL_NUMBER_OF_GENIUSES){
		number_of_available_geniuses_++;
		return true;
	}
	return false;
}

bool GeniusBar::updateCustomersWaitTime(){
	if(number_of_customers_ > 0){
		for(int i = 0;  i < number_of_customers_; i++){
			genius_bar_[i].updateWaitTime(WAIT_TIME_INCREMENT);
		}
		return true;
	}
	return false;
}
