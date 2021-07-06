#include "pch.h"
#include "DBController.h"
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::Xml::Serialization;

/*Producto*/
void AppController::DBController::AddProduct(Product^ product)
{
    productDB->ListDB->Add(product);
    productDB->Persist();
}

void AppController::DBController::UpdateProduct(Product^ product)
{
    for (int i = 0; i < productDB->ListDB->Count; i++)
        if (productDB->ListDB[i]->Id == product->Id) { // verificando id
            productDB->ListDB[i] = product;  // actualiza el producto anterior con el actual
            productDB->Persist();
            return;
        }
}

void AppController::DBController::DeleteProduct(int productId)
{
    for (int i = 0; i < productDB->ListDB->Count; i++)
        if (productDB->ListDB[i]->Id == productId) { // si coincide, se procede a eliminar
            //productDB->ListDB[i]->Status = 'I';  // en lugar de borrarlo (por temas de seguridad), se le cambia de estado: INACTIVO
            productDB->ListDB->RemoveAt(i);
            productDB->Persist();
            return;
        }
}

List<Product^>^ AppController::DBController::QueryAllProducts()
{
    return productDB->ListDB;
}

int AppController::DBController::QueryLastProductId()
{
    if (productDB->ListDB->Count > 0)
        return productDB->ListDB[productDB->ListDB->Count - 1]->Id;
    else
        return 0;
}

List<Groceries^>^ AppController::DBController::QueryAllGroceries()
{
    productDB->LoadFromBinaryFile();
    List<Groceries^>^ grocerieslist = gcnew List<Groceries^>();
    for (int i = 0; i < productDB->ListDB->Count; i++) {
        if (productDB->ListDB[i]->GetType() == Groceries::typeid && productDB->ListDB[i]->Status == 'A') {
            grocerieslist->Add(dynamic_cast<Groceries^>(productDB->ListDB[i]));
        }
    }
    return grocerieslist;
}

List<HealthCare^>^ AppController::DBController::QueryAllHealthCare()
{
    productDB->LoadFromBinaryFile();
    List <HealthCare^>^ healthcareList = gcnew List<HealthCare^>();
    for (int i = 0; i < productDB->ListDB->Count; i++)
        if (productDB->ListDB[i]->GetType() == HealthCare::typeid)
            healthcareList->Add((HealthCare^)productDB->ListDB[i]);
    return healthcareList;
}

int AppController::DBController::ReturnIDbyProductName(String^ name)
{
    for (int i = 0; i < productDB->ListDB->Count; i++)
        if (productDB->ListDB[i]->Name == name)
            return productDB->ListDB[i]->Id;
}

Product^ AppController::DBController::QueryProductById(int productId)
{   //como lo tengo que buscar por id, tengo que hacer un for
    productDB->LoadFromBinaryFile();
    for (int i = 0; i < productDB->ListDB->Count; i++)
        if (productDB->ListDB[i]->Id == productId)
            return productDB->ListDB[i];
    return nullptr; // es un puntero a nulo
}

Groceries^ AppController::DBController::QueryGroceriesById(int productId)
{
    for (int i = 0; i < productDB->ListDB->Count; i++)
        if (productDB->ListDB[i]->Id == productId &&
            productDB->ListDB[i]->GetType() == Groceries::typeid)
            return (Groceries^)productDB->ListDB[i]; // se requeria un casting para evitar el error
    return nullptr;
}

HealthCare^ AppController::DBController::QueryHealthCareById(int productId)
{
    for (int i = 0; i < productDB->ListDB->Count; i++)
        if (productDB->ListDB[i]->Id == productId &&
            productDB->ListDB[i]->GetType() == HealthCare::typeid)
            return (HealthCare^)productDB->ListDB[i]; // se requeria un casting para evitar el error
    return nullptr;
}

List<Groceries^>^ AppController::DBController::QueryAllGroceriesByCoincidence(String^)
{
    List<Groceries^>^ list = gcnew List<Groceries^>();
    return list;
}

List<HealthCare^>^ AppController::DBController::QueryAllHealthCareByCoincidence(String^)
{
    List<HealthCare^>^ list = gcnew List<HealthCare^>();
    return list;
}

