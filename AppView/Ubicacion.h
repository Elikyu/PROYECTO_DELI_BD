#pragma once
#include "CarritoCustomerForm.h"
namespace AppView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AppController;
	using namespace AppModel;

	/// <summary>
	/// Resumen de Ubicacion
	/// </summary>
	public ref class Ubicacion : public System::Windows::Forms::Form
	{
		String^ Address;
	public:
		Ubicacion(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Ubicacion()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::CheckBox^ chckAddress;
	protected:
	public: System::Windows::Forms::CheckBox^ chckCustomAddress;

	protected:


	protected:


	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ btnAddressCheck_Click;
	public: System::Windows::Forms::TextBox^ txtCustomAddressC;
	public: System::Windows::Forms::TextBox^ txtArrivalTimeC;
	private:


	public: System::Windows::Forms::TextBox^ txtAddressC;
	public: System::Windows::Forms::TextBox^ txtUSER;

	private:



	private:





	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Ubicacion::typeid));
			this->chckAddress = (gcnew System::Windows::Forms::CheckBox());
			this->chckCustomAddress = (gcnew System::Windows::Forms::CheckBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->btnAddressCheck_Click = (gcnew System::Windows::Forms::Button());
			this->txtCustomAddressC = (gcnew System::Windows::Forms::TextBox());
			this->txtArrivalTimeC = (gcnew System::Windows::Forms::TextBox());
			this->txtAddressC = (gcnew System::Windows::Forms::TextBox());
			this->txtUSER = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// chckAddress
			// 
			this->chckAddress->AutoSize = true;
			this->chckAddress->Location = System::Drawing::Point(9, 9);
			this->chckAddress->Margin = System::Windows::Forms::Padding(2);
			this->chckAddress->Name = L"chckAddress";
			this->chckAddress->Size = System::Drawing::Size(63, 17);
			this->chckAddress->TabIndex = 0;
			this->chckAddress->Text = L"Mi casa";
			this->chckAddress->UseVisualStyleBackColor = true;
			this->chckAddress->CheckedChanged += gcnew System::EventHandler(this, &Ubicacion::chckAddress_CheckedChanged);
			// 
			// chckCustomAddress
			// 
			this->chckCustomAddress->AutoSize = true;
			this->chckCustomAddress->Location = System::Drawing::Point(9, 41);
			this->chckCustomAddress->Margin = System::Windows::Forms::Padding(2);
			this->chckCustomAddress->Name = L"chckCustomAddress";
			this->chckCustomAddress->Size = System::Drawing::Size(167, 17);
			this->chckCustomAddress->TabIndex = 2;
			this->chckCustomAddress->Text = L"Agregar ubicacion en el mapa";
			this->chckCustomAddress->UseVisualStyleBackColor = true;
			this->chckCustomAddress->CheckedChanged += gcnew System::EventHandler(this, &Ubicacion::chckCustomAddress_CheckedChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(13, 59);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(467, 227);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(55, 314);
			this->label3->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(142, 13);
			this->label3->TabIndex = 5;
			this->label3->Text = L"Tiempo estimado de llegada:";
			this->label3->Click += gcnew System::EventHandler(this, &Ubicacion::label3_Click);
			// 
			// btnAddressCheck_Click
			// 
			this->btnAddressCheck_Click->BackColor = System::Drawing::SystemColors::ControlDarkDark;
			this->btnAddressCheck_Click->ForeColor = System::Drawing::Color::Black;
			this->btnAddressCheck_Click->Location = System::Drawing::Point(312, 344);
			this->btnAddressCheck_Click->Margin = System::Windows::Forms::Padding(2);
			this->btnAddressCheck_Click->Name = L"btnAddressCheck_Click";
			this->btnAddressCheck_Click->Size = System::Drawing::Size(83, 27);
			this->btnAddressCheck_Click->TabIndex = 7;
			this->btnAddressCheck_Click->Text = L"Confirmar";
			this->btnAddressCheck_Click->UseVisualStyleBackColor = false;
			this->btnAddressCheck_Click->Click += gcnew System::EventHandler(this, &Ubicacion::btnAddressCheck_Click_Click);
			// 
			// txtCustomAddressC
			// 
			this->txtCustomAddressC->Location = System::Drawing::Point(246, 288);
			this->txtCustomAddressC->Margin = System::Windows::Forms::Padding(2);
			this->txtCustomAddressC->Name = L"txtCustomAddressC";
			this->txtCustomAddressC->Size = System::Drawing::Size(174, 20);
			this->txtCustomAddressC->TabIndex = 8;
			this->txtCustomAddressC->Text = L"Escribir  Direccion";
			this->txtCustomAddressC->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Ubicacion::txtCustomAddressC_KeyDown);
			// 
			// txtArrivalTimeC
			// 
			this->txtArrivalTimeC->Location = System::Drawing::Point(246, 312);
			this->txtArrivalTimeC->Margin = System::Windows::Forms::Padding(2);
			this->txtArrivalTimeC->Name = L"txtArrivalTimeC";
			this->txtArrivalTimeC->ReadOnly = true;
			this->txtArrivalTimeC->Size = System::Drawing::Size(174, 20);
			this->txtArrivalTimeC->TabIndex = 9;
			this->txtArrivalTimeC->TextChanged += gcnew System::EventHandler(this, &Ubicacion::txtArrivalTimeC_TextChanged);
			// 
			// txtAddressC
			// 
			this->txtAddressC->Location = System::Drawing::Point(205, 7);
			this->txtAddressC->Margin = System::Windows::Forms::Padding(2);
			this->txtAddressC->Name = L"txtAddressC";
			this->txtAddressC->ReadOnly = true;
			this->txtAddressC->Size = System::Drawing::Size(275, 20);
			this->txtAddressC->TabIndex = 10;
			this->txtAddressC->TextChanged += gcnew System::EventHandler(this, &Ubicacion::txtAddressC_TextChanged);
			// 
			// txtUSER
			// 
			this->txtUSER->Location = System::Drawing::Point(631, 12);
			this->txtUSER->Name = L"txtUSER";
			this->txtUSER->ReadOnly = true;
			this->txtUSER->Size = System::Drawing::Size(25, 20);
			this->txtUSER->TabIndex = 11;
			// 
			// Ubicacion
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::InactiveCaption;
			this->ClientSize = System::Drawing::Size(494, 370);
			this->Controls->Add(this->txtUSER);
			this->Controls->Add(this->txtAddressC);
			this->Controls->Add(this->txtArrivalTimeC);
			this->Controls->Add(this->txtCustomAddressC);
			this->Controls->Add(this->btnAddressCheck_Click);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->chckCustomAddress);
			this->Controls->Add(this->chckAddress);
			this->Margin = System::Windows::Forms::Padding(2);
			this->Name = L"Ubicacion";
			this->Text = L"Ubicacion";
			this->Load += gcnew System::EventHandler(this, &Ubicacion::Ubicacion_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	/*private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}

private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
}*/
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void btnAddressCheck_Click_Click(System::Object^ sender, System::EventArgs^ e);

private: System::Void txtCustomAddressC_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	if (e->KeyData == Keys::Enter)
	{
		txtArrivalTimeC->Text = AppController::DBController::CompareAdress(txtCustomAddressC->Text);

	}
}
private: System::Void chckAddress_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (chckAddress->Checked == true) {
		chckCustomAddress->Enabled = false;
		Address = txtAddressC->Text;
		txtCustomAddressC->Enabled = false;
		txtArrivalTimeC->Text = AppController::DBController::CompareAdress(txtAddressC->Text);
	}
	else {
		chckCustomAddress->Enabled = true;
	}
}
private: System::Void chckCustomAddress_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
	if (chckCustomAddress->Checked == true) {
		chckAddress->Enabled = false;
		Address = txtCustomAddressC->Text;
		txtCustomAddressC->Enabled = true;
	}
	else {
		chckAddress->Enabled = true;
		txtCustomAddressC->Enabled = false;
	}
}
private: System::Void txtAddressC_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	//if (chckAddress->Checked == true)

		//txtAddressC->Text = AppModel::User::Address;
}
private: System::Void Ubicacion_Load(System::Object^ sender, System::EventArgs^ e) {
	txtCustomAddressC->Enabled = false;
}
private: System::Void txtArrivalTimeC_TextChanged(System::Object^ sender, System::EventArgs^ e) {

}
};
}
