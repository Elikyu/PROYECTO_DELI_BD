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
	/// Resumen de CustomerRatingForm
	/// </summary>
	public ref class CustomerRatingForm : public System::Windows::Forms::Form
	{
	public:
		CustomerRatingForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar c�digo de constructor aqu�
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se est�n usando.
		/// </summary>
		~CustomerRatingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btnFinalize;
	private: System::Windows::Forms::TextBox^ txtCustomerRating;
	protected:

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtCustomerName;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pbZeroStars;
	private: System::Windows::Forms::PictureBox^ pbOneStar;
	private: System::Windows::Forms::PictureBox^ pbTwoStars;
	private: System::Windows::Forms::PictureBox^ pbThreeStars;
	private: System::Windows::Forms::PictureBox^ pbFourStars;
	private: System::Windows::Forms::PictureBox^ pbFiveStars;
	private: System::Windows::Forms::Label^ label5;
	public: System::Windows::Forms::TextBox^ txtIdSale;
	private:

	private:
		/// <summary>
		/// Variable del dise�ador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// M�todo necesario para admitir el Dise�ador. No se puede modificar
		/// el contenido de este m�todo con el editor de c�digo.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(CustomerRatingForm::typeid));
			this->btnFinalize = (gcnew System::Windows::Forms::Button());
			this->txtCustomerRating = (gcnew System::Windows::Forms::TextBox());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtCustomerName = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pbZeroStars = (gcnew System::Windows::Forms::PictureBox());
			this->pbOneStar = (gcnew System::Windows::Forms::PictureBox());
			this->pbTwoStars = (gcnew System::Windows::Forms::PictureBox());
			this->pbThreeStars = (gcnew System::Windows::Forms::PictureBox());
			this->pbFourStars = (gcnew System::Windows::Forms::PictureBox());
			this->pbFiveStars = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->txtIdSale = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbZeroStars))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbOneStar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTwoStars))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbThreeStars))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFourStars))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFiveStars))->BeginInit();
			this->SuspendLayout();
			// 
			// btnFinalize
			// 
			this->btnFinalize->Location = System::Drawing::Point(392, 255);
			this->btnFinalize->Name = L"btnFinalize";
			this->btnFinalize->Size = System::Drawing::Size(75, 23);
			this->btnFinalize->TabIndex = 24;
			this->btnFinalize->Text = L"Finalizar";
			this->btnFinalize->UseVisualStyleBackColor = true;
			this->btnFinalize->Click += gcnew System::EventHandler(this, &CustomerRatingForm::btnFinalize_Click);
			// 
			// txtCustomerRating
			// 
			this->txtCustomerRating->Location = System::Drawing::Point(367, 198);
			this->txtCustomerRating->Name = L"txtCustomerRating";
			this->txtCustomerRating->Size = System::Drawing::Size(100, 20);
			this->txtCustomerRating->TabIndex = 23;
			this->txtCustomerRating->TextChanged += gcnew System::EventHandler(this, &CustomerRatingForm::txtCustomerRating_TextChanged);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(26, 201);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(338, 91);
			this->label4->TabIndex = 22;
			this->label4->Text = L"Estimado repartidor, califique el trato del cliente hacia usted del 1 al 5: \r\nDon"
				L"de \r\n(1) Totalmente insatisfecho\r\n(2) Insatisfecho\r\n(3) Neutral\r\n(4) Satisfecho\r"
				L"\n(5) Totalmente satisfecho";
			// 
			// txtCustomerName
			// 
			this->txtCustomerName->Location = System::Drawing::Point(140, 72);
			this->txtCustomerName->Name = L"txtCustomerName";
			this->txtCustomerName->Size = System::Drawing::Size(327, 20);
			this->txtCustomerName->TabIndex = 21;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 97);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 13);
			this->label3->TabIndex = 19;
			this->label3->Text = L"Puntuaci�n:";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 72);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(95, 13);
			this->label2->TabIndex = 20;
			this->label2->Text = L"Nombre del cliente";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(123, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(250, 24);
			this->label1->TabIndex = 18;
			this->label1->Text = L"CALIFICACI�N AL CLIENTE";
			// 
			// pbZeroStars
			// 
			this->pbZeroStars->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbZeroStars.Image")));
			this->pbZeroStars->Location = System::Drawing::Point(85, 116);
			this->pbZeroStars->Name = L"pbZeroStars";
			this->pbZeroStars->Size = System::Drawing::Size(297, 70);
			this->pbZeroStars->TabIndex = 17;
			this->pbZeroStars->TabStop = false;
			// 
			// pbOneStar
			// 
			this->pbOneStar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbOneStar.Image")));
			this->pbOneStar->Location = System::Drawing::Point(85, 116);
			this->pbOneStar->Name = L"pbOneStar";
			this->pbOneStar->Size = System::Drawing::Size(297, 70);
			this->pbOneStar->TabIndex = 16;
			this->pbOneStar->TabStop = false;
			// 
			// pbTwoStars
			// 
			this->pbTwoStars->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbTwoStars.Image")));
			this->pbTwoStars->Location = System::Drawing::Point(85, 116);
			this->pbTwoStars->Name = L"pbTwoStars";
			this->pbTwoStars->Size = System::Drawing::Size(297, 70);
			this->pbTwoStars->TabIndex = 15;
			this->pbTwoStars->TabStop = false;
			// 
			// pbThreeStars
			// 
			this->pbThreeStars->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbThreeStars.Image")));
			this->pbThreeStars->Location = System::Drawing::Point(85, 116);
			this->pbThreeStars->Name = L"pbThreeStars";
			this->pbThreeStars->Size = System::Drawing::Size(297, 70);
			this->pbThreeStars->TabIndex = 14;
			this->pbThreeStars->TabStop = false;
			// 
			// pbFourStars
			// 
			this->pbFourStars->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbFourStars.Image")));
			this->pbFourStars->Location = System::Drawing::Point(85, 116);
			this->pbFourStars->Name = L"pbFourStars";
			this->pbFourStars->Size = System::Drawing::Size(297, 70);
			this->pbFourStars->TabIndex = 13;
			this->pbFourStars->TabStop = false;
			// 
			// pbFiveStars
			// 
			this->pbFiveStars->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbFiveStars.Image")));
			this->pbFiveStars->Location = System::Drawing::Point(85, 116);
			this->pbFiveStars->Name = L"pbFiveStars";
			this->pbFiveStars->Size = System::Drawing::Size(297, 70);
			this->pbFiveStars->TabIndex = 12;
			this->pbFiveStars->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(26, 47);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 13);
			this->label5->TabIndex = 26;
			this->label5->Text = L"Id. venta";
			// 
			// txtIdSale
			// 
			this->txtIdSale->Location = System::Drawing::Point(142, 47);
			this->txtIdSale->Name = L"txtIdSale";
			this->txtIdSale->Size = System::Drawing::Size(38, 20);
			this->txtIdSale->TabIndex = 25;
			// 
			// CustomerRatingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(484, 308);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtIdSale);
			this->Controls->Add(this->btnFinalize);
			this->Controls->Add(this->txtCustomerRating);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtCustomerName);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pbZeroStars);
			this->Controls->Add(this->pbOneStar);
			this->Controls->Add(this->pbTwoStars);
			this->Controls->Add(this->pbThreeStars);
			this->Controls->Add(this->pbFourStars);
			this->Controls->Add(this->pbFiveStars);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"CustomerRatingForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"CustomerRatingForm";
			this->Load += gcnew System::EventHandler(this, &CustomerRatingForm::CustomerRatingForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbZeroStars))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbOneStar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTwoStars))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbThreeStars))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFourStars))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFiveStars))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void CustomerRatingForm_Load(System::Object^ sender, System::EventArgs^ e) {
		Refreshpage();
	}
		   void Refreshpage() {
			   int idsale = Int32::Parse(txtIdSale->Text);
			   Order^ order = AppManager::QueryOrderbyId(idsale);
			   txtCustomerName->Text = order->User->FirstName + " " + order->User->LastName;

		   }