Product^ AppController::DBController::QueryProductByName(String^ name)
{

    for (int i = 0; i < productDB->ListDB->Count; i++)
        if (productDB->ListDB[i]->Name->ToUpper()->CompareTo(name->ToUpper())==0) { // si coincide, se procede a eliminar
             // en lugar de borrarlo (por temas de seguridad), se le cambia de estado: INACTIVO
            return productDB->ListDB[i];
        }
    return nullptr;

}

///////////////////////////////////////////////////////////////
/*Bonus Points*/
void AppController::DBController::AddBonusPointsPQ(BonusPoints^ bonuspoints)
{
    bonuspointsDB->ListPQDB->Add(bonuspoints);
    bonuspointsDB->PersistPQ();
}

void AppController::DBController::AddBonusPointsSQ(BonusPoints^ bonuspoints)
{
    bonuspointsDB->ListSQDB->Add(bonuspoints);
    bonuspointsDB->PersistSQ();
}

void AppController::DBController::UpdateBonusPointsPQ(BonusPoints^ bonuspoints)
{
    for (int i = 0; i < bonuspointsDB->ListPQDB->Count; i++)
        if (bonuspointsDB->ListPQDB[i]->PointsQuantity == bonuspoints->PointsQuantity) { // verificando cantidad de puntos
            bonuspointsDB->ListPQDB[i] = bonuspoints;  // actualiza el producto anterior con el actual
            bonuspointsDB->PersistPQ();
            return;
        }
}

void AppController::DBController::UpdateBonusPointsSQ(BonusPoints^ bonuspoints)
{
    for (int i = 0; i < bonuspointsDB->ListSQDB->Count; i++)
        if (bonuspointsDB->ListSQDB[i]->PointsQuantity == bonuspoints->PointsQuantity) { // verificando cantidad de puntos
            bonuspointsDB->ListSQDB[i] = bonuspoints;  // actualiza el producto anterior con el actual
            bonuspointsDB->PersistSQ();
            return;
        }
}

void AppController::DBController::DeleteBonusPointsSQ(int solesQuantity)
{
    for (int i = 0; i < bonuspointsDB->ListSQDB->Count; i++)
        if (bonuspointsDB->ListSQDB[i]->SolesQuantity == solesQuantity) { // si coincide, se procede a eliminar
            //productDB->ListDB[i]->Status = 'I';  // en lugar de borrarlo (por temas de seguridad), se le cambia de estado: INACTIVO
            bonuspointsDB->ListSQDB->RemoveAt(i);
            bonuspointsDB->PersistSQ();
            return;
        }
}

void AppController::DBController::DeleteBonusPointsPQ(int pointsQuantity)
{

    for (int i = 0; i < bonuspointsDB->ListPQDB->Count; i++)
        if (bonuspointsDB->ListPQDB[i]->PointsQuantity == pointsQuantity) { // si coincide, se procede a eliminar
            //productDB->ListDB[i]->Status = 'I';  // en lugar de borrarlo (por temas de seguridad), se le cambia de estado: INACTIVO
            bonuspointsDB->ListPQDB->RemoveAt(i);
            bonuspointsDB->PersistPQ();
            return;
        }
}

BonusPoints^ AppController::DBController::QueryBonusPointsByPQ(int pointsQuantity)
{
    bonuspointsDB->LoadFromBinaryFilePQ();
    for (int i = 0; i < bonuspointsDB->ListPQDB->Count; i++)
        if (bonuspointsDB->ListPQDB[i]->PointsQuantity == pointsQuantity &&
            bonuspointsDB->ListPQDB[i]->GetType() == BonusPoints::typeid)
            return (BonusPoints^)bonuspointsDB->ListPQDB[i]; // se requeria un casting para evitar el error
    return nullptr;
}

BonusPoints^ AppController::DBController::QueryBonusPointsBySQ(int solesQuantity)
{
    bonuspointsDB->LoadFromBinaryFileSQ();
    for (int i = 0; i < bonuspointsDB->ListSQDB->Count; i++)
        if (bonuspointsDB->ListSQDB[i]->SolesQuantity == solesQuantity &&
            bonuspointsDB->ListSQDB[i]->GetType() == BonusPoints::typeid)
            return (BonusPoints^)bonuspointsDB->ListSQDB[i]; // se requeria un casting para evitar el error
    return nullptr;
}

