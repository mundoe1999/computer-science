#ifndef CUSTOMER_HPP_
#define CUSTOMER_HPP_

#include <string>

class Customer{
  public:

      Customer();  //default constructor
      Customer(std::string name, std::string device = "unknown", int wait_time = 0);   //parameterized constructor

      //return: name_
      std::string getName();

      //return: defective_device_
      std::string getDevice();

      //return: wait_time_
      int getWaitTime();

      //post: wait_time_ = new_wait_time
      void updateWaitTime(int new_wait_time);

  private:
      std::string name_;
      std::string defective_device_;
      int wait_time_;

}; // end Customer

#endif
