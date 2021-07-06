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
	/// Resumen de DeliverymanRatingForm
	/// </summary>
	public ref class DeliverymanRatingForm : public System::Windows::Forms::Form
	{
	public:
		DeliverymanRatingForm(void)
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
		~DeliverymanRatingForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pbFiveStars;
	protected:

	private: System::Windows::Forms::PictureBox^ pbFourStars;

	private: System::Windows::Forms::PictureBox^ pbThreeStars;
	private: System::Windows::Forms::PictureBox^ pbTwoStars;



	private: System::Windows::Forms::PictureBox^ pbOneStar;

	private: System::Windows::Forms::PictureBox^ pbZeroStars;


	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ txtDeliverymanName;

	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::TextBox^ txtDeliverymanRating;

	private: System::Windows::Forms::Button^ btnFinalize;
	public: System::Windows::Forms::TextBox^ txtIdSale;
	private: System::Windows::Forms::Label^ label5;

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(DeliverymanRatingForm::typeid));
			this->pbFiveStars = (gcnew System::Windows::Forms::PictureBox());
			this->pbFourStars = (gcnew System::Windows::Forms::PictureBox());
			this->pbThreeStars = (gcnew System::Windows::Forms::PictureBox());
			this->pbTwoStars = (gcnew System::Windows::Forms::PictureBox());
			this->pbOneStar = (gcnew System::Windows::Forms::PictureBox());
			this->pbZeroStars = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->txtDeliverymanName = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->txtDeliverymanRating = (gcnew System::Windows::Forms::TextBox());
			this->btnFinalize = (gcnew System::Windows::Forms::Button());
			this->txtIdSale = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFiveStars))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFourStars))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbThreeStars))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTwoStars))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbOneStar))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbZeroStars))->BeginInit();
			this->SuspendLayout();
			// 
			// pbFiveStars
			// 
			this->pbFiveStars->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbFiveStars.Image")));
			this->pbFiveStars->Location = System::Drawing::Point(85, 116);
			this->pbFiveStars->Name = L"pbFiveStars";
			this->pbFiveStars->Size = System::Drawing::Size(297, 70);
			this->pbFiveStars->TabIndex = 0;
			this->pbFiveStars->TabStop = false;
			// 
			// pbFourStars
			// 
			this->pbFourStars->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbFourStars.Image")));
			this->pbFourStars->Location = System::Drawing::Point(85, 116);
			this->pbFourStars->Name = L"pbFourStars";
			this->pbFourStars->Size = System::Drawing::Size(297, 70);
			this->pbFourStars->TabIndex = 1;
			this->pbFourStars->TabStop = false;
			// 
			// pbThreeStars
			// 
			this->pbThreeStars->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbThreeStars.Image")));
			this->pbThreeStars->Location = System::Drawing::Point(85, 116);
			this->pbThreeStars->Name = L"pbThreeStars";
			this->pbThreeStars->Size = System::Drawing::Size(297, 70);
			this->pbThreeStars->TabIndex = 2;
			this->pbThreeStars->TabStop = false;
			// 
			// pbTwoStars
			// 
			this->pbTwoStars->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbTwoStars.Image")));
			this->pbTwoStars->Location = System::Drawing::Point(85, 116);
			this->pbTwoStars->Name = L"pbTwoStars";
			this->pbTwoStars->Size = System::Drawing::Size(297, 70);
			this->pbTwoStars->TabIndex = 3;
			this->pbTwoStars->TabStop = false;
			// 
			// pbOneStar
			// 
			this->pbOneStar->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbOneStar.Image")));
			this->pbOneStar->Location = System::Drawing::Point(85, 116);
			this->pbOneStar->Name = L"pbOneStar";
			this->pbOneStar->Size = System::Drawing::Size(297, 70);
			this->pbOneStar->TabIndex = 4;
			this->pbOneStar->TabStop = false;
			// 
			// pbZeroStars
			// 
			this->pbZeroStars->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pbZeroStars.Image")));
			this->pbZeroStars->Location = System::Drawing::Point(85, 116);
			this->pbZeroStars->Name = L"pbZeroStars";
			this->pbZeroStars->Size = System::Drawing::Size(297, 70);
			this->pbZeroStars->TabIndex = 5;
			this->pbZeroStars->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(81, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(292, 24);
			this->label1->TabIndex = 6;
			this->label1->Text = L"CALIFICACIÓN AL REPARTIDOR";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(26, 66);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 13);
			this->label2->TabIndex = 7;
			this->label2->Text = L"Nombre del repartidor";
			// 
			// txtDeliverymanName
			// 
			this->txtDeliverymanName->Location = System::Drawing::Point(140, 66);
			this->txtDeliverymanName->Name = L"txtDeliverymanName";
			this->txtDeliverymanName->Size = System::Drawing::Size(242, 20);
			this->txtDeliverymanName->TabIndex = 8;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(26, 85);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(64, 13);
			this->label3->TabIndex = 7;
			this->label3->Text = L"Puntuación:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(26, 201);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(200, 91);
			this->label4->TabIndex = 9;
			this->label4->Text = L"Estimado cliente, califíquenos del 1 al 5: \r\nDonde \r\n(1) Totalmente insatisfecho\r"
				L"\n(2) Insatisfecho\r\n(3) Neutral\r\n(4) Satisfecho\r\n(5) Totalmente satisfecho";
			// 
			// txtDeliverymanRating
			// 
			this->txtDeliverymanRating->Location = System::Drawing::Point(282, 201);
			this->txtDeliverymanRating->Name = L"txtDeliverymanRating";
			this->txtDeliverymanRating->Size = System::Drawing::Size(100, 20);
			this->txtDeliverymanRating->TabIndex = 10;
			this->txtDeliverymanRating->TextChanged += gcnew System::EventHandler(this, &DeliverymanRatingForm::txtDeliverymanRating_TextChanged);
			// 
			// btnFinalize
			// 
			this->btnFinalize->Location = System::Drawing::Point(307, 256);
			this->btnFinalize->Name = L"btnFinalize";
			this->btnFinalize->Size = System::Drawing::Size(75, 23);
			this->btnFinalize->TabIndex = 11;
			this->btnFinalize->Text = L"Finalizar";
			this->btnFinalize->UseVisualStyleBackColor = true;
			this->btnFinalize->Click += gcnew System::EventHandler(this, &DeliverymanRatingForm::btnFinalize_Click);
			// 
			// txtIdSale
			// 
			this->txtIdSale->Location = System::Drawing::Point(142, 40);
			this->txtIdSale->Name = L"txtIdSale";
			this->txtIdSale->Size = System::Drawing::Size(38, 20);
			this->txtIdSale->TabIndex = 12;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(26, 40);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(49, 13);
			this->label5->TabIndex = 13;
			this->label5->Text = L"Id. venta";
			// 
			// DeliverymanRatingForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(441, 308);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->txtIdSale);
			this->Controls->Add(this->btnFinalize);
			this->Controls->Add(this->txtDeliverymanRating);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->txtDeliverymanName);
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
			this->Name = L"DeliverymanRatingForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"DeliverymanRatingForm";
			this->Load += gcnew System::EventHandler(this, &DeliverymanRatingForm::DeliverymanRatingForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFiveStars))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbFourStars))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbThreeStars))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbTwoStars))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbOneStar))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pbZeroStars))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Void DeliverymanRatingForm_Load(System::Object^ sender, System::EventArgs^ e) {

		Refreshpage();
	}

		   void Refreshpage() {
			   int idsale= Int32::Parse(txtIdSale->Text);
			   Order^ order = AppManager::QueryOrderbyId(idsale);
			   txtDeliverymanName->Text = order->DeliveryMan->FirstName + " " +  order->DeliveryMan->LastName;
		
		   }
