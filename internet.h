// =========================================================
// File: Internet.h
// Author: José Armando Rosas Balderas - A01704132
// Date:04/06/2022
// Description: This file implements some functions. And it
//is a child class of Operator, designed for people that
//use more internet than messages and talks.
// =========================================================

#ifndef INTERNET_H_INCLUDED
#define INTERNET_H_INCLUDED

#include "Operator.h"

class InternetOperator : public Operator {
private:
  const double LIMITGB = 10.0;

public:
  InternetOperator(int, double, double, double, int, OperatorType);
  InternetOperator(const InternetOperator&);

  double calculateTalkingCost(int, int);
  double calculateMessageCost(int, int, int);
  double calculateNetworkCost(double);
};

InternetOperator:: InternetOperator (int identificacion, double costoLlamada,
                      double costoMensaje, double costoGB,
                      int descuento, OperatorType Tipo) :
    Operator(identificacion, costoLlamada, costoMensaje, costoGB, descuento, INTERNET){}

InternetOperator :: InternetOperator (const InternetOperator &other):Operator(other) {}

double InternetOperator:: calculateTalkingCost(int minute, int age){
    double talkingCost =0;
    if(minute <=0 || age <= 0){
        return talkingCost;
    }

    if(minute <= 2){
        talkingCost += (minute * talkingCharge);
        talkingCost -= discountRate * talkingCost/100;
        return talkingCost;
    }
    talkingCost += (minute * talkingCharge);
    return talkingCost;

}

double InternetOperator:: calculateMessageCost(int quantity, int thisOpId, int otherOpId){
    double CostoMensaje = 0;
    if (quantity <= 0){
        return CostoMensaje;
    }
    if (quantity < 3){
        CostoMensaje += messageCost * quantity;
        CostoMensaje -= discountRate * CostoMensaje/100;
        return CostoMensaje;
    }

    CostoMensaje += messageCost * quantity;
        return CostoMensaje;
}

double InternetOperator::calculateNetworkCost(double amount) {
    double CostoInternet = 0;
    if(amount <= 0){
        return CostoInternet;
    }
    if((amount + totalInternetUsage) > LIMITGB)
        CostoInternet += (amount - LIMITGB + totalInternetUsage) * networkCharge;
        return CostoInternet;

}
#endif // INTERNET_H_INCLUDED
