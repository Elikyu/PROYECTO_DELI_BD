#pragma once
#define MODEGROCERIES 2
#define MODEHEALTH 3

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
	/// Resumen de StatisticsForm
	/// </summary>
	public ref class StatisticsForm : public System::Windows::Forms::Form
	{
	public:
		StatisticsForm(void)
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
		~StatisticsForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabPage^ tabIncome;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ linechartIncome;


	private: System::Windows::Forms::TabPage^ tabSoldProducts;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TabControl^ tabProductsSold;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ barchartStockProducts;
	private: System::Windows::Forms::TabPage^ tabPage1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ piechartProductsSold;



	private: System::Windows::Forms::TabPage^ tabPage2;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chartDeliverymanRating;




	protected:


	protected:










	protected:

	protected:





	protected:

	protected:

	protected:

	protected:

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
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea2 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea3 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea4 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->tabIncome = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->linechartIncome = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabSoldProducts = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->barchartStockProducts = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabProductsSold = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->piechartProductsSold = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->chartDeliverymanRating = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->tabIncome->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->linechartIncome))->BeginInit();
			this->tabSoldProducts->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->barchartStockProducts))->BeginInit();
			this->tabProductsSold->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->piechartProductsSold))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDeliverymanRating))->BeginInit();
			this->SuspendLayout();
			// 
			// tabIncome
			// 
			this->tabIncome->Controls->Add(this->label2);
			this->tabIncome->Controls->Add(this->linechartIncome);
			this->tabIncome->Location = System::Drawing::Point(4, 22);
			this->tabIncome->Name = L"tabIncome";
			this->tabIncome->Padding = System::Windows::Forms::Padding(3);
			this->tabIncome->Size = System::Drawing::Size(452, 310);
			this->tabIncome->TabIndex = 1;
			this->tabIncome->Text = L"Ingresos";
			this->tabIncome->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(338, 263);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(78, 26);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Código de la\r\nboleta";
			// 
			// linechartIncome
			// 
			this->linechartIncome->BorderlineWidth = 0;
			chartArea1->AxisX->MajorGrid->LineColor = System::Drawing::Color::White;
			chartArea1->AxisX->MajorTickMark->LineColor = System::Drawing::Color::White;
			chartArea1->AxisY->MajorGrid->LineColor = System::Drawing::Color::White;
			chartArea1->AxisY->MinorGrid->LineColor = System::Drawing::Color::Transparent;
			chartArea1->AxisY->MinorTickMark->LineColor = System::Drawing::Color::Transparent;
			chartArea1->Name = L"ChartArea1";
			this->linechartIncome->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->linechartIncome->Legends->Add(legend1);
			this->linechartIncome->Location = System::Drawing::Point(6, 37);
			this->linechartIncome->Name = L"linechartIncome";
			series1->BorderWidth = 5;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Line;
			series1->Color = System::Drawing::Color::Red;
			series1->Legend = L"Legend1";
			series1->Name = L"Montos";
			this->linechartIncome->Series->Add(series1);
			this->linechartIncome->Size = System::Drawing::Size(412, 267);
			this->linechartIncome->TabIndex = 1;
			this->linechartIncome->Text = L"chartIncome";
			// 
			// tabSoldProducts
			// 
			this->tabSoldProducts->Controls->Add(this->label1);
			this->tabSoldProducts->Controls->Add(this->barchartStockProducts);
			this->tabSoldProducts->Location = System::Drawing::Point(4, 22);
			this->tabSoldProducts->Name = L"tabSoldProducts";
			this->tabSoldProducts->Padding = System::Windows::Forms::Padding(3);
			this->tabSoldProducts->Size = System::Drawing::Size(452, 310);
			this->tabSoldProducts->TabIndex = 0;
			this->tabSoldProducts->Text = L"Stock de productos";
			this->tabSoldProducts->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(349, 275);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(58, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Producto";
			// 
			// barchartStockProducts
			// 
			this->barchartStockProducts->BorderlineWidth = 0;
			chartArea2->AxisX->MajorGrid->LineColor = System::Drawing::Color::White;
			chartArea2->AxisX->MajorTickMark->LineColor = System::Drawing::Color::White;
			chartArea2->AxisY->MajorGrid->LineColor = System::Drawing::Color::White;
			chartArea2->AxisY->MinorGrid->LineColor = System::Drawing::Color::Transparent;
			chartArea2->AxisY->MinorTickMark->LineColor = System::Drawing::Color::Transparent;
			chartArea2->Name = L"ChartArea1";
			this->barchartStockProducts->ChartAreas->Add(chartArea2);
			legend2->Name = L"Legend1";
			this->barchartStockProducts->Legends->Add(legend2);
			this->barchartStockProducts->Location = System::Drawing::Point(11, 37);
			this->barchartStockProducts->Name = L"barchartStockProducts";
			series2->ChartArea = L"ChartArea1";
			series2->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)));
			series2->Legend = L"Legend1";
			series2->Name = L"Stock";
			this->barchartStockProducts->Series->Add(series2);
			this->barchartStockProducts->Size = System::Drawing::Size(412, 267);
			this->barchartStockProducts->TabIndex = 0;
			this->barchartStockProducts->Text = L"chartStockProduct";
			// 
			// tabProductsSold
			// 
			this->tabProductsSold->Controls->Add(this->tabSoldProducts);
			this->tabProductsSold->Controls->Add(this->tabIncome);
			this->tabProductsSold->Controls->Add(this->tabPage1);
			this->tabProductsSold->Controls->Add(this->tabPage2);
			this->tabProductsSold->Location = System::Drawing::Point(18, 22);
			this->tabProductsSold->Name = L"tabProductsSold";
			this->tabProductsSold->SelectedIndex = 0;
			this->tabProductsSold->Size = System::Drawing::Size(460, 336);
			this->tabProductsSold->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label3);
			this->tabPage1->Controls->Add(this->piechartProductsSold);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(452, 310);
			this->tabPage1->TabIndex = 2;
			this->tabPage1->Text = L"Productos vendidos";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(349, 275);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(58, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Producto";
			// 
			// piechartProductsSold
			// 
			this->piechartProductsSold->BorderlineWidth = 0;
			chartArea3->AxisX->MajorGrid->LineColor = System::Drawing::Color::White;
			chartArea3->AxisX->MajorTickMark->LineColor = System::Drawing::Color::White;
			chartArea3->AxisY->MajorGrid->LineColor = System::Drawing::Color::White;
			chartArea3->AxisY->MinorGrid->LineColor = System::Drawing::Color::Transparent;
			chartArea3->AxisY->MinorTickMark->LineColor = System::Drawing::Color::Transparent;
			chartArea3->Name = L"ChartArea1";
			this->piechartProductsSold->ChartAreas->Add(chartArea3);
			legend3->Name = L"Legend1";
			this->piechartProductsSold->Legends->Add(legend3);
			this->piechartProductsSold->Location = System::Drawing::Point(11, 37);
			this->piechartProductsSold->Name = L"piechartProductsSold";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Pie;
			series3->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(64)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series3->Legend = L"Legend1";
			series3->Name = L"Cant.Vendida";
			series3->YValuesPerPoint = 2;
			this->piechartProductsSold->Series->Add(series3);
			this->piechartProductsSold->Size = System::Drawing::Size(412, 267);
			this->piechartProductsSold->TabIndex = 1;
			this->piechartProductsSold->Text = L"chartStockProduct";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label4);
			this->tabPage2->Controls->Add(this->chartDeliverymanRating);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(452, 310);
			this->tabPage2->TabIndex = 3;
			this->tabPage2->Text = L"Eficiencia del repartidor";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(347, 273);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(66, 13);
			this->label4->TabIndex = 2;
			this->label4->Text = L"Repartidor";
			// 
			// chartDeliverymanRating
			// 
			this->chartDeliverymanRating->BorderlineWidth = 0;
			chartArea4->AxisX->MajorGrid->LineColor = System::Drawing::Color::White;
			chartArea4->AxisX->MajorTickMark->LineColor = System::Drawing::Color::White;
			chartArea4->AxisY->MajorGrid->LineColor = System::Drawing::Color::White;
			chartArea4->AxisY->MinorGrid->LineColor = System::Drawing::Color::Transparent;
			chartArea4->AxisY->MinorTickMark->LineColor = System::Drawing::Color::Transparent;
			chartArea4->Name = L"ChartArea1";
			this->chartDeliverymanRating->ChartAreas->Add(chartArea4);
			legend4->Name = L"Legend1";
			this->chartDeliverymanRating->Legends->Add(legend4);
			this->chartDeliverymanRating->Location = System::Drawing::Point(11, 37);
			this->chartDeliverymanRating->Name = L"chartDeliverymanRating";
			series4->ChartArea = L"ChartArea1";
			series4->Color = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(192)), static_cast<System::Int32>(static_cast<System::Byte>(192)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			series4->Legend = L"Legend1";
			series4->Name = L"Calificación";
			this->chartDeliverymanRating->Series->Add(series4);
			this->chartDeliverymanRating->Size = System::Drawing::Size(412, 267);
			this->chartDeliverymanRating->TabIndex = 1;
			this->chartDeliverymanRating->Text = L"chartDeliverymanRating";
			// 
			// StatisticsForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(494, 370);
			this->Controls->Add(this->tabProductsSold);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"StatisticsForm";
			this->Text = L"StatisticsForm";
			this->Load += gcnew System::EventHandler(this, &StatisticsForm::StatisticsForm_Load);
			this->tabIncome->ResumeLayout(false);
			this->tabIncome->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->linechartIncome))->EndInit();
			this->tabSoldProducts->ResumeLayout(false);
			this->tabSoldProducts->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->barchartStockProducts))->EndInit();
			this->tabProductsSold->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->piechartProductsSold))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chartDeliverymanRating))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		private: System::Void StatisticsForm_Load(System::Object^ sender, System::EventArgs^ e) {

				List<Groceries^>^ groceriesList = AppManager::QueryAllGroceries();
				List<HealthCare^>^ healthcareList = AppManager::QueryAllHealthCare();
				List<Product^>^ productsList = AppManager::QueryAllProducts();

				if (productsList != nullptr) {
					for (int i = 0; i < productsList->Count; i++) {
						barchartStockProducts->Series["Stock"]->Points->Add(productsList[i]->StockTotal);
						barchartStockProducts->Series["Stock"]->Points[i]->AxisLabel = productsList[i]->Name;
						barchartStockProducts->Series["Stock"]->Points[i]->LegendText = productsList[i]->Name;
						barchartStockProducts->Series["Stock"]->Points[i]->Label = "" + productsList[i]->StockTotal;
					}
				}

				if (productsList != nullptr) {
					for (int i = 0; i < productsList->Count; i++) {
						piechartProductsSold->Series["Cant.Vendida"]->Points->Add(productsList[i]->QuantitySold);
						piechartProductsSold->Series["Cant.Vendida"]->Points[i]->AxisLabel = productsList[i]->Name;
						piechartProductsSold->Series["Cant.Vendida"]->Points[i]->LegendText = productsList[i]->Name;
						piechartProductsSold->Series["Cant.Vendida"]->Points[i]->Label = "" + productsList[i]->QuantitySold;

					}
				}

				List<Order^>^ orderList = AppManager::QueryAllSales();
				if (orderList != nullptr) {
					for (int i = 0; i < orderList->Count; i++) {
						linechartIncome->Series["Montos"]->Points->Add(orderList[i]->Total);
						linechartIncome->Series["Montos"]->Points[i]->AxisLabel = "" + orderList[i]->Id;
						linechartIncome->Series["Montos"]->Points[i]->LegendText = "" + orderList[i]->Id;
						linechartIncome->Series["Montos"]->Points[i]->Label = "" + orderList[i]->Total;
					}
				}	
				String^ deliverymanFullName;
				//if (orderList != nullptr) {
					for (int i = 0; i < orderList->Count; i++) {
						if (orderList[i]->DeliveryMan != nullptr) {
							deliverymanFullName = orderList[i]->DeliveryMan->FirstName + " " + orderList[i]->DeliveryMan->LastName;
							chartDeliverymanRating->Series["Calificación"]->Points->Add(orderList[i]->DeliveryMan->DeliveryManRatingAverage);
							chartDeliverymanRating->Series["Calificación"]->Points[i]->AxisLabel = deliverymanFullName;
							chartDeliverymanRating->Series["Calificación"]->Points[i]->LegendText = deliverymanFullName;
							chartDeliverymanRating->Series["Calificación"]->Points[i]->Label = "" + orderList[i]->DeliveryMan->DeliveryManRatingAverage;
						}
					}
				//}
		}
	};
}
