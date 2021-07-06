/**
 * Project SalesSolution
 */

#include "pch.h"
#include "DeliveryMan.h"

/**
 * DeliveryMan implementation
 */

AppModel::DeliveryMan::DeliveryMan(int id, String^ userName, String^ password, String^ firstName, String^ lastName, char gender, String^ documentnumber, String^ phonenumber, String^ email, String^ category, String^ address, char status, double quota, int verificationcode, double  deliveryManRatingAverage)
{
	Id = id;
	Username = userName;
	Password = password;
	FirstName = firstName;
	LastName = lastName;
	Gender = gender;
	DocumentNumber = documentnumber;
	PhoneNumber = phonenumber;
	Category = category;
	Email = email;
	Address = address;
	Status = status;
	VerificationCode = verificationcode;
	DeliveryManRatingAverage = deliveryManRatingAverage;
}
