#include "AccesoUbicacionDestino.h"
#include "CarritoCustomerForm.h"
#include"Ubicacion.h"

System::Void AppView::AccesoUbicacionDestino::txtAddressC_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    Ubicacion^ ubi = gcnew Ubicacion();

    if (ubi->chckAddress->Checked == true) {
        txtAddressC->Text = ubi->txtAddressC->Text;
    }
    else if (ubi->chckCustomAddress->Checked == true) {
        txtAddressC->Text = ubi->txtCustomAddressC->Text;
    }

}

System::Void AppView::AccesoUbicacionDestino::txtArrivalTimeC_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    Ubicacion^ time = gcnew Ubicacion();
    txtArrivalTimeC->Text = time->txtArrivalTimeC->Text;

}

System::Void AppView::AccesoUbicacionDestino::txtNumberContact_TextChanged(System::Object^ sender, System::EventArgs^ e)
{
    CarritoCustomerForm^ customer = gcnew CarritoCustomerForm();
    int customerId = UserManager::ReturnIDbyUserName(customer->textUserNameCS->Text);
    Customer^ u = UserManager::QueryCustomerbyId(customerId);
    txtNumberContact->Text = u->PhoneNumber;
    
}
