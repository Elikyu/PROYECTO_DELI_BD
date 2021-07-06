#include "Ubicacion.h"
#include "CarritoCustomerForm.h"

System::Void AppView::Ubicacion::btnAddressCheck_Click_Click(System::Object^ sender, System::EventArgs^ e)
{
	int customerId = UserManager::ReturnIDbyUserName(txtUSER->Text);
	User^ u = UserManager::QueryUserbyId(customerId);
	CarritoCustomerForm^ form = gcnew CarritoCustomerForm();
	form->txtSAddres->Text = u->Address;
	this->Close();
}
