#include "pch.h"
#include "DBController.h"
using namespace System::IO;
using namespace System::Globalization;
using namespace System::Runtime::Serialization;
using namespace System::Runtime::Serialization::Formatters::Binary;
using namespace System::Xml::Serialization;

void AppController::DBController::Init()
{
    System::Xml::Serialization::XmlSerializer^ reader =        gcnew System::Xml::Serialization::XmlSerializer(ConnectionParam::typeid);    System::IO::StreamReader^ file = nullptr;    try {        file = gcnew System::IO::StreamReader("init.xml");        connParam = (ConnectionParam^)reader->Deserialize(file);    }    catch (...) {        return;    }    finally {        if (file != nullptr) file->Close();    }
}

SqlConnection^ AppController::DBController::GetConnection()
{
    SqlConnection^ conn = gcnew SqlConnection();    String^ connStr = "Server=" + connParam->Server + ";Database=" + connParam->Database +        ";User ID=" + connParam->User + ";Password=" + connParam->Password;    conn->ConnectionString = connStr;    conn->Open();    return conn;
}

/*Producto*/
void AppController::DBController::AddProduct(Product^ product) {

    SqlConnection^ conn = GetConnection();
    String^ strCmd;
    if (product->GetType() == Groceries::typeid) {
        strCmd = "dbo.usp_AddGroceries";
        SqlCommand^ comm = gcnew SqlCommand(strCmd,conn);
        comm->CommandType = System::Data::CommandType::StoredProcedure;
        comm->Parameters->Add("@name", System::Data::SqlDbType::VarChar, 250);
        comm->Parameters->Add("@description", System::Data::SqlDbType::VarChar, 500);
        comm->Parameters->Add("@price", System::Data::SqlDbType::Decimal, 10);
        comm->Parameters["@price"]->Precision = 10;
        comm->Parameters["@price"]->Scale = 2;
        comm->Parameters->Add("@stockTotal", System::Data::SqlDbType::Int);
        comm->Parameters->Add("@photo", System::Data::SqlDbType::Image);
        comm->Parameters->Add("@brand", System::Data::SqlDbType::VarChar, 250);
        comm->Parameters->Add("@quantitySold", System::Data::SqlDbType::VarChar, 250);
        SqlParameter^ outputIdParam = gcnew SqlParameter("@id", System::Data::SqlDbType::Int);
        outputIdParam->Direction = System::Data::ParameterDirection::Output;
        comm->Parameters->Add(outputIdParam);
        comm->Prepare();

        Groceries^ b = dynamic_cast<Groceries^>(product);
        comm->Parameters["@name"]->Value = b->Name;
        comm->Parameters["@description"]->Value = b->Description;
        comm->Parameters["@price"]->Value = b->Price;
        comm->Parameters["@stockTotal"]->Value = b->StockTotal;
        comm->Parameters["@photo"]->Value = b->Photo;
        comm->Parameters["@brand"]->Value = b->Brand;
        comm->Parameters["@quantitySold"]->Value = b->QuantitySold;
        
        if (product->Photo != nullptr)
            comm->Parameters["@photo"]->Value = product->Photo;
        else
            comm->Parameters["@photo"]->Value = DBNull::Value;

        //Paso 3: Se ejecuta la sentencia
        comm->ExecuteNonQuery();
        //Paso 4: Se procesa el resultado.
        int output_id = Convert::ToInt32(comm->Parameters["@id"]->Value);

    }

    else if (product->GetType() == HealthCare::typeid) {
        strCmd = "dbo.usp_AddHealthCare";
        SqlCommand^ comm = gcnew SqlCommand(strCmd, conn);
        comm->CommandType = System::Data::CommandType::StoredProcedure;
        comm->Parameters->Add("@name", System::Data::SqlDbType::VarChar, 250);
        comm->Parameters->Add("@description", System::Data::SqlDbType::VarChar, 500);
        comm->Parameters->Add("@price", System::Data::SqlDbType::Decimal, 10);
        comm->Parameters["@price"]->Precision = 10;
        comm->Parameters["@price"]->Scale = 2;
        comm->Parameters->Add("@stockTotal", System::Data::SqlDbType::Int);
        comm->Parameters->Add("@photo", System::Data::SqlDbType::Image);
        comm->Parameters->Add("@brand", System::Data::SqlDbType::VarChar, 250);
        comm->Parameters->Add("@quantitySold", System::Data::SqlDbType::VarChar, 250);


        SqlParameter^ outputIdParam = gcnew SqlParameter("@id", System::Data::SqlDbType::Int);
        outputIdParam->Direction = System::Data::ParameterDirection::Output;
        comm->Parameters->Add(outputIdParam);

        comm->Prepare();

        HealthCare^ b = dynamic_cast<HealthCare^>(product);
        comm->Parameters["@name"]->Value = b->Name;
        comm->Parameters["@description"]->Value = b->Description;
        comm->Parameters["@price"]->Value = b->Price;
        comm->Parameters["@stockTotal"]->Value = b->StockTotal;
        comm->Parameters["@photo"]->Value = b->Photo;
        comm->Parameters["@brand"]->Value = b->Brand;
        comm->Parameters["@quantitySold"]->Value = b->QuantitySold;

        //conn->Open();
        comm->ExecuteNonQuery();
        //Para leer el dato de salida
        int id_output = Convert::ToInt32(comm->Parameters["@id"]->Value);
    }

    conn->Close();

}

