#pragma once
// для управления выделением памяти
#include<malloc.h>

namespace PoluyanovM {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	// опишем динамические массивы
	// задание 1
	
	double *M1;
	double *M2;
	double *M3;

	// задание 2
	int **A1;
	int **B1;

	public ref class MainForm : public System::Windows::Forms::Form
	{
	public:
		MainForm(void)
		{
			InitializeComponent();
			//
			//Добавляем выделение памяти для массивов
			M1 = new double[8 * sizeof(double)]{0,0,0,0,0,0,0,0};// сразу обнулим его инициализатором
			this->dataGridView1->RowCount = 8;// зададим количество строк первой таблицы
			M3 = new double[4 * sizeof(double)];
			// проинициализируем массив М2 в момент его создания инициализатором
			M2 = new double[10 * sizeof(double)] { 0.2,(-1.2),0.5,-3,9,2,-9,8,9,0 };
			// проинициализируем массив М2 
			this->dataGridView2->RowCount = 10;// зададим количество строк второй таблицы
			// и заполним вторую таблицу значениями массива
			for (int i = 0; i < 10; i++) {
				this->dataGridView2->Rows[i]->Cells[0]->Value = Convert::ToString(M2[i]);
				// заполним и первый обнулённый массив
				i<8? dataGridView1->Rows[i]->Cells[0]->Value = Convert::ToString(M1[i]):i=i;
			}			
			this->dataGridView3->RowCount = 4;// зададим количество строк третьей таблицы

			// задание 2
			dataGridView4->RowCount = 3;// зададим количество строк первой таблицы А
			dataGridView6->RowCount = 3;// зададим количество строк второй таблицы А
			dataGridView5->RowCount = 4;// зададим количество строк первой таблицы B
			dataGridView7->RowCount = 4;// зададим количество строк второй таблицы B
			// выделим память для массивов и проинициализируем В1
			A1 = new int*[3];
			B1 = new int*[4];
			for (int i = 0; i < 4; i++) {
				B1[i] = new int[4];// выделим память для каждой строки В1
				if (i < 3) {
					A1[i] = new int[3];// выделим память для каждой строки А1
				}
			}
			// инициализируем согласно условию
			int T[16]{ 5,3,7,-1, -3,-5,4,7, 9,0,1,2, 1,5,3,2 };// временный массив
			int c = 0;// обнулим счетчик
			for (int i = 0; i < 4; i++) {// по всем строкам
				for (int j = 0; j < 4; j++) { // по элементам строки
					B1[i][j] = T[c++];// внесём значение в массив
					// и сразу внесем значение во входную таблицу чтобы повторно не запускать цикл
					dataGridView5->Rows[i]->Cells[j]->Value = Convert::ToString(B1[i][j]);
				}
			}
		}

	protected:

		~MainForm()
		{
			//зачистим за собой память наших массивов
			free(M1);
			free(M2);
			free(M3);
			
			// освободим внутренние массивы строк
			for (int i = 0; i < 4; i++) {
				free(B1[i]);// освобождаем память строки В1
				if (i < 3) {
					free(A1[i]); //освобождаем память строки А1
				}
			}
			// освободим собственно внешние массивы
			free(A1);
			free(B1);

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
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::DataGridView^  dataGridView7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column12;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column13;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column14;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column15;
	private: System::Windows::Forms::DataGridView^  dataGridView6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
	private: System::Windows::Forms::DataGridView^  dataGridView5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column11;
	private: System::Windows::Forms::DataGridView^  dataGridView4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
private: System::Windows::Forms::ListBox^  listBox2;
private: System::Windows::Forms::Label^  label13;
private: System::Windows::Forms::Label^  label12;
private: System::Windows::Forms::ListBox^  listBox1;
private: System::Windows::Forms::TextBox^  textBox1;
private: System::Windows::Forms::Label^  label11;
private: System::Windows::Forms::Button^  button3;


	private:

		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code

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
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->dataGridView7 = (gcnew System::Windows::Forms::DataGridView());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView6 = (gcnew System::Windows::Forms::DataGridView());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView5 = (gcnew System::Windows::Forms::DataGridView());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->listBox2 = (gcnew System::Windows::Forms::ListBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->listBox1 = (gcnew System::Windows::Forms::ListBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
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
			this->tabControl1->Size = System::Drawing::Size(781, 424);
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
			this->tabPage1->Size = System::Drawing::Size(773, 398);
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
			this->label1->Size = System::Drawing::Size(767, 59);
			this->label1->TabIndex = 1;
			this->label1->Text = resources->GetString(L"label1.Text");
			this->label1->UseWaitCursor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->button2);
			this->tabPage2->Controls->Add(this->label10);
			this->tabPage2->Controls->Add(this->label9);
			this->tabPage2->Controls->Add(this->label8);
			this->tabPage2->Controls->Add(this->label7);
			this->tabPage2->Controls->Add(this->dataGridView7);
			this->tabPage2->Controls->Add(this->dataGridView6);
			this->tabPage2->Controls->Add(this->dataGridView5);
			this->tabPage2->Controls->Add(this->dataGridView4);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(773, 398);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Номер 2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(244, 207);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(162, 23);
			this->button2->TabIndex = 9;
			this->button2->Text = L"Обработать";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MainForm::button2_Click);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(435, 248);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(145, 13);
			this->label10->TabIndex = 8;
			this->label10->Text = L"Массив В после обработки";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(69, 248);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(145, 13);
			this->label9->TabIndex = 7;
			this->label9->Text = L"Массив А после обработки";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(453, 69);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(127, 13);
			this->label8->TabIndex = 6;
			this->label8->Text = L"Массив В до обработки";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(74, 69);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(127, 13);
			this->label7->TabIndex = 5;
			this->label7->Text = L"Массив А до обработки";
			// 
			// dataGridView7
			// 
			this->dataGridView7->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView7->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column12,
					this->Column13, this->Column14, this->Column15
			});
			this->dataGridView7->Location = System::Drawing::Point(427, 264);
			this->dataGridView7->Name = L"dataGridView7";
			this->dataGridView7->Size = System::Drawing::Size(180, 121);
			this->dataGridView7->TabIndex = 4;
			// 
			// Column12
			// 
			this->Column12->HeaderText = L"1";
			this->Column12->Name = L"Column12";
			this->Column12->Width = 30;
			// 
			// Column13
			// 
			this->Column13->HeaderText = L"2";
			this->Column13->Name = L"Column13";
			this->Column13->Width = 30;
			// 
			// Column14
			// 
			this->Column14->HeaderText = L"3";
			this->Column14->Name = L"Column14";
			this->Column14->Width = 30;
			// 
			// Column15
			// 
			this->Column15->HeaderText = L"4";
			this->Column15->Name = L"Column15";
			this->Column15->Width = 30;
			// 
			// dataGridView6
			// 
			this->dataGridView6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView6->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column5,
					this->Column6, this->Column7
			});
			this->dataGridView6->Location = System::Drawing::Point(65, 264);
			this->dataGridView6->Name = L"dataGridView6";
			this->dataGridView6->Size = System::Drawing::Size(149, 101);
			this->dataGridView6->TabIndex = 3;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"1";
			this->Column5->Name = L"Column5";
			this->Column5->Width = 30;
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"2";
			this->Column6->Name = L"Column6";
			this->Column6->Width = 30;
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"3";
			this->Column7->Name = L"Column7";
			this->Column7->Width = 30;
			// 
			// dataGridView5
			// 
			this->dataGridView5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView5->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column8,
					this->Column9, this->Column10, this->Column11
			});
			this->dataGridView5->Location = System::Drawing::Point(427, 85);
			this->dataGridView5->Name = L"dataGridView5";
			this->dataGridView5->Size = System::Drawing::Size(180, 121);
			this->dataGridView5->TabIndex = 2;
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"1";
			this->Column8->Name = L"Column8";
			this->Column8->Width = 30;
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"2";
			this->Column9->Name = L"Column9";
			this->Column9->Width = 30;
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"3";
			this->Column10->Name = L"Column10";
			this->Column10->Width = 30;
			// 
			// Column11
			// 
			this->Column11->HeaderText = L"4";
			this->Column11->Name = L"Column11";
			this->Column11->Width = 30;
			// 
			// dataGridView4
			// 
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column2,
					this->Column3, this->Column4
			});
			this->dataGridView4->Location = System::Drawing::Point(65, 85);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->Size = System::Drawing::Size(149, 103);
			this->dataGridView4->TabIndex = 1;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"1";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 30;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"2";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 30;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"3";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 30;
			// 
			// label2
			// 
			this->label2->Dock = System::Windows::Forms::DockStyle::Top;
			this->label2->Location = System::Drawing::Point(3, 3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(767, 40);
			this->label2->TabIndex = 0;
			this->label2->Text = resources->GetString(L"label2.Text");
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->button3);
			this->tabPage3->Controls->Add(this->listBox2);
			this->tabPage3->Controls->Add(this->label13);
			this->tabPage3->Controls->Add(this->label12);
			this->tabPage3->Controls->Add(this->listBox1);
			this->tabPage3->Controls->Add(this->textBox1);
			this->tabPage3->Controls->Add(this->label11);
			this->tabPage3->Controls->Add(this->label3);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(773, 398);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Номер 3";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(323, 81);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(97, 23);
			this->button3->TabIndex = 7;
			this->button3->Text = L"Обработать";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MainForm::button3_Click);
			// 
			// listBox2
			// 
			this->listBox2->FormattingEnabled = true;
			this->listBox2->Location = System::Drawing::Point(159, 97);
			this->listBox2->Name = L"listBox2";
			this->listBox2->Size = System::Drawing::Size(143, 264);
			this->listBox2->TabIndex = 6;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(156, 81);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(114, 13);
			this->label13->TabIndex = 5;
			this->label13->Text = L"Читаются одинаково";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(8, 81);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(118, 13);
			this->label12->TabIndex = 4;
			this->label12->Text = L"Список слов в строке";
			// 
			// listBox1
			// 
			this->listBox1->FormattingEnabled = true;
			this->listBox1->Location = System::Drawing::Point(8, 97);
			this->listBox1->Name = L"listBox1";
			this->listBox1->Size = System::Drawing::Size(136, 264);
			this->listBox1->TabIndex = 3;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(186, 45);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(565, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(8, 48);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(172, 13);
			this->label11->TabIndex = 1;
			this->label11->Text = L"Введите строку до 80 символов:";
			// 
			// label3
			// 
			this->label3->Dock = System::Windows::Forms::DockStyle::Top;
			this->label3->Location = System::Drawing::Point(3, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(767, 39);
			this->label3->TabIndex = 0;
			this->label3->Text = resources->GetString(L"label3.Text");
			// 
			// MainForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(781, 424);
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
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

private: void compare(double *M1, double *M2, double *M3) {
		// обработка значений массивов
		// у нас в результирующем массиве всего 4 элемента
		// значит и цикл делаем только до 4х

		for (int i = 0; i < 4; i++) {// по первым 4м элементам
			if (M1[i] * M2[i] >= 0) // нас интересует только знак числа
			{ M3[i] = 1; }// числа одинаковых знаков при произведении друг на друга дадут положительное число
			else { M3[i] = 0; }// числа разных знаков при произведении друг на друга дадут отрицательное число
			
			/* вообще говоря всё условие можно выкинуть и написать так
			M1[i] * M2[i]>=0?M3[i]=1:M3[i]=0;
			или вообще так  M3[i]=(int)(M1[i] * M2[i] >= 0) 
			но могут возникнуть лишние вопросы
			*/
		}
	}
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		// заполним массив М1 значениями введёнными в таблицу 1
		for (int i = 0; i < 8; i++) {
         M1[i]= Convert::ToDouble(this->dataGridView1->Rows[i]->Cells[0]->Value);// конвертируем
		}
		//вызовем описанную нами функцию для заполнения массива М3
		this->compare(M1, M2, M3);
		// внесём данные из М3 в результирующую таблицу
		for (int i = 0; i < 4; i++) {
			this->dataGridView3->Rows[i]->Cells[0]->Value = Convert::ToString(M3[i]);// конвертируем
		}
	}

// функция меняет местами последнюю строку и первый столбец заданного массива в задании 2
private:System::Void changerowcolumn(int **A, int n) {
	// тут можно сократить код и не выделять один массив при желании
	// выделим память под временные массивы
	int *B = new int[n];
	int *C = new int[n];

	// и сохраним в них последнюю строку 
	for (int i = 0; i < n; i++) {
		B[i] = A[n - 1][i];
	}
	//и первый столбец
	for (int i = 0; i < n; i++) {
		C[i] = A[i][0];
	}
	// запишем в последнюю строку первый столбец
	for (int i = 0; i < n; i++) {
		A[n - 1][i] = A[i][0];
	}
	//Вернем из временного массива назад строку на место столбца
	for (int i = 0; i < n; i++) {
		A[i][0] = B[i];
	}
	// и столбец на место строки (вот эту часть можно не делать если выделяется 1 массив для строки)
	for (int i = 0; i < n; i++) {
		A[n - 1][i] = C[i];
	}
	// освободим временные массивы
	free(B);
	free(C);
}

private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	// по строкам и по столбцам таблицы dataGridView4 заносим её в массив A[i][j]
	for (int i = 0; i <3; i++)
		for (int j = 0; j < 3; j++)
		{
			A1[i][j] = Convert::ToInt32(this->dataGridView4->Rows[i]->Cells[j]->Value);
		}
	// исходные массивы готовы к обработке нашей функцией
	changerowcolumn(A1, 3);// передаем массив и его размер
	changerowcolumn(B1, 4);// передаем массив и его размер
	// результат обработки переносим в таблицы dataGridView6 и dataGridView7
	// по строкам и по столбцам таблицы dataGridView6 заполняем её из массива A1[i][j]
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
		{
			this->dataGridView6->Rows[i]->Cells[j]->Value = Convert::ToString(A1[i][j]);// преобразуем в строку
		}
	// по строкам и по столбцам таблицы dataGridView7 заполняем её из массива B1[i][j]
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
		{
			this->dataGridView7->Rows[i]->Cells[j]->Value = Convert::ToString(B1[i][j]);// преобразуем в строку
		}
	}
