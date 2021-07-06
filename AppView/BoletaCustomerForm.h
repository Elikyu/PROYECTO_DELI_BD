#pragma once

namespace AppView {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace AppModel;
	using namespace AppController;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Resumen de BoletaCustomerForm
	/// </summary>
	public ref class BoletaCustomerForm : public System::Windows::Forms::Form
	{
	public:
		BoletaCustomerForm(void)
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
		~BoletaCustomerForm()
		{
			if (components)
			{
				delete components;
			}
		}
	public: System::Windows::Forms::TextBox^ txtIdSale;
	private: System::Windows::Forms::Label^ label1;
	public:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	public: System::Windows::Forms::TextBox^ txtPaymentType;
	private:

	public: System::Windows::Forms::TextBox^ textDateTimeB;
	public: System::Windows::Forms::TextBox^ txtDocumentNumber;
	public: System::Windows::Forms::TextBox^ txtTotal;
	private: System::Windows::Forms::DataGridView^ dgvBoletaCustomer;
	public:

	public:
	private:




	public:
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	public: System::Windows::Forms::TextBox^ txtUser;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Id;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Name;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Quantity;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ PrecioUnitario;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Importe;
	private: System::Windows::Forms::Label^ label5;
	public:
	private:

	private:
	protected:

	protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(BoletaCustomerForm::typeid));
			this->txtIdSale = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtPaymentType = (gcnew System::Windows::Forms::TextBox());
			this->textDateTimeB = (gcnew System::Windows::Forms::TextBox());
			this->txtDocumentNumber = (gcnew System::Windows::Forms::TextBox());
			this->txtTotal = (gcnew System::Windows::Forms::TextBox());
			this->dgvBoletaCustomer = (gcnew System::Windows::Forms::DataGridView());
			this->Id = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Name = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Quantity = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->PrecioUnitario = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Importe = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->txtUser = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBoletaCustomer))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// txtIdSale
			// 
			this->txtIdSale->Location = System::Drawing::Point(400, 42);
			this->txtIdSale->Name = L"txtIdSale";
			this->txtIdSale->ReadOnly = true;
			this->txtIdSale->Size = System::Drawing::Size(100, 20);
			this->txtIdSale->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ForeColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(52, 83);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(95, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Nombre del cliente";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->ForeColor = System::Drawing::Color::Transparent;
			this->label2->Location = System::Drawing::Point(22, 348);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(70, 13);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Tipo de pago";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->ForeColor = System::Drawing::Color::Transparent;
			this->label3->Location = System::Drawing::Point(302, 86);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(92, 13);
			this->label3->TabIndex = 3;
			this->label3->Text = L"No de documento";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->ForeColor = System::Drawing::Color::Transparent;
			this->label4->Location = System::Drawing::Point(397, 299);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(31, 13);
			this->label4->TabIndex = 4;
			this->label4->Text = L"Total";
			// 
			// txtPaymentType
			// 
			this->txtPaymentType->Location = System::Drawing::Point(98, 348);
			this->txtPaymentType->Name = L"txtPaymentType";
			this->txtPaymentType->ReadOnly = true;
			this->txtPaymentType->Size = System::Drawing::Size(100, 20);
			this->txtPaymentType->TabIndex = 5;
			// 
			// textDateTimeB
			// 
			this->textDateTimeB->Location = System::Drawing::Point(25, 314);
			this->textDateTimeB->Name = L"textDateTimeB";
			this->textDateTimeB->ReadOnly = true;
			this->textDateTimeB->Size = System::Drawing::Size(173, 20);
			this->textDateTimeB->TabIndex = 6;
			// 
			// txtDocumentNumber
			// 
			this->txtDocumentNumber->Location = System::Drawing::Point(400, 83);
			this->txtDocumentNumber->Name = L"txtDocumentNumber";
			this->txtDocumentNumber->ReadOnly = true;
			this->txtDocumentNumber->Size = System::Drawing::Size(100, 20);
			this->txtDocumentNumber->TabIndex = 7;
			// 
			// txtTotal
			// 
			this->txtTotal->Location = System::Drawing::Point(467, 296);
			this->txtTotal->Name = L"txtTotal";
			this->txtTotal->ReadOnly = true;
			this->txtTotal->Size = System::Drawing::Size(79, 20);
			this->txtTotal->TabIndex = 8;
			// 
			// dgvBoletaCustomer
			// 
			this->dgvBoletaCustomer->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvBoletaCustomer->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				this->Id,
					this->Name, this->Quantity, this->PrecioUnitario, this->Importe
			});
			this->dgvBoletaCustomer->Location = System::Drawing::Point(25, 119);
			this->dgvBoletaCustomer->Name = L"dgvBoletaCustomer";
			this->dgvBoletaCustomer->Size = System::Drawing::Size(518, 150);
			this->dgvBoletaCustomer->TabIndex = 9;
			// 
			// Id
			// 
			this->Id->HeaderText = L"Id";
			this->Id->Name = L"Id";
			// 
			// Name
			// 
			this->Name->HeaderText = L"Nombre del Producto";
			this->Name->Name = L"Name";
			// 
			// Quantity
			// 
			this->Quantity->HeaderText = L"Cantidad";
			this->Quantity->Name = L"Quantity";
			// 
			// PrecioUnitario
			// 
			this->PrecioUnitario->HeaderText = L"Precio Uni.";
			this->PrecioUnitario->Name = L"PrecioUnitario";
			// 
			// Importe
			// 
			this->Importe->HeaderText = L"Importe";
			this->Importe->Name = L"Importe";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(25, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(80, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 10;
			this->pictureBox1->TabStop = false;
			// 
			// txtUser
			// 
			this->txtUser->Location = System::Drawing::Point(153, 83);
			this->txtUser->Name = L"txtUser";
			this->txtUser->ReadOnly = true;
			this->txtUser->Size = System::Drawing::Size(100, 20);
			this->txtUser->TabIndex = 11;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->ForeColor = System::Drawing::Color::Transparent;
			this->label5->Location = System::Drawing::Point(302, 42);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(61, 13);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Id de venta";
			// 
			// BoletaCustomerForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(37)), static_cast<System::Int32>(static_cast<System::Byte>(31)),
				static_cast<System::Int32>(static_cast<System::Byte>(33)));
			this->ClientSize = System::Drawing::Size(581, 433);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtUser);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->dgvBoletaCustomer);
			this->Controls->Add(this->txtTotal);
			this->Controls->Add(this->txtDocumentNumber);
			this->Controls->Add(this->textDateTimeB);
			this->Controls->Add(this->txtPaymentType);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->txtIdSale);

			this->Text = L"BoletaCustomerForm";
			this->Load += gcnew System::EventHandler(this, &BoletaCustomerForm::BoletaCustomerForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvBoletaCustomer))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void BoletaCustomerForm_Load(System::Object^ sender, System::EventArgs^ e) {
		RefreshForm();
	}
		   void RefreshForm() {
			   int idsale = Int32::Parse(txtIdSale->Text);
			   Order^ order = AppManager::QueryOrderbyId(idsale);
			   txtUser->Text = order->User->FirstName + " " + order->User->LastName;
			   txtDocumentNumber->Text = order->User->DocumentNumber;
			   textDateTimeB->Text = order->Date;
			   txtTotal->Text =  "" + order->Total;
			   txtPaymentType->Text = "Tarjeta";
			   

			   //txtTotal->Text=
			   dgvBoletaCustomer->Rows->Clear();
			   for (int i = 0; i < order->Details->Count; i++) {
				   dgvBoletaCustomer->Rows->Add(gcnew array<String^>{
					   "" + order->Details[i]->Product->Id,
						   "" + order->Details[i]->Product->Name,
						   "" + order->Details[i]->Quantity,
						   "" + order->Details[i]->UnitPrice,
						   "" + order->Details[i]->SubTotal

				   });

			   }
		   }
		 
};
}