List<BonusPoints^>^ AppController::DBController::QueryAllBonusPointsPQ()
{
    bonuspointsDB->LoadFromBinaryFilePQ();
    return bonuspointsDB->ListPQDB;
}
List<BonusPoints^>^ AppController::DBController::QueryAllBonusPointsSQ()
{
    bonuspointsDB->LoadFromBinaryFileSQ();
    return bonuspointsDB->ListSQDB;
}

void AppController::DBController::RegisterSale(Order^ sale)
{

    saleDB->ListDB->Add(sale);
    saleDB->Persist();
}

List<Order^>^ AppController::DBController::QueryAllSales()
{
    saleDB->LoadFromBinaryFile();
    return saleDB->ListDB;
}

List<Order^>^ AppController::DBController::QueryAllSalesByCustomer(String^ username)
{
    List<Order^>^ list = gcnew List<Order^>();

    saleDB->LoadFromBinaryFile();

    for (int i = 0; i < saleDB->ListDB->Count; i++) {
        if (saleDB->ListDB[i]->User->Username->CompareTo(username) == 0) {
            list->Add((saleDB->ListDB[i]));

        }
        return list;
    }

}

int AppController::DBController::QueryLastSaleId()
{
    if (saleDB->ListDB->Count > 0)
        return saleDB->ListDB[saleDB->ListDB->Count - 1]->Id;
    else
        return 0;
}

Order^ AppController::DBController::QueryOrderbyId(int saleId)
{
    saleDB->LoadFromBinaryFile();
    for (int i = 0; i < saleDB->ListDB->Count; i++) {
        if (saleDB->ListDB[i]->Id == saleId) {
            return saleDB->ListDB[i];
        }
    }
    return nullptr;
}

void AppController::DBController::UpdateOrder(Order^ order)
{
    saleDB->LoadFromBinaryFile();

    for (int i = 0; i <= saleDB->ListDB->Count; i++) {
        if (saleDB->ListDB[i]->Id == order->Id) {
            saleDB->ListDB[i]->Status = order->Status;
            saleDB->ListDB[i]->DeliveryMan = order->DeliveryMan;
            saleDB->Persist();
            return;
        }
    }
}

void AppController::DBController::UpdateDeliverymanQualification(Order^ order)
{
    saleDB->LoadFromBinaryFile();
    for (int i = 0; i <= saleDB->ListDB->Count; i++) {
        if (saleDB->ListDB[i]->Id == order->Id) {
            saleDB->ListDB[i]->DeliveryManRating = order->DeliveryManRating;
            saleDB->Persist();
            return;
        }
    }
}

void AppController::DBController::UpdateCustomerQualification(Order^ order)
{
    saleDB->LoadFromBinaryFile();
    for (int i = 0; i <= saleDB->ListDB->Count; i++) {
        if (saleDB->ListDB[i]->Id == order->Id) {
            saleDB->ListDB[i]->CustomerRating = order->CustomerRating;
            saleDB->Persist();
            return;
        }
    }
}

void AppController::DBController::UpdateStatusOrder(Order^ order)
{
    saleDB->LoadFromBinaryFile();
    for (int i = 0; i <= saleDB->ListDB->Count; i++) {
        if (saleDB->ListDB[i]->Id == order->Id) {
            saleDB->ListDB[i]->Status = order->Status;
            saleDB->Persist();
            return;
        }
    }
  
}

/////////////////////////////////////////////////

SqlConnection^ AppController::DBController::GetConnection()
{
    SqlConnection^ conn = gcnew SqlConnection();    String^ connStr = "Server=" + connParam->Server + ";Database=" + connParam->Database +        ";User ID=" + connParam->User + ";Password=" + connParam->Password;    conn->ConnectionString = connStr;    conn->Open();    return conn;
}

void AppController::DBController::Init()
{
    System::Xml::Serialization::XmlSerializer^ reader =        gcnew System::Xml::Serialization::XmlSerializer(ConnectionParam::typeid);    System::IO::StreamReader^ file = nullptr;    try {        file = gcnew System::IO::StreamReader("init.xml");        connParam = (ConnectionParam^)reader->Deserialize(file);    }    catch (...) {        return;    }    finally {        if (file != nullptr) file->Close();    }
}