void AppController::DBController::UpdateProduct(Product^ product)
{
    SqlConnection^ conn = GetConnection();

    /* 2do paso: Se prepara la sentencia */
  
    String^ strCmd;
    if (product->GetType() == Groceries::typeid) {
        strCmd = "dbo.usp_UpdateGroceries";
        SqlCommand^  comm = gcnew SqlCommand(strCmd, conn);
        comm->CommandType = System::Data::CommandType::StoredProcedure;
        comm->Parameters->Add("@id", System::Data::SqlDbType::Int);
        comm->Parameters->Add("@name", System::Data::SqlDbType::VarChar, 250);
        comm->Parameters->Add("@description", System::Data::SqlDbType::VarChar, 500);
        comm->Parameters->Add("@price", System::Data::SqlDbType::Decimal, 10);
        comm->Parameters["@price"]->Precision = 10;
        comm->Parameters["@price"]->Scale = 2;
        comm->Parameters->Add("@stockTotal", System::Data::SqlDbType::Int);
        comm->Parameters->Add("@brand", System::Data::SqlDbType::VarChar, 250);
        comm->Parameters->Add("@status", System::Data::SqlDbType::Char, 1);
        comm->Parameters->Add("@photo", System::Data::SqlDbType::Image);
        //
        comm->Parameters->Add("@quantitySold", System::Data::SqlDbType::Int);
        //
        comm->Prepare();

        Groceries^ b = dynamic_cast<Groceries^>(product);
        comm->Parameters["@id"]->Value = b->Id;
        comm->Parameters["@name"]->Value = b->Name;
        comm->Parameters["@description"]->Value = b->Description;
        comm->Parameters["@price"]->Value = b->Price;
        comm->Parameters["@stockTotal"]->Value = b->StockTotal;
        comm->Parameters["@brand"]->Value = b->Brand;
        comm->Parameters["@status"]->Value = "A";
        //
        comm->Parameters["@quantitySold"]->Value = b->QuantitySold;
        //
        if (b->Photo != nullptr)
            comm->Parameters["@photo"]->Value = b->Photo;
        else
            comm->Parameters["@photo"]->Value = DBNull::Value;

        comm->ExecuteNonQuery();
    }
    else if (product->GetType() == HealthCare::typeid) {
        strCmd = "dbo.usp_UpdateHealthCare";
        SqlCommand^  comm = gcnew SqlCommand(strCmd, conn);
        comm->CommandType = System::Data::CommandType::StoredProcedure;
        comm->Parameters->Add("@id", System::Data::SqlDbType::Int);
        comm->Parameters->Add("@name", System::Data::SqlDbType::VarChar, 250);
        comm->Parameters->Add("@description", System::Data::SqlDbType::VarChar, 500);
        comm->Parameters->Add("@price", System::Data::SqlDbType::Decimal, 10);
        comm->Parameters["@price"]->Precision = 10;
        comm->Parameters["@price"]->Scale = 2;
        comm->Parameters->Add("@stockTotal", System::Data::SqlDbType::Int);
        comm->Parameters->Add("@brand", System::Data::SqlDbType::VarChar, 250);
        comm->Parameters->Add("@status", System::Data::SqlDbType::Char, 1);
        comm->Parameters->Add("@photo", System::Data::SqlDbType::Image);
        //
        comm->Parameters->Add("@quantitySold", System::Data::SqlDbType::Int);
        //
        comm->Prepare();

        HealthCare^ b = dynamic_cast<HealthCare^>(product);
        comm->Parameters["@id"]->Value = b->Id;
        comm->Parameters["@name"]->Value = b->Name;
        comm->Parameters["@description"]->Value = b->Description;
        comm->Parameters["@price"]->Value = b->Price;
        comm->Parameters["@stockTotal"]->Value = b->StockTotal;
        comm->Parameters["@brand"]->Value = b->Brand;
        comm->Parameters["@status"]->Value = "A";
        //
        comm->Parameters["@quantitySold"]->Value = b->QuantitySold;
        //
        if (b->Photo != nullptr)
            comm->Parameters["@photo"]->Value = b->Photo;
        else
            comm->Parameters["@photo"]->Value = DBNull::Value;

        comm->ExecuteNonQuery();
    }

    //IMPORTANTE Paso 4: Cerramos la conexión con la BD
    if (conn != nullptr) conn->Close();
}

