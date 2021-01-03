#pragma once
#include<malloc.h>

namespace PoluyanovM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MainForm
	/// </summary>

	double *M1;
	double *M2;
	double *M3;


	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//Добавляем выделение памяти для массивов
			//
			M1 = new double[8 * sizeof(double)]{0,0,0,0,0,0,0,0};// сразу обнулим его инициализатором
			this->dataGridView1->RowCount = 8;// зададим количество строк первой таблицы
			M3 = new double[4 * sizeof(double)];
			// проинициализируем массив М2 в момент его создания инициализатором
			M2 = new double[10 * sizeof(double)] { 0.2,(-1.2),0.5,-3,9,2,-9,8,9,0 };
			// проинициализируем массив М2 и внесем его в таблицу
			this->dataGridView2->RowCount = 10;// зададим количество строк второй таблицы
			// заполним вторую таблицу значениями массива
			for (int i = 0; i < 10; i++) {
				this->dataGridView2->Rows[i]->Cells[0]->Value = Convert::ToString(M2[i]);
				// заполним и первый обнулённый массив
				i<8? dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(M1[i]):i=i;
			}
			
			this->dataGridView3->RowCount = 4;// зададим количество строк третьей таблицы
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MainForm()
		{
			//зачистим за собой память наших массивов
			free(M1);
			free(M2);
			free(M3);

			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::DataGridView^  dataGridView3;
	private: System::Windows::Forms::DataGridView^  dataGridView2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  C;
	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  C0;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MainForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->C = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->C0 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl1->Location = System::Drawing::Point(0, 0);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(1097, 523);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label6);
			this->tabPage1->Controls->Add(this->label5);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->button1);
			this->tabPage1->Controls->Add(this->dataGridView3);
			this->tabPage1->Controls->Add(this->dataGridView2);
			this->tabPage1->Controls->Add(this->dataGridView1);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1089, 497);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Номер 1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(392, 62);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(76, 13);
			this->label6->TabIndex = 8;
			this->label6->Text = L"Массив М3[4]";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(147, 62);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(82, 13);
			this->label5->TabIndex = 7;
			this->label5->Text = L"Массив М2[10]";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(8, 62);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(76, 13);
			this->label4->TabIndex = 6;
			this->label4->Text = L"Массив М1[8]";
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(255, 78);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(131, 23);
			this->button1->TabIndex = 5;
			this->button1->Text = L"Обработать";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MainForm::button1_Click);
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Column1 });
			this->dataGridView3->Location = System::Drawing::Point(392, 78);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->Size = System::Drawing::Size(113, 160);
			this->dataGridView3->TabIndex = 4;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"M3";
			this->Column1->Name = L"Column1";
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->C });
			this->dataGridView2->Location = System::Drawing::Point(150, 78);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(99, 265);
			this->dataGridView2->TabIndex = 3;
			// 
			// C
			// 
			this->C->HeaderText = L"M2";
			this->C->Name = L"C";
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->C0 });
			this->dataGridView1->Location = System::Drawing::Point(8, 78);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(99, 265);
			this->dataGridView1->TabIndex = 2;
			// 
			// C0
			// 
			this->C0->HeaderText = L"M1";
			this->C0->Name = L"C0";
			// 
			// label1
			// 
			this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			this->label1->Location = System::Drawing::Point(3, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(1083, 40);
			this->label1->TabIndex = 1;
			this->label1->Text = resources->GetString(L"label1.Text");
			this->label1->UseWaitCursor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1089, 497);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Номер 2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->Dock = System::Windows::Forms::DockStyle::Top;
			this->label2->Location = System::Drawing::Point(3, 3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(1083, 40);
			this->label2->TabIndex = 0;
			this->label2->Text = resources->GetString(L"label2.Text");
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label3);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1089, 497);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Номер 3";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->Dock = System::Windows::Forms::DockStyle::Top;
			this->label3->Location = System::Drawing::Point(3, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(1083, 32);
			this->label3->TabIndex = 0;
			this->label3->Text = resources->GetString(L"label3.Text");
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1097, 523);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MainForm";
			this->Text = L"13 Полуянов Матвей ";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage2->ResumeLayout(false);
			this->tabPage3->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: void compare(double *M1, double *M2, double *M3) {
		// обработка значений массивов
		// у нас в результирующем массиве всего 4 элемента
		// значит и цикл делаем только до 4х

		for (int i = 0; i < 4; i++) {
			if (M1[i] * M2[i] >= 0) 
			{ M3[i] = 1; }// числа одинаковых знаков при произведении друг на друга дадут положительное число
			else { M3[i] = 0; }// числа разных знаков при произведении друг на друга дадут отрицательное число
		}
		//return void;
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		// заполним массив М1 значениями введёнными в таблицу 1
		for (int i = 0; i < 8; i++) {
         M1[i]= Convert::ToDouble(this->dataGridView1->Rows[i]->Cells[0]->Value);
		}
		//вызовем описанную функцию для заполнения массива М3
		this->compare(M1, M2, M3);
		// внесём данные из М3 в результирующую таблицу
		for (int i = 0; i < 4; i++) {
			this->dataGridView3->Rows[i]->Cells[0]->Value = Convert::ToString(M3[i]);
		}
	}
};
}