/*User*/
void AppController::DBController::AddUser(User^ user)
{
    /*
    userDB->ListDB->Add(user);
    userDB->SaveUsers();
*/
// Paso 1: Se obtiene la conexión
    SqlConnection^ conn = GetConnection();

    // Paso 2:  Se prepara la sentencia
    SqlCommand^ comm;
    String^ strCmd;
    strCmd = "dbo.usp_AddUser";
    comm = gcnew SqlCommand(strCmd, conn);
    comm->CommandType = System::Data::CommandType::StoredProcedure;
    comm->Parameters->Add("@vusername", System::Data::SqlDbType::VarChar, 100);
    comm->Parameters->Add("@vpassword", System::Data::SqlDbType::VarChar, 100);
    comm->Parameters->Add("@vfirst_name", System::Data::SqlDbType::VarChar, 100);
    comm->Parameters->Add("@vlast_name", System::Data::SqlDbType::VarChar, 100);
    comm->Parameters->Add("@cgender", System::Data::SqlDbType::Char, 1);
    comm->Parameters->Add("@vdocument_number", System::Data::SqlDbType::VarChar, 15);
    comm->Parameters->Add("@vphone_number", System::Data::SqlDbType::VarChar, 50);
    comm->Parameters->Add("@vaddress", System::Data::SqlDbType::VarChar, 150);
    comm->Parameters->Add("@vemail", System::Data::SqlDbType::VarChar, 150);
    comm->Parameters->Add("@vcategory", System::Data::SqlDbType::VarChar, 15);

    SqlParameter^ outputIdParam = gcnew SqlParameter("@iid", System::Data::SqlDbType::Int);
    outputIdParam->Direction = System::Data::ParameterDirection::Output;
    comm->Parameters->Add(outputIdParam);
    comm->Prepare();

    comm->Parameters["@vusername"]->Value = user->Username;
    comm->Parameters["@vpassword"]->Value = user->Password;
    comm->Parameters["@vfirst_name"]->Value = user->FirstName;
    comm->Parameters["@vlast_name"]->Value = user->LastName;
    comm->Parameters["@cgender"]->Value = user->Gender;
    comm->Parameters["@vdocument_number"]->Value = user->DocumentNumber;
    comm->Parameters["@vphone_number"]->Value = user->PhoneNumber;
    comm->Parameters["@vaddress"]->Value = user->Address;
    comm->Parameters["@vemail"]->Value = user->Email;
    comm->Parameters["@vcategory"]->Value = user->Category;


    //Paso 3: Se ejecuta la sentencia
    comm->ExecuteNonQuery();

    //Paso 4: Si se quiere procesar la salida.
    int output_id = Convert::ToInt32(comm->Parameters["@id"]->Value);

    //Paso 5: Se cierra la conexión
    conn->Close();

}

void AppController::DBController::UpdateUser(User^ user)
{
    userDB->SaveUsers();
    for (int i = 0; i < userDB->ListDB->Count; i++)
        if (userDB->ListDB[i]->Id == user->Id) {
            userDB->ListDB[i] = user;
            userDB->SaveUsers();
            return;
        }
}

void AppController::DBController::DeleteUser(int userId)
{
    for (int i = 0; i < userDB->ListDB->Count; i++)
        if (userDB->ListDB[i]->Id == userId) {
            //productDB->ListDB[i]->Status = 'I';
            userDB->ListDB->RemoveAt(i);
            userDB->SaveUsers();
            return;
        }
}