void AppController::DBController::DeleteProduct(int productId)
{
    SqlConnection^ conn = GetConnection();

    /* 2do paso: Se prepara la sentencia */
    SqlCommand^ comm;
    String^ strCmd;
    strCmd = "dbo.usp_DeleteProduct";
    comm = gcnew SqlCommand(strCmd, conn);
    comm->CommandType = System::Data::CommandType::StoredProcedure;
    comm->Parameters->Add("@id", System::Data::SqlDbType::Int);
    comm->Prepare();

    comm->Parameters["@id"]->Value = productId;
    //conn->Open();
    comm->ExecuteNonQuery();

    //IMPORTANTE Paso 4: Cerramos la conexión con la BD
    conn->Close();
}

List<Product^>^ AppController::DBController::QueryAllProducts()
{
    /*return productDB->ListDB;*/


    /* 1er paso: Se obtiene la conexión */
    SqlConnection^ conn = GetConnection();

    /* 2do paso: Se prepara la sentencia */
    SqlCommand^ comm;

    comm = gcnew SqlCommand("usp_QueryAllProductsByName", conn);
    comm->CommandType = System::Data::CommandType::StoredProcedure;
    comm->Parameters->Add("@product_name", System::Data::SqlDbType::VarChar, 250);
    comm->Prepare();
    comm->Parameters["@product_name"]->Value = "";

    SqlDataReader^ reader = comm->ExecuteReader();

    List<Product^>^ list = gcnew List<Product^>();
    while (reader->Read()) {
        if (reader["name"] != nullptr) {
            Groceries^ s = gcnew Groceries();
            s->Id = Int32::Parse(reader["id"]->ToString());
            s->Name = reader["name"]->ToString();
            s->Description = reader["description"]->ToString();
            s->Price = Double::Parse(reader["price"]->ToString());
            s->StockTotal = Int32::Parse(reader["stockTotal"]->ToString());
            s->QuantitySold = Int32::Parse(reader["quantitySold"]->ToString());
            list->Add(s);
        }
        if (reader["brand"] != nullptr) {
            HealthCare^ s = gcnew HealthCare();
            s->Id = Int32::Parse(reader["id"]->ToString());
            s->Name = reader["name"]->ToString();
            s->Description = reader["description"]->ToString();
            s->Price = Double::Parse(reader["price"]->ToString());
            s->StockTotal = Int32::Parse(reader["stockTotal"]->ToString());
            s->Brand = reader["brand"]->ToString();
            s->QuantitySold = Int32::Parse(reader["quantitySold"]->ToString());
            list->Add(s);
        }
    }

    //IMPORTANTE Paso 4: Cerramos la conexión con la BD
    if (conn != nullptr) conn->Close();
    return list;
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
    List<Groceries^>^ list = gcnew List<Groceries^>();
    /*
    productDB->LoadFromBinaryFile();
    for (int i = 0; i < productDB->ListDB->Count; i++) {
        if (productDB->ListDB[i]->GetType() == Book::typeid && productDB->ListDB[i]->Status == 'A') {
            list->Add(dynamic_cast<Book^>(productDB->ListDB[i]));
        }
    }
    */
    /*Paso 1: Se obtiene la conexión */
    SqlConnection^ conn = GetConnection();

    /*Paso 2: Se prepara la sentencia */
    SqlCommand^ comm = gcnew SqlCommand("usp_QueryAllGroceries", conn);
    comm->CommandType = System::Data::CommandType::StoredProcedure;

    /*Paso 3: Se ejecuta la sentencia */
    SqlDataReader^ reader = comm->ExecuteReader();

    /*Paso 4: Se procesan los resultados */
    while (reader->Read()) {
        Groceries^ b = gcnew Groceries();
        b->Id = Int32::Parse(reader["id"]->ToString());
        b->Name = reader["name"]->ToString();
        b->Description = reader["description"]->ToString();
        b->Price = Double::Parse(reader["price"]->ToString());
        b->StockTotal = Int32::Parse(reader["stockTotal"]->ToString());
        b->Brand = reader["brand"]->ToString();
       
        list->Add(b);
    }
    /*Paso 5: Se cierran los objetos de conexión */
    if (reader != nullptr) reader->Close();
    if (conn != nullptr) conn->Close();

    return list;

}

