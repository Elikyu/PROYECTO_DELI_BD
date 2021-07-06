/**
 * Project SalesSolution
 */

#include "pch.h"
#include "Manager.h"

/**
 * Manager implementation
 */

AppModel::Manager::Manager(int id, String^ firstName, String^ lastName, String^ phoneNumber, int verificationcode, int employeesNumber)
{
	Id = id;
	FirstName = firstName;
	PhoneNumber = phoneNumber;
	VerificationCode = verificationcode;
	EmployeesNumber = employeesNumber;
}