// функция выделяет слова из строки в listBox1 для задания 3
private: void getWords(String ^s) {
	const wchar_t *sep = L" ";// зададим разделитель
	s->Trim();// обрежем лишние пробелы в начале и конце строки
	s += " ";//в конце один пробел нам нужен для упрощения алгоритма
	String^ ts = "";// переменная для текущего слова 
	for (int i = 0; i < s->Length; i++) {// по всем символам исходной строки
		if (s[i] == *sep) {//если текущий символ есть разделитель значит слово закончилось
			if (ts != "") {// проверяем не пустая ли строка слова
				listBox1->Items->Add(ts);// добавляем слово в список
			}
			ts = "";// обнулим новое слово
		}
		else {
			ts += s[i];// если не разделитель то добавляем к текущему слову этот символ
		}
	}
}
// проверяем слово на то что оно читается одинаково
	private: bool palindrom(String ^w) {
		if (w->Length == 1) { return false; }// не считаем слова из одного символа
		int len = w->Length;// сохраним длину слова
		for (int i = 0; i < len / 2; i++) {// просматриваем слово с начала и с конца посимвольно
			if (w[i] != w[len - 1 - i]) {// сравниваем, как только несовпадение - это не палиндром
				return false; // завершаем функцию, это не палиндром
			}
		}
		return true;// если дошли сюда, то это палиндром
	}

private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
	listBox1->Items->Clear();// очищаем поля вывода
	listBox2->Items->Clear();// очищаем поля вывода
	if (textBox1->Text->Length >80) {// проверяем превышение длины строки по условию
		listBox2->Items->Add("Длина строки более 80");// выводим сообщение
	}
	if (textBox1->Text->Length ==0) {// проверяем пустую строку
		listBox2->Items->Add("Длина строки равна 0");// выводим сообщение
	}
	textBox1->Text = " " + textBox1->Text + " ";// добавляем служебные пробелы
	getWords(textBox1->Text);// разделяем на слова в список слов
	for (int i = 0; i < listBox1->Items->Count; i++) {// по всем словам списка проверяем их
		//если палиндром - добавляем в список палиндромов
		if (palindrom(listBox1->Items[i]->ToString())){ 
			listBox2->Items->Add( listBox1->Items[i]->ToString());
		}
	}
	// выводим сообщение об отсутствии палиндромов при необходимости
	if (listBox2->Items->Count == 0) { listBox2->Items->Add("Отсутствуют палиндромы"); }
}
};
}