List<HealthCare^>^ AppController::DBController::QueryAllHealthCare()
{
    List<HealthCare^>^ list = gcnew List<HealthCare^>();

    
    /*Paso 1: Se obtiene la conexión */
    SqlConnection^ conn = GetConnection();

    /*Paso 2: Se prepara la sentencia */
    SqlCommand^ comm = gcnew SqlCommand("usp_QueryAllHealthCare", conn);
    comm->CommandType = System::Data::CommandType::StoredProcedure;

    /*Paso 3: Se ejecuta la sentencia */
    SqlDataReader^ reader = comm->ExecuteReader();

    /*Paso 4: Se procesan los resultados */
    while (reader->Read()) {
        HealthCare^ b = gcnew HealthCare();
        b->Id = Int32::Parse(reader["id"]->ToString());
        b->Name = reader["name"]->ToString();
        b->Description = reader["description"]->ToString();
        b->Price = Double::Parse(reader["price"]->ToString());
        b->StockTotal = Int32::Parse(reader["stockTotal"]->ToString());

        b->Brand =reader["brand"]->ToString();

        list->Add(b);
    }
    /*Paso 5: Se cierran los objetos de conexión */
    if (reader != nullptr) reader->Close();
    if (conn != nullptr) conn->Close();

    return list;

}

int AppController::DBController::ReturnIDbyProductName(String^ name)
{
    /*for (int i = 0; i < productDB->ListDB->Count; i++)
        if (productDB->ListDB[i]->Name == name)
            return productDB->ListDB[i]->Id;*/

    int id;

    /* Paso 1: Se obtiene la conexión */
    SqlConnection^ conn = GetConnection();

    /* Paso 2: Se prepara la sentencia */
    SqlCommand^ comm = gcnew SqlCommand();
    comm->Connection = conn;
    comm->CommandText = "SELECT id FROM PRODUCT WHERE name='" + name + "'";

    /* Paso 3: Se ejecuta la sentencia */
    SqlDataReader^ dr = comm->ExecuteReader();

    /* Paso 4: Se procesan los resultados */
    if (dr->Read()) {
        id = (int)dr["id"];
    }

    /* Paso 5: Se cierra los objetos de conexión!!!!!!!!!! */
    if (dr != nullptr) dr->Close();
    if (conn != nullptr) conn->Close();
    return id;

}