User^ AppController::DBController::ValidateUser(String^ username, String^ password)
{
    User^ user = nullptr;
    //LoadUsers();
    /*
    for (int i = 0; i < userDB->ListDB->Count; i++) {
        if (userDB->ListDB[i]->Username->Equals(username) &&
            userDB->ListDB[i]->Password->Equals(password))
            return userDB->ListDB[i];
    }
    */
    /* Paso 1: Se obtiene la conexión */
    SqlConnection^ conn = GetConnection();

    /* Paso 2: Se prepara la sentencia */
    SqlCommand^ comm = gcnew SqlCommand();
    comm->Connection = conn;
    comm->CommandText = "SELECT * FROM app_user WHERE username='" + username +
        "' AND password='" + password + "'";

    /* Paso 3: Se ejecuta la sentencia */
    SqlDataReader^ dr = comm->ExecuteReader();

    /* Paso 4: Se procesan los resultados */
    if (dr->Read()) {
        user = gcnew User();
        user->Id = (int)dr["id"];
        user->Username = (String^)dr["username"];
        user->FirstName = safe_cast<String^>(dr["first_name"]);
        user->LastName = safe_cast<String^>(dr["last_name"]);
        user->Category = safe_cast<String^>(dr["category"]);
    }

    /* Paso 5: Se cierra los objetos de conexión!!!!!!!!!! */
    if (dr != nullptr) dr->Close();
    if (conn != nullptr) conn->Close();

    return user;
}

User^ AppController::DBController::QueryUserbyId(int userId)
{
    userDB->LoadUsers();
    for (int i = 0; i < userDB->ListDB->Count; i++)
        if (userDB->ListDB[i]->Id == userId &&
            userDB->ListDB[i]->GetType() == User::typeid)
            return (User^)userDB->ListDB[i];
    return nullptr;
}

int AppController::DBController::ReturnIDbyUserName(String^ username)
{
    userDB->LoadUsers();
    for (int i = 0; i < userDB->ListDB->Count; i++)
        if (userDB->ListDB[i]->Username->Equals(username))
            return userDB->ListDB[i]->Id;
}

int AppController::DBController::QueryLastUserId()
{
    
    if (userDB->ListDB->Count > 0)
        return userDB->ListDB[userDB->ListDB->Count - 1]->Id;
    else
        return 0;
}

List<User^>^ AppController::DBController::QueryAllUsers()
{
    userDB->LoadUsers();
    return userDB->ListDB;

}

bool AppController::DBController::ConfirmUser(User^ user) {

    userDB->LoadUsers();

    for (int i = 0; i < userDB->ListDB->Count; i++) {
        if (userDB->ListDB[i]->DocumentNumber == user->DocumentNumber
            | userDB->ListDB[i]->PhoneNumber == user->PhoneNumber
            | userDB->ListDB[i]->Username == (user->Username) )
            //userDB->ListDBUser[i]->PhoneNumber==user->PhoneNumber | userDB->ListDBUser[i]-> Username== user->Username )
        {
            return false;
        }
    }
    return true;
}


/*Customer*/
void AppController::DBController::AddCustomers(Customer^ customer)
{
    customerDB->ListDB->Add(customer);
    SaveCustomers();
}

Customer^ AppController::DBController::QueryCustomerById(int customerId)
{
    LoadCustomers();
    for (int i = 0; i < customerDB->ListDB->Count; i++) {
        if (customerDB->ListDB[i]->Id == customerId)
            return customerDB->ListDB[i];
    }
    return nullptr;
}

List<Customer^>^ AppController::DBController::QueryAllCustomer()
{   //VERIFICAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
    userDB->LoadUsers();
    List<Customer^>^ list = gcnew List<Customer^>();
    for (int i = 0; i < userDB->ListDB->Count; i++) {
        if (userDB->ListDB[i]->GetType() == Customer::typeid && userDB->ListDB[i]->Status == 'A') {
            list->Add(dynamic_cast<Customer^>(userDB->ListDB[i]));
        }
    }
    return list;
}

bool AppController::DBController::ConfirmCustomer(Customer^ customer)
{
    userDB->LoadUsers();

    for (int i = 0; i < userDB->ListDB->Count; i++) {
        if (userDB->ListDB[i]->DocumentNumber == customer->DocumentNumber
            | userDB->ListDB[i]->PhoneNumber == customer->PhoneNumber
            | userDB->ListDB[i]->Username == (customer->Username))
        {
            return false;
        }
    }
    return true;
}

void AppController::DBController::SaveCustomers()
{
    System::Xml::Serialization::XmlSerializer^ writer =
    gcnew System::Xml::Serialization::XmlSerializer(CustomerDB::typeid);

    System::IO::StreamWriter^ file = gcnew System::IO::StreamWriter("Customers.xml");
    writer->Serialize(file, customerDB);
    file->Close();
}