private: System::Void txtCustomerRating_TextChanged(System::Object^ sender, System::EventArgs^ e) {

	if (txtCustomerRating->Text->CompareTo("") == 0) {
		pbZeroStars->Visible = true;
		pbOneStar->Visible = false; pbTwoStars->Visible = false; pbThreeStars->Visible = false;
		pbFourStars->Visible = false;   pbFiveStars->Visible = false;
	}
	else if (Int32::Parse(txtCustomerRating->Text) == 1 |
		Int32::Parse(txtCustomerRating->Text) == 2 |
		Int32::Parse(txtCustomerRating->Text) == 3 |
		Int32::Parse(txtCustomerRating->Text) == 4 |
		Int32::Parse(txtCustomerRating->Text) == 5) {
		switch (Int32::Parse(txtCustomerRating->Text)) {

		case 1:
			pbZeroStars->Visible = false;
			pbOneStar->Visible = true; pbTwoStars->Visible = false; pbThreeStars->Visible = false;
			pbFourStars->Visible = false;   pbFiveStars->Visible = false;
			break;
		case 2:
			pbZeroStars->Visible = false;
			pbOneStar->Visible = false; pbTwoStars->Visible = true; pbThreeStars->Visible = false;
			pbFourStars->Visible = false;   pbFiveStars->Visible = false;
			break;
		case 3:
			pbZeroStars->Visible = false;
			pbOneStar->Visible = false; pbTwoStars->Visible = false; pbThreeStars->Visible = true;
			pbFourStars->Visible = false;   pbFiveStars->Visible = false;
			break;
		case 4:
			pbZeroStars->Visible = false;
			pbOneStar->Visible = false; pbTwoStars->Visible = false; pbThreeStars->Visible = false;
			pbFourStars->Visible = true;   pbFiveStars->Visible = false;
			break;
		case 5:
			pbZeroStars->Visible = false;
			pbOneStar->Visible = false; pbTwoStars->Visible = false; pbThreeStars->Visible = false;
			pbFourStars->Visible = false;   pbFiveStars->Visible = true;
			break;

		default:
			pbZeroStars->Visible = true;
			pbOneStar->Visible = false; pbTwoStars->Visible = false; pbThreeStars->Visible = false;
			pbFourStars->Visible = false;   pbFiveStars->Visible = false;
		}
	}
	else MessageBox::Show("Ingrese un numero dentro del rango");
}
private: System::Void btnFinalize_Click(System::Object^ sender, System::EventArgs^ e) {

	if (Int32::Parse(txtCustomerRating->Text) == 1 |
		Int32::Parse(txtCustomerRating->Text) == 2 |
		Int32::Parse(txtCustomerRating->Text) == 3 |
		Int32::Parse(txtCustomerRating->Text) == 4 |
		Int32::Parse(txtCustomerRating->Text) == 5) {
		int idsale = Int32::Parse(txtIdSale->Text);
		Order^ order = AppManager::QueryOrderbyId(idsale);
		order->CustomerRating = Int32::Parse(txtCustomerRating->Text);
		
		AppManager::UpdateCustomerQualification(order);

		this->Close();

		
		

	}
	else {
		MessageBox::Show("Ingrese un valor entero");
	}
}
};
}