Product^ AppController::DBController::QueryProductById(int productId)
{   //como lo tengo que buscar por id, tengo que hacer un for
    /*
    productDB->LoadFromBinaryFile();
    for (int i = 0; i < productDB->ListDB->Count; i++)
        if (productDB->ListDB[i]->Id == productId)
            return productDB->ListDB[i];
    return nullptr; // es un puntero a nulo
    */

    /* Paso 1: Se obtiene la conexión */
    SqlConnection^ conn = GetConnection();

    /* Paso 2:  Se prepara la sentencia */
    SqlCommand^ comm;
    String^ strCmd;
    strCmd = "SELECT * " +
        "FROM PRODUCT P " +
        "LEFT JOIN GROCERY_PRODUCT B ON B.id = P.id " +
        "LEFT JOIN HEALTHCARE_PRODUCT E ON E.id = P.id " +
        "WHERE P.id = @p1 AND " +
        "P.status = 'A'";
    comm = gcnew SqlCommand(strCmd, conn);
    SqlParameter^ p1 = gcnew SqlParameter("@p1", System::Data::SqlDbType::Int);
    p1->Value = productId;
    comm->Parameters->Add(p1);
    /* Paso 3: Se ejecuta la sentencia */
    SqlDataReader^ reader = comm->ExecuteReader();

    /* 4to paso: Se procesan los resultados */
    Product^ p;
    if (reader->Read()) {
        if (!DBNull::Value->Equals(reader["name"])) {
            Groceries^ s = gcnew Groceries();
            s->Id = Int32::Parse(reader["id"]->ToString());
            s->Name = reader["name"]->ToString();
            s->Description = reader["description"]->ToString();
            s->Price = Double::Parse(reader["price"]->ToString());
            s->StockTotal = Int32::Parse(reader["stockTotal"]->ToString());
            s->QuantitySold = Int32::Parse(reader["quantitySold"]->ToString());
            p = s;
        }
        if (!DBNull::Value->Equals(reader["brand"])) {
            HealthCare^ s = gcnew HealthCare();
            s->Id = Int32::Parse(reader["id"]->ToString());
            s->Name = reader["name"]->ToString();
            s->Description = reader["description"]->ToString();
            s->Price = Double::Parse(reader["price"]->ToString());
            s->StockTotal = Int32::Parse(reader["stockTotal"]->ToString());
            s->Brand = reader["brand"]->ToString();
            s->QuantitySold = Int32::Parse(reader["quantitySold"]->ToString());
            p = s;
        }
    }
    /* Paso 5: Se cierra la conexión */
    if (conn != nullptr) conn->Close();
    return p;
}

Groceries^ AppController::DBController::QueryGroceriesById(int productId)
{
    SqlConnection^ conn = GetConnection();

    /* 2do paso: Se prepara la sentencia */
    SqlCommand^ comm;

    comm = gcnew SqlCommand("usp_QueryGroceriesById", conn);
    comm->CommandType = System::Data::CommandType::StoredProcedure;
    comm->Parameters->Add("@id", System::Data::SqlDbType::Int);
    comm->Prepare();
    comm->Parameters["@id"]->Value = productId;

    /* 3er paso: Se ejecuta la sentencia */
    SqlDataReader^ reader = comm->ExecuteReader();

    /* 4to paso: Se procesa el resultado */
    Groceries^ s = nullptr;
    if (reader->Read()) {
        s = gcnew Groceries();
        if (!DBNull::Value->Equals(reader["id"]))
            s->Id = Int32::Parse(reader["id"]->ToString());
        if (!DBNull::Value->Equals(reader["name"]))
            s->Name = reader["name"]->ToString();
        if (!DBNull::Value->Equals(reader["description"]))
            s->Description = reader["description"]->ToString();
        if (!DBNull::Value->Equals(reader["price"]))
            s->Price = Double::Parse(reader["price"]->ToString());
        if (!DBNull::Value->Equals(reader["brand"]))
            s->Brand = reader["brand"]->ToString();
        if (!DBNull::Value->Equals(reader["stockTotal"]))
            s->StockTotal = Int32::Parse(reader["stockTotal"]->ToString());
        if (!DBNull::Value->Equals(reader["photo"]))
            s->Photo = (array<Byte>^)reader["photo"];
    }

    /* Paso 5: Cerramos la conexión con la BD */
    if (conn != nullptr)	conn->Close();
    return s;
}

