#pragma once
using namespace System;

public ref class ComboBoxItem2
{
public:
	String^ Name;
	//property int SolesQuantity;
	//property double PercentageDiscount;
	//property int PointsEarned;
	ComboBoxItem2( String^ Name)
	{
		this->Name = Name;
	}

	String^ ToString()  override
	{
		return this->Name;
	}

};