void AppController::DBController::LoadCustomers()
{
    System::Xml::Serialization::XmlSerializer^ reader =
        gcnew System::Xml::Serialization::XmlSerializer(CustomerDB::typeid);
    System::IO::StreamReader^ file = nullptr;
    try {
        file = gcnew System::IO::StreamReader("Customers.xml");
        customerDB = (CustomerDB^)reader->Deserialize(file);
    }
    catch (...) {
        return;
    }
    finally {
        if (file != nullptr) file->Close();
    }
}

/*Manager*/

Manager^ AppController::DBController::QueryManagerById(int managerId)
{
    LoadManagers();
    for (int i = 0; i < managerDB->ListDB->Count; i++) {
        if (managerDB->ListDB[i]->Id == managerId)
            return managerDB->ListDB[i];
    }
    return nullptr;
}

List<Manager^>^ AppController::DBController::QueryAllManagers()
{   //VERIFICAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
    userDB->LoadUsers();
    List<Manager^>^ list = gcnew List<Manager^>();
    for (int i = 0; i < userDB->ListDB->Count; i++) {
        if (userDB->ListDB[i]->GetType() == Manager::typeid && userDB->ListDB[i]->Status == 'A') {
            list->Add(dynamic_cast<Manager^>(userDB->ListDB[i]));
        }
    }
    return list;
}

bool AppController::DBController::ConfirmManager(Manager^ manager)
{
    userDB->LoadUsers();

    for (int i = 0; i < userDB->ListDB->Count; i++) {
        if (userDB->ListDB[i]->DocumentNumber == manager->DocumentNumber
            | userDB->ListDB[i]->PhoneNumber == manager->PhoneNumber
            | userDB->ListDB[i]->Username == (manager->Username) | !(manager->VerificationCode == 0000))
        {
            return false;
        }
    }
    return true;

}

void AppController::DBController::AddManagers(Manager^ manager)
{
    managerDB->ListDB->Add(manager);
    SaveManagers();
}

void AppController::DBController::SaveManagers()
{
    System::Xml::Serialization::XmlSerializer^ writer =
    gcnew System::Xml::Serialization::XmlSerializer(ManagerDB::typeid);

    System::IO::StreamWriter^ file = gcnew System::IO::StreamWriter("Managers.xml");
    writer->Serialize(file, managerDB);
    file->Close();
}

void AppController::DBController::LoadManagers()
{
    System::Xml::Serialization::XmlSerializer^ reader =
    gcnew System::Xml::Serialization::XmlSerializer(ManagerDB::typeid);
    System::IO::StreamReader^ file = nullptr;
    try {
        file = gcnew System::IO::StreamReader("Managers.xml");
        managerDB = (ManagerDB^)reader->Deserialize(file);
    }
    catch (...) {
        return;
    }
    finally {
        if (file != nullptr) file->Close();
    }
}

void AppController::DBController::AddtoCarrito(Product^product)
{
    carritoDB->ListDB->Add(product);
    productDB->Persist();
}

void AppController::DBController::DeletefromCarrito(int productId)
{

    for (int i = 0; i < carritoDB->ListDB->Count; i++)
        if (carritoDB->ListDB[i]->Id == productId) {
            carritoDB->ListDB->RemoveAt(i);
            //carritoDB->Persist();
            return;
        }
}

void AppController::DBController::DeleteAllCarrito()
{
  
    for (int i = 0; i <= carritoDB->ListDB->Count; i++) {
        carritoDB->ListDB->RemoveAt(i);
        //carritoDB->Persist();
    }
}

List<Product^>^ AppController::DBController::QueryAllCarrito()
{
    carritoDB->LoadFromBinaryFile();
    return carritoDB->ListDB;
}

bool AppController::DBController::QueryCarritoByName(String^ name)
{

    for (int i = 0; i < carritoDB->ListDB->Count; i++)
        if (carritoDB->ListDB[i]->Name->ToUpper()->CompareTo(name->ToUpper()) == 0) { // si coincide, se procede a eliminar
             // en lugar de borrarlo (por temas de seguridad), se le cambia de estado: INACTIVO
            return true;
        }
    return false;
}