HealthCare^ AppController::DBController::QueryHealthCareById(int productId)
{
    SqlConnection^ conn = GetConnection();

    /* 2do paso: Se prepara la sentencia */
    

    SqlCommand^  comm = gcnew SqlCommand("usp_QueryHealthCareById", conn);
    comm->CommandType = System::Data::CommandType::StoredProcedure;
    comm->Parameters->Add("@id", System::Data::SqlDbType::Int);
    comm->Prepare();
    comm->Parameters["@id"]->Value = productId;

    /* 3er paso: Se ejecuta la sentencia */
    SqlDataReader^ reader = comm->ExecuteReader();

    /* 4to paso: Se procesa el resultado */
    HealthCare^ s = nullptr;
    if (reader->Read()) {
        s = gcnew HealthCare();
        if (!DBNull::Value->Equals(reader["id"]))
            s->Id = Int32::Parse(reader["id"]->ToString());
        if (!DBNull::Value->Equals(reader["name"]))
            s->Name = reader["name"]->ToString();
        if (!DBNull::Value->Equals(reader["description"]))
            s->Description = reader["description"]->ToString();
        if (!DBNull::Value->Equals(reader["price"]))
            s->Price = Double::Parse(reader["price"]->ToString());
        if (!DBNull::Value->Equals(reader["brand"]))
            s->Brand = reader["brand"]->ToString();
        if (!DBNull::Value->Equals(reader["stockTotal"]))
            s->StockTotal = Int32::Parse(reader["stockTotal"]->ToString());
        if (!DBNull::Value->Equals(reader["photo"]))
            s->Photo = (array<Byte>^)reader["photo"];
    }

    /* Paso 5: Cerramos la conexión con la BD */
    if (conn != nullptr)	conn->Close();
    return s;
}

List<Groceries^>^ AppController::DBController::QueryAllGroceriesByCoincidence(String^ str)
{
    /*List<Groceries^>^ list = gcnew List<Groceries^>();
    return list; */

    /* 1er paso: Se obtiene la conexión */
    SqlConnection^ conn = GetConnection();

    /* 2do paso: Se prepara la sentencia */
    SqlCommand^ comm;

    String^ strCmd;
    strCmd = "dbo.usp_QueryAllGroceriesByCoincidence";
    comm = gcnew SqlCommand(strCmd, conn);
    comm->CommandType = System::Data::CommandType::StoredProcedure;
    comm->Parameters->Add("@data", System::Data::SqlDbType::VarChar, 250);
    comm->Prepare();
    comm->Parameters["@data"]->Value = str;

    /*3er paso: Se ejecuta la sentencia */
    SqlDataReader^ reader = comm->ExecuteReader();

    /*4to paso: Se procesan los resultados */
    List<Groceries^>^ list = gcnew List<Groceries^>();
    while (reader->Read()) {
        Groceries^ b = gcnew Groceries();
        b->Id = Int32::Parse(reader["id"]->ToString());
        b->Name = reader["name"]->ToString();
        b->Description = reader["description"]->ToString();
        b->Price = Double::Parse(reader["price"]->ToString());
        b->StockTotal = Int32::Parse(reader["stockTotal"]->ToString());
        b->QuantitySold = Int32::Parse(reader["quantitySold"]->ToString());

        list->Add(b);
    }

    /* 5to Paso: Cerramos la conexión con la BD */
    if (conn != nullptr)conn->Close();
    return list;
}

