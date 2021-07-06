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
	/// Resumen de AllRatingsForm
	/// </summary>
	public ref class AllRatingsForm : public System::Windows::Forms::Form
	{
	public:
		AllRatingsForm(void)
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
		~AllRatingsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataGridView^ dgvDeliverymanRating;
	protected:

	protected:
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ IdSale;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ FullNameDeliveryman;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ StarsNumberDeliveryman;
	private: System::Windows::Forms::DataGridView^ dgvCustomerRating;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ dataGridViewTextBoxColumn1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ CustomerFullName;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ StarsNumberCustomer;
	private: System::Windows::Forms::Label^ label2;





















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
			this->dgvDeliverymanRating = (gcnew System::Windows::Forms::DataGridView());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->IdSale = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->FullNameDeliveryman = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StarsNumberDeliveryman = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dgvCustomerRating = (gcnew System::Windows::Forms::DataGridView());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->dataGridViewTextBoxColumn1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CustomerFullName = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->StarsNumberCustomer = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDeliverymanRating))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCustomerRating))->BeginInit();
			this->SuspendLayout();
			// 
			// dgvDeliverymanRating
			// 
			this->dgvDeliverymanRating->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvDeliverymanRating->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->IdSale,
					this->FullNameDeliveryman, this->StarsNumberDeliveryman
			});
			this->dgvDeliverymanRating->Location = System::Drawing::Point(68, 48);
			this->dgvDeliverymanRating->Name = L"dgvDeliverymanRating";
			this->dgvDeliverymanRating->Size = System::Drawing::Size(352, 125);
			this->dgvDeliverymanRating->TabIndex = 0;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(163, 23);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(169, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"CALIFICACIÓN AL REPARTIDOR";
			// 
			// IdSale
			// 
			this->IdSale->HeaderText = L"Cód. Venta";
			this->IdSale->Name = L"IdSale";
			this->IdSale->Width = 80;
			// 
			// FullNameDeliveryman
			// 
			this->FullNameDeliveryman->HeaderText = L"Nombre completo (R)";
			this->FullNameDeliveryman->Name = L"FullNameDeliveryman";
			this->FullNameDeliveryman->Width = 150;
			// 
			// StarsNumberDeliveryman
			// 
			this->StarsNumberDeliveryman->HeaderText = L"N° Estrellas (R)";
			this->StarsNumberDeliveryman->Name = L"StarsNumberDeliveryman";
			this->StarsNumberDeliveryman->Width = 80;
			// 
			// dgvCustomerRating
			// 
			this->dgvCustomerRating->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dgvCustomerRating->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->dataGridViewTextBoxColumn1,
					this->CustomerFullName, this->StarsNumberCustomer
			});
			this->dgvCustomerRating->Location = System::Drawing::Point(68, 221);
			this->dgvCustomerRating->Name = L"dgvCustomerRating";
			this->dgvCustomerRating->Size = System::Drawing::Size(352, 125);
			this->dgvCustomerRating->TabIndex = 2;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(175, 195);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(143, 13);
			this->label2->TabIndex = 3;
			this->label2->Text = L"CALIFICACIÓN AL CLIENTE";
			// 
			// dataGridViewTextBoxColumn1
			// 
			this->dataGridViewTextBoxColumn1->HeaderText = L"Cód. Venta";
			this->dataGridViewTextBoxColumn1->Name = L"dataGridViewTextBoxColumn1";
			this->dataGridViewTextBoxColumn1->Width = 80;
			// 
			// CustomerFullName
			// 
			this->CustomerFullName->HeaderText = L"Nombre completo (C)";
			this->CustomerFullName->Name = L"CustomerFullName";
			this->CustomerFullName->Width = 150;
			// 
			// StarsNumberCustomer
			// 
			this->StarsNumberCustomer->HeaderText = L"N° Estrellas (C)";
			this->StarsNumberCustomer->Name = L"StarsNumberCustomer";
			this->StarsNumberCustomer->Width = 80;
			// 
			// AllRatingsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(494, 370);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->dgvCustomerRating);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->dgvDeliverymanRating);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"AllRatingsForm";
			this->Text = L"AllRatingsForm";
			this->Load += gcnew System::EventHandler(this, &AllRatingsForm::AllRatingsForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvDeliverymanRating))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dgvCustomerRating))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		private: System::Void AllRatingsForm_Load(System::Object^ sender, System::EventArgs^ e) {
			RefreshDGVAllRatings();
		}
			   void RefreshDGVAllRatings() {
				   List<Order^>^ orderList = AppManager::QueryAllSales();
				   int idsale = AppManager::QueryLastSaleId();
				   Order^ order = AppManager::QueryOrderbyId(idsale);
				   String^ deliverymanFullName;
				   String^ customerFullName;

				   dgvDeliverymanRating->Rows->Clear();
				   for (int i = 0; i < orderList->Count; i++) {
					   if (orderList[i]->DeliveryMan != nullptr) {
						   deliverymanFullName = orderList[i]->DeliveryMan->FirstName + " " + orderList[i]->DeliveryMan->LastName;
						   dgvDeliverymanRating->Rows->Add(gcnew array<String^> {
							   "" + orderList[i]->Id,
								   deliverymanFullName,
								   "" + orderList[i]->DeliveryManRating
						   });
					   }
				   }

				   dgvCustomerRating->Rows->Clear();
				   for (int i = 0; i < orderList->Count; i++) {
					   customerFullName = orderList[i]->User->FirstName + " " + orderList[i]->User->LastName;
					   dgvCustomerRating->Rows->Add(gcnew array<String^> {
						   "" + orderList[i]->Id,
							   customerFullName,
							   "" + orderList[i]->CustomerRating
					   });
				   }

				   //DeliveryManRatingAverage
			   }

	}; // promedios
}