/*Deliveryman*/

DeliveryMan^ AppController::DBController::QueryDeliveryManById(int deliverymanId)
{
    LoadDeliveryMan();
    for (int i = 0; i < deliveryManDB->ListDB->Count; i++) {
        if (deliveryManDB->ListDB[i]->Id == deliverymanId)
        {
            return (DeliveryMan^)(deliveryManDB->ListDB[i]);
        }
    }
    return nullptr;
}

List<DeliveryMan^>^ AppController::DBController::QueryAllDeliveryMan()
{   //VERIFICAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAR
    userDB->LoadUsers();
    List<DeliveryMan^>^ list = gcnew List<DeliveryMan^>();
    for (int i = 0; i < userDB->ListDB->Count; i++) {
        if (userDB->ListDB[i]->GetType() == DeliveryMan::typeid && userDB->ListDB[i]->Status == 'A') {
            list->Add(dynamic_cast<DeliveryMan^>(userDB->ListDB[i]));
        }
    }
    return list;
}

bool AppController::DBController::ConfirmDeliveryMan(DeliveryMan^ deliveryman)
{
    userDB->LoadUsers();

    for (int i = 0; i < userDB->ListDB->Count; i++) {
        if (userDB->ListDB[i]->DocumentNumber == deliveryman->DocumentNumber
            | userDB->ListDB[i]->PhoneNumber == deliveryman->PhoneNumber
            | userDB->ListDB[i]->Username == (deliveryman->Username) | !(deliveryman->VerificationCode == 123456))
        {
            return false;
        }
    }
    return true;

}

void AppController::DBController::AddDeliveryMan(DeliveryMan^ deliveryman)
{
    deliveryManDB->ListDB->Add(deliveryman);
    SaveDeliveryMan();
}

void AppController::DBController::SaveDeliveryMan()
{
    System::Xml::Serialization::XmlSerializer^ writer =
        gcnew System::Xml::Serialization::XmlSerializer(DeliveryManDB::typeid);

    System::IO::StreamWriter^ file = gcnew System::IO::StreamWriter("DeliveryMan.xml");
    writer->Serialize(file, deliveryManDB);
    file->Close();
}

void AppController::DBController::LoadDeliveryMan()
{
    System::Xml::Serialization::XmlSerializer^ reader =
        gcnew System::Xml::Serialization::XmlSerializer(DeliveryManDB::typeid);
    System::IO::StreamReader^ file = nullptr;
    try {
        file = gcnew System::IO::StreamReader("DeliveryMan.xml");
        deliveryManDB = (DeliveryManDB^)reader->Deserialize(file);
    }
    catch (...) {
        return;
    }
    finally {
        if (file != nullptr) file->Close();
    }
}
/*Ubicacion*/
String^ AppController::DBController::CompareAdress(String^ Adress)
{
    if (Adress == "Direccion1")return "13 minutos";
    if (Adress == "Direccion2")return "6 minutos";
    if (Adress == "Direccion3")return "10 minutos";
    if (Adress == "Direccion4")return "10 minutos";
    if (Adress == "Direccion5")return "11 minutos";
    if (Adress == "Direccion6")return "11 minutos";
    if (Adress == "Direccion7")return "8 minutos";
    if (Adress == "Direccion8")return "8 minutos";
    if (Adress == "Direccion9")return "5 minutos";
    if (Adress == "Direccion10")return "11 minutos";
    if (Adress == "Direccion11")return "12 minutos";
    if (Adress == "Direccion12")return "11 minutos";
    if (Adress == "Direccion13")return "11 minutos";
    if (Adress == "Direccion14")return "9 minutos";
    if (Adress == "Direccion15")return "9 minutos";
    if (Adress == "Direccion16")return "8 minutos";
    if (Adress == "Direccion17")return "9 minutos";
    if (Adress == "Direccion18")return "10 minutos";
    if (Adress == "Direccion19")return "10 minutos";
    if (Adress == "Direccion20")return "13 minutos";
    if (Adress == "Direccion21")return "11 minutos";
}


//////////////////////////////////////////////