List<HealthCare^>^ AppController::DBController::QueryAllHealthCareByCoincidence(String^ str)
{
    /*List<HealthCare^>^ list = gcnew List<HealthCare^>();
    return list;*/

    /* 1er paso: Se obtiene la conexión */
    SqlConnection^ conn = GetConnection();

    /* 2do paso: Se prepara la sentencia */
    SqlCommand^ comm;

    comm = gcnew SqlCommand("usp_QueryAllHealthCareByCoincidence", conn);
    comm->CommandType = System::Data::CommandType::StoredProcedure;
    comm->Parameters->Add("@data", System::Data::SqlDbType::VarChar, 250);
    comm->Prepare();
    comm->Parameters["@data"]->Value = str;
    /* 3er paso: Se ejecuta la sentencia */
    SqlDataReader^ reader = comm->ExecuteReader();
    /* 4to paso: Se procesan los resultados */
    List<HealthCare^>^ list = gcnew List<HealthCare^>();
    while (reader->Read()) {
        HealthCare^ s = gcnew HealthCare();
        s->Id = Int32::Parse(reader["id"]->ToString());
        s->Name = reader["name"]->ToString();
        s->Description = reader["description"]->ToString();
        s->Price = Double::Parse(reader["price"]->ToString());
        s->StockTotal = Int32::Parse(reader["stock"]->ToString());
        s->Brand = reader["brand"]->ToString();
        s->QuantitySold = Int32::Parse(reader["quantitySold"]->ToString());

        list->Add(s);
    }

    /* 5to paso: Cerramos la conexión con la BD */
    if (conn != nullptr) conn->Close();
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

    /*saleDB->ListDB->Add(sale);
    saleDB->Persist();*/

    /* 1er paso: Se obtiene la conexión */
    SqlConnection^ conn = GetConnection();

    /* 2do paso: Se prepara la sentencia */
    SqlCommand^ comm;
    String^ strCmd;
    if (sale != nullptr) {
        strCmd = "dbo.usp_RegisterSale";
        comm = gcnew SqlCommand(strCmd, conn);
        comm->CommandType = System::Data::CommandType::StoredProcedure;
        comm->Parameters->Add("@status", System::Data::SqlDbType::Char, 1);
        comm->Parameters->Add("@date", System::Data::SqlDbType::Date);
        comm->Parameters->Add("@paymentType", System::Data::SqlDbType::Char,8);
        comm->Parameters->Add("@arrivalTime", System::Data::SqlDbType::Int);
        comm->Parameters->Add("@deliveryManRating", System::Data::SqlDbType::Int);
        comm->Parameters->Add("@customerRating", System::Data::SqlDbType::Int);
        comm->Parameters->Add("@ubication", System::Data::SqlDbType::VarChar, 25);
        comm->Parameters->Add("@total", System::Data::SqlDbType::Decimal, 10);
        comm->Parameters["@total"]->Precision = 10;
        comm->Parameters["@total"]->Scale = 2;
        comm->Parameters->Add("@customer_id", System::Data::SqlDbType::Int);
        comm->Parameters->Add("@deliveryMan_id", System::Data::SqlDbType::Int);

        SqlParameter^ outputIdParam = gcnew SqlParameter("@id", System::Data::SqlDbType::Int);
        outputIdParam->Direction = System::Data::ParameterDirection::Output;
        comm->Parameters->Add(outputIdParam);

        comm->Prepare();

        comm->Parameters["@status"]->Value = sale->Status == 'A' ? "A" : "I";
        comm->Parameters["@date"]->Value = sale->Date;
        comm->Parameters["@paymentType"]->Value = sale->PaymentType;
        comm->Parameters["@arrivalTime"]->Value = sale->ArrivalTime;
        comm->Parameters["@deliveryManRating"]->Value = sale->DeliveryManRating;
        comm->Parameters["@customerRating"]->Value = sale->CustomerRating;
        comm->Parameters["@ubication"]->Value = sale->Ubication;
        comm->Parameters["@total"]->Value = sale->Total;
        comm->Parameters["@customer_id"]->Value = sale->Customer->Id;
        comm->Parameters["@salesman_id"]->Value = sale->DeliveryMan->Id;

        /* 4to paso: Se ejecuta la sentencia */
        comm->ExecuteNonQuery();
        //Para leer el dato de salida
        int id_output = Convert::ToInt32(comm->Parameters["@id"]->Value);

        for (int i = 0; i < sale->Details->Count; i++) {
            strCmd = "dbo.usp_AddSaleDetail";
            comm = gcnew SqlCommand(strCmd, conn);
            comm->CommandType = System::Data::CommandType::StoredProcedure;
            comm->Parameters->Add("@order_id", System::Data::SqlDbType::Int);
            comm->Parameters->Add("@product_id", System::Data::SqlDbType::Int);
            comm->Parameters->Add("@quantity", System::Data::SqlDbType::Int);
            comm->Parameters->Add("@unit_price", System::Data::SqlDbType::Decimal, 10);
            comm->Parameters["@unit_price"]->Precision = 10;
            comm->Parameters["@unit_price"]->Scale = 2;
            comm->Parameters->Add("@subtotal", System::Data::SqlDbType::Decimal, 10);
            comm->Parameters["@subtotal"]->Precision = 10;
            comm->Parameters["@subtotal"]->Scale = 2;
            comm->Parameters->Add("@total", System::Data::SqlDbType::Decimal, 10);
            comm->Parameters["@total"]->Precision = 10;
            comm->Parameters["@total"]->Scale = 2;
            //comm->Parameters->Add("@status", System::Data::SqlDbType::Char, 1);
            SqlParameter^ outputIdParam = gcnew SqlParameter("@id", System::Data::SqlDbType::Int);
            outputIdParam->Direction = System::Data::ParameterDirection::Output;
            comm->Parameters->Add(outputIdParam);

            comm->Prepare();

            comm->Parameters["@order_id"]->Value = id_output;
            comm->Parameters["@product_id"]->Value = sale->Details[i]->Product->Id;
            comm->Parameters["@quantity"]->Value = sale->Details[i]->Quantity;
            comm->Parameters["@unit_price"]->Value = sale->Details[i]->UnitPrice;
            comm->Parameters["@subtotal"]->Value = sale->Details[i]->SubTotal;
            comm->Parameters["@total"]->Value = sale->Details[i]->Total;

            /* 4to paso: Se ejecuta la sentencia */
            comm->ExecuteNonQuery();
        }
    }

    /* 5to Paso: Cerramos la conexión con la BD */
    if (conn != nullptr) conn->Close();
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
    //comm->Parameters->Add("@iid", System::Data::SqlDbType::Int);

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
    comm->Parameters["@iid"]->Value = user->Id;;


    //Paso 3: Se ejecuta la sentencia
    comm->ExecuteNonQuery();

    //Paso 4: Si se quiere procesar la salida.
    int output_id = Convert::ToInt32(comm->Parameters["@iid"]->Value);

    //Paso 5: Se cierra la conexión
    if (conn != nullptr) conn->Close();

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
    /*
    userDB->LoadUsers();
    for (int i = 0; i < userDB->ListDB->Count; i++)
        if (userDB->ListDB[i]->Id == userId &&
            userDB->ListDB[i]->GetType() == User::typeid)
            return (User^)userDB->ListDB[i];
    return nullptr;
    */

    /* 1er paso: Se obtiene la conexión */
    SqlConnection^ conn = GetConnection();

    /* 2do paso: Se prepara la sentencia */
    SqlCommand^ comm;

    comm = gcnew SqlCommand("usp_QueryUserById", conn);
    comm->CommandType = System::Data::CommandType::StoredProcedure;
    comm->Parameters->Add("@id", System::Data::SqlDbType::Int);
    comm->Prepare();
    comm->Parameters["@id"]->Value = userId;

    /* 3er paso: Se ejecuta la sentencia */
    SqlDataReader^ reader = comm->ExecuteReader();

    /* 4to paso: Se procesan los resultados */
    User^ s;
    if (reader->Read()) {
        s = gcnew User();
        s->Id = Int32::Parse(reader["id"]->ToString());
        s->Username = reader["username"]->ToString();
        s->FirstName = reader["first_name"]->ToString();
        s->LastName = reader["last_name"]->ToString();
        s->Gender = reader["gender"]->ToString()[0];
        s->Email = safe_cast<String^> (reader["email"]);
        s->DocumentNumber = safe_cast<String^> (reader["document_number"]);
        s->Address = safe_cast<String^> (reader["address"]);
        s->PhoneNumber = safe_cast<String^> (reader["phone_number"]);
    }

    /* IMPORTANTE 5to paso: Cerramos la conexión con la BD */
    if (conn != nullptr) conn->Close();
    return s;
}

int AppController::DBController::ReturnIDbyUserName(String^ username)
{
    int id;
    //userDB->LoadUsers();
    //for (int i = 0; i < userDB->ListDB->Count; i++)
      //  if (userDB->ListDB[i]->Username->Equals(username))
        //    return userDB->ListDB[i]->Id;


    /* Paso 1: Se obtiene la conexión */
    SqlConnection^ conn = GetConnection();

    /* Paso 2: Se prepara la sentencia */
    SqlCommand^ comm = gcnew SqlCommand();
    comm->Connection = conn;
    comm->CommandText = "SELECT id FROM app_user WHERE username='" + username + "'";

    /* Paso 3: Se ejecuta la sentencia */
    SqlDataReader^ dr = comm->ExecuteReader();

    /* Paso 4: Se procesan los resultados */
    if (dr->Read()) {
        id = (int)dr["id"];
    }

    /* Paso 5: Se cierra los objetos de conexión!!!!!!!!!! */
    if (dr != nullptr) dr->Close();
    if (conn != nullptr) conn->Close();
    return id;
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
    //productDB->Persist();
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