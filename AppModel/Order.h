/**
 * Project SalesSolution
 */
#include "SaleDetail.h"
#include "DeliveryMan.h"
#include "Customer.h"
//#include "Store.h"

#pragma once
using namespace System;
using namespace System :: Collections::Generic;

namespace AppModel {
    [Serializable]
    public ref class Order {
    public:
        property int Id;
        //property String^ Product;
        property char Status;  // en espera, entregado, en camino
        property String^ Date;
        property char PaymentType; // siempre sera con tarjeta de credito
        property int ArrivalTime;
        property int DeliveryManRating;
        property int CustomerRating;
        property String^ Ubication;
        property DeliveryMan^ DeliveryMan;
        property Customer^ Customer;
        property User^ User;
        property double Total;
        property List<SaleDetail^>^ Details;
    };
}