private: System::Void txtDeliverymanRating_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	if (txtDeliverymanRating->Text->CompareTo("") == 0) {
		pbZeroStars->Visible = true;
		pbOneStar->Visible = false; pbTwoStars->Visible = false; pbThreeStars->Visible = false;
		pbFourStars->Visible = false;   pbFiveStars->Visible = false;
	}
	else if (Int32::Parse(txtDeliverymanRating->Text) == 1 |
		Int32::Parse(txtDeliverymanRating->Text) == 2 |
		Int32::Parse(txtDeliverymanRating->Text) == 3 |
		Int32::Parse(txtDeliverymanRating->Text) == 4 |
		Int32::Parse(txtDeliverymanRating->Text) == 5) {
		switch (Int32::Parse(txtDeliverymanRating->Text)) {

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
	if (Int32::Parse(txtDeliverymanRating->Text) == 1 |
		Int32::Parse(txtDeliverymanRating->Text) == 2 |
		Int32::Parse(txtDeliverymanRating->Text) == 3 |
		Int32::Parse(txtDeliverymanRating->Text) == 4 |
		Int32::Parse(txtDeliverymanRating->Text) == 5) {
		int idsale = Int32::Parse(txtIdSale->Text);
		Order^ order = AppManager::QueryOrderbyId(idsale);
		order->DeliveryManRating = Int32::Parse(txtDeliverymanRating->Text);
		order->Status = 'X';
		AppManager::UpdateDeliverymanQualification(order);
		AppManager::UpdateStatusOrder(order);
		
		this->Close();

	}
	else {
		MessageBox::Show("Ingrese un valor entero");
	}
}
};
}
