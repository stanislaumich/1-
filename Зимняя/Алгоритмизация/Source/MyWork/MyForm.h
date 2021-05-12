#pragma once
#include <string>
#include<malloc.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fstream>



using std::string;
using std::ios;

namespace MyWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::IO;

	std::ofstream OF;
	std::ifstream IF;

	struct list
	{
		string name; // поле данных марка авто
		string nomer; // поле данных номер авто
		struct list *ptrnext; // указатель на следующий элемент
		struct list *ptrprev; // указатель на предыдущий элемент
	};

	struct olymp {
		string country;
		int gold;
		int silver;
		int bronze;
		int ball;
		int kolvo;
		int mesto;
	};

	list *ecur, *etemp, *efirst, *elast;
	int **A;
	int **B;

	olymp *olympa;
	int olympn;

	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			efirst = new list();
			efirst->ptrprev = NULL;
			efirst->ptrnext = NULL;
			efirst->name = "EMPTY";
			efirst->nomer = "EMPTY";
			elast = efirst;
			ecur = efirst;

			dataGridView1->RowCount = 4;
			dataGridView2->RowCount = 3;
			dataGridView3->RowCount = 4;
			dataGridView4->RowCount = 3;

			A= new int*[4];
			for (int i=0;i<4;i++){A[i]= new int[4];}
			B = new int*[3];
			for (int i = 0; i<3; i++) { B[i] = new int[3]; }
			int T[9] = { 4,2,7,-1,-5,-7,9,4,1 };
			int c = 0;
			for (int i = 0; i < 3; i++) {
				for (int j = 0; j < 3; j++) {
					B[i][j] = T[c++];
					this->dataGridView2->Rows[i]->Cells[j]->Value = Convert::ToString(B[i][j]);
			 }
			}
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
         // освободить память


			/*ecur = efirst;
			while (ecur != NULL)
			{
				ecur = ecur->ptrnext;
				free(ecur->ptrprev);
			}
			*/

			free(efirst);




			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl1;
	protected:
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::TabPage^  tabPage2;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::TabPage^  tabPage4;
	private: System::Windows::Forms::Button^  button9;
	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label4;
private: System::Windows::Forms::Label^  label16;
private: System::Windows::Forms::Button^  button11;
private: System::Windows::Forms::TextBox^  textBox7;
private: System::Windows::Forms::Label^  label15;
private: System::Windows::Forms::TextBox^  textBox6;
private: System::Windows::Forms::Label^  label14;
private: System::Windows::Forms::TextBox^  textBox5;
private: System::Windows::Forms::Button^  button10;
private: System::Windows::Forms::Label^  label20;
private: System::Windows::Forms::Label^  label19;
private: System::Windows::Forms::Label^  label18;
private: System::Windows::Forms::Label^  label17;
private: System::Windows::Forms::TextBox^  textBox9;
private: System::Windows::Forms::TextBox^  textBox8;
private: System::Windows::Forms::RichTextBox^  richTextBox1;
private: System::Windows::Forms::RichTextBox^  richTextBox2;
private: System::Windows::Forms::DataGridView^  dataGridView4;
private: System::Windows::Forms::DataGridView^  dataGridView3;
private: System::Windows::Forms::Button^  button12;
private: System::Windows::Forms::DataGridView^  dataGridView2;
private: System::Windows::Forms::DataGridView^  dataGridView1;
private: System::Windows::Forms::Label^  label22;
private: System::Windows::Forms::Label^  label21;
private: System::Windows::Forms::Label^  label3;
private: System::Windows::Forms::Label^  label2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column51;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column52;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column53;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column4;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  CB1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  CB2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  CB3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  C1;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  C2;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  C3;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  C4;
private: System::Windows::Forms::Button^  button13;
private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
private: System::Windows::Forms::Button^  button15;
private: System::Windows::Forms::Button^  button14;
private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
private: System::Windows::Forms::DataGridView^  dataGridView5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column5;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column7;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column8;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column9;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column10;
private: System::Windows::Forms::DataGridView^  dataGridView6;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column11;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column12;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column13;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column14;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column15;
private: System::Windows::Forms::DataGridViewTextBoxColumn^  Column16;


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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->label20 = (gcnew System::Windows::Forms::Label());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button10 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView4 = (gcnew System::Windows::Forms::DataGridView());
			this->Column51 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column52 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column53 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView3 = (gcnew System::Windows::Forms::DataGridView());
			this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button12 = (gcnew System::Windows::Forms::Button());
			this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			this->CB1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CB2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->CB3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->C1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->C4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label22 = (gcnew System::Windows::Forms::Label());
			this->label21 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->richTextBox1 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->dataGridView6 = (gcnew System::Windows::Forms::DataGridView());
			this->Column11 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column12 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column13 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column14 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column15 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column16 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->dataGridView5 = (gcnew System::Windows::Forms::DataGridView());
			this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button15 = (gcnew System::Windows::Forms::Button());
			this->button14 = (gcnew System::Windows::Forms::Button());
			this->button13 = (gcnew System::Windows::Forms::Button());
			this->richTextBox2 = (gcnew System::Windows::Forms::RichTextBox());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			this->tabPage3->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->BeginInit();
			this->tabPage4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl1
			// 
			this->tabControl1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->tabControl1->Controls->Add(this->tabPage1);
			this->tabControl1->Controls->Add(this->tabPage2);
			this->tabControl1->Controls->Add(this->tabPage3);
			this->tabControl1->Controls->Add(this->tabPage4);
			this->tabControl1->Location = System::Drawing::Point(1, 1);
			this->tabControl1->Margin = System::Windows::Forms::Padding(1);
			this->tabControl1->Name = L"tabControl1";
			this->tabControl1->SelectedIndex = 0;
			this->tabControl1->Size = System::Drawing::Size(951, 434);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->textBox9);
			this->tabPage1->Controls->Add(this->textBox8);
			this->tabPage1->Controls->Add(this->label20);
			this->tabPage1->Controls->Add(this->label19);
			this->tabPage1->Controls->Add(this->label18);
			this->tabPage1->Controls->Add(this->label17);
			this->tabPage1->Controls->Add(this->label16);
			this->tabPage1->Controls->Add(this->button11);
			this->tabPage1->Controls->Add(this->textBox7);
			this->tabPage1->Controls->Add(this->label15);
			this->tabPage1->Controls->Add(this->textBox6);
			this->tabPage1->Controls->Add(this->label14);
			this->tabPage1->Controls->Add(this->textBox5);
			this->tabPage1->Controls->Add(this->button10);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(943, 408);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Задание 1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(10, 226);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(480, 20);
			this->textBox9->TabIndex = 15;
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(10, 191);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(480, 20);
			this->textBox8->TabIndex = 14;
			// 
			// label20
			// 
			this->label20->AutoSize = true;
			this->label20->Location = System::Drawing::Point(579, 229);
			this->label20->Name = L"label20";
			this->label20->Size = System::Drawing::Size(13, 13);
			this->label20->TabIndex = 13;
			this->label20->Text = L"0";
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(579, 194);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(13, 13);
			this->label19->TabIndex = 12;
			this->label19->Text = L"0";
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(496, 229);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(77, 13);
			this->label18->TabIndex = 11;
			this->label18->Text = L"Сумма кодов:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(496, 194);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(77, 13);
			this->label17->TabIndex = 10;
			this->label17->Text = L"Сумма кодов:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(744, 28);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(149, 13);
			this->label16->TabIndex = 9;
			this->label16->Text = L"Условимся что а латинское";
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(10, 147);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(205, 23);
			this->button11->TabIndex = 8;
			this->button11->Text = L"Выполнить задание для массивов";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(10, 108);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(480, 20);
			this->textBox7->TabIndex = 7;
			this->textBox7->Text = L"asdaaassdfasdaaa";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(7, 92);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(102, 13);
			this->label15->TabIndex = 6;
			this->label15->Text = L"Заданный массив:";
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(78, 30);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(44, 20);
			this->textBox6->TabIndex = 5;
			this->textBox6->Text = L"40";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(7, 33);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(66, 13);
			this->label14->TabIndex = 4;
			this->label14->Text = L"Элементов:";
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(10, 57);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(480, 20);
			this->textBox5->TabIndex = 3;
			// 
			// button10
			// 
			this->button10->Location = System::Drawing::Point(128, 28);
			this->button10->Name = L"button10";
			this->button10->Size = System::Drawing::Size(141, 23);
			this->button10->TabIndex = 2;
			this->button10->Text = L"Сгенерировать массив";
			this->button10->UseVisualStyleBackColor = true;
			this->button10->Click += gcnew System::EventHandler(this, &MyForm::button10_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(898, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Написать функцию, которая для заданного в качестве параметра массива типа char во"
				L"звращает сумму кодов его элементов и заменяет все вхождения буквы а на знак «\?»";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->dataGridView4);
			this->tabPage2->Controls->Add(this->dataGridView3);
			this->tabPage2->Controls->Add(this->button12);
			this->tabPage2->Controls->Add(this->dataGridView2);
			this->tabPage2->Controls->Add(this->dataGridView1);
			this->tabPage2->Controls->Add(this->label22);
			this->tabPage2->Controls->Add(this->label21);
			this->tabPage2->Controls->Add(this->label3);
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Controls->Add(this->richTextBox1);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(943, 408);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Задание 2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// dataGridView4
			// 
			this->dataGridView4->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView4->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->Column51,
					this->Column52, this->Column53
			});
			this->dataGridView4->Location = System::Drawing::Point(705, 93);
			this->dataGridView4->Name = L"dataGridView4";
			this->dataGridView4->Size = System::Drawing::Size(155, 135);
			this->dataGridView4->TabIndex = 9;
			// 
			// Column51
			// 
			this->Column51->HeaderText = L"C1";
			this->Column51->Name = L"Column51";
			this->Column51->Width = 30;
			// 
			// Column52
			// 
			this->Column52->HeaderText = L"C2";
			this->Column52->Name = L"Column52";
			this->Column52->Width = 30;
			// 
			// Column53
			// 
			this->Column53->HeaderText = L"C3";
			this->Column53->Name = L"Column53";
			this->Column53->Width = 30;
			// 
			// dataGridView3
			// 
			this->dataGridView3->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView3->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->Column1,
					this->Column2, this->Column3, this->Column4
			});
			this->dataGridView3->Location = System::Drawing::Point(486, 93);
			this->dataGridView3->Name = L"dataGridView3";
			this->dataGridView3->Size = System::Drawing::Size(199, 135);
			this->dataGridView3->TabIndex = 8;
			// 
			// Column1
			// 
			this->Column1->HeaderText = L"C1";
			this->Column1->Name = L"Column1";
			this->Column1->Width = 30;
			// 
			// Column2
			// 
			this->Column2->HeaderText = L"C2";
			this->Column2->Name = L"Column2";
			this->Column2->Width = 30;
			// 
			// Column3
			// 
			this->Column3->HeaderText = L"C3";
			this->Column3->Name = L"Column3";
			this->Column3->Width = 30;
			// 
			// Column4
			// 
			this->Column4->HeaderText = L"C4";
			this->Column4->Name = L"Column4";
			this->Column4->Width = 30;
			// 
			// button12
			// 
			this->button12->Location = System::Drawing::Point(391, 93);
			this->button12->Name = L"button12";
			this->button12->Size = System::Drawing::Size(75, 23);
			this->button12->TabIndex = 7;
			this->button12->Text = L"Обработать";
			this->button12->UseVisualStyleBackColor = true;
			this->button12->Click += gcnew System::EventHandler(this, &MyForm::button12_Click);
			// 
			// dataGridView2
			// 
			this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {
				this->CB1, this->CB2,
					this->CB3
			});
			this->dataGridView2->Location = System::Drawing::Point(213, 93);
			this->dataGridView2->Name = L"dataGridView2";
			this->dataGridView2->Size = System::Drawing::Size(159, 135);
			this->dataGridView2->TabIndex = 6;
			// 
			// CB1
			// 
			this->CB1->HeaderText = L"C1";
			this->CB1->Name = L"CB1";
			this->CB1->Width = 30;
			// 
			// CB2
			// 
			this->CB2->HeaderText = L"C2";
			this->CB2->Name = L"CB2";
			this->CB2->Width = 30;
			// 
			// CB3
			// 
			this->CB3->HeaderText = L"C3";
			this->CB3->Name = L"CB3";
			this->CB3->Width = 30;
			// 
			// dataGridView1
			// 
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {
				this->C1, this->C2,
					this->C3, this->C4
			});
			this->dataGridView1->Location = System::Drawing::Point(7, 93);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->Size = System::Drawing::Size(191, 135);
			this->dataGridView1->TabIndex = 5;
			// 
			// C1
			// 
			this->C1->HeaderText = L"C1";
			this->C1->Name = L"C1";
			this->C1->Width = 30;
			// 
			// C2
			// 
			this->C2->HeaderText = L"C2";
			this->C2->Name = L"C2";
			this->C2->Width = 30;
			// 
			// C3
			// 
			this->C3->HeaderText = L"C3";
			this->C3->Name = L"C3";
			this->C3->Width = 30;
			// 
			// C4
			// 
			this->C4->HeaderText = L"C4";
			this->C4->Name = L"C4";
			this->C4->Width = 30;
			// 
			// label22
			// 
			this->label22->AutoSize = true;
			this->label22->Location = System::Drawing::Point(764, 67);
			this->label22->Name = L"label22";
			this->label22->Size = System::Drawing::Size(68, 13);
			this->label22->TabIndex = 4;
			this->label22->Text = L"Результат 2";
			// 
			// label21
			// 
			this->label21->AutoSize = true;
			this->label21->Location = System::Drawing::Point(551, 67);
			this->label21->Name = L"label21";
			this->label21->Size = System::Drawing::Size(68, 13);
			this->label21->TabIndex = 3;
			this->label21->Text = L"Результат 1";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(239, 67);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(108, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Исходный массив 2";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(42, 67);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(108, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Исходный массив 1";
			// 
			// richTextBox1
			// 
			this->richTextBox1->Location = System::Drawing::Point(7, 6);
			this->richTextBox1->Name = L"richTextBox1";
			this->richTextBox1->Size = System::Drawing::Size(930, 53);
			this->richTextBox1->TabIndex = 0;
			this->richTextBox1->Text = resources->GetString(L"richTextBox1.Text");
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->dataGridView6);
			this->tabPage3->Controls->Add(this->dataGridView5);
			this->tabPage3->Controls->Add(this->button15);
			this->tabPage3->Controls->Add(this->button14);
			this->tabPage3->Controls->Add(this->button13);
			this->tabPage3->Controls->Add(this->richTextBox2);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(943, 408);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Задание 3";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// dataGridView6
			// 
			this->dataGridView6->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView6->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column11,
					this->Column12, this->Column13, this->Column14, this->Column15, this->Column16
			});
			this->dataGridView6->Location = System::Drawing::Point(227, 232);
			this->dataGridView6->Name = L"dataGridView6";
			this->dataGridView6->Size = System::Drawing::Size(666, 167);
			this->dataGridView6->TabIndex = 5;
			// 
			// Column11
			// 
			this->Column11->HeaderText = L"Страна";
			this->Column11->Name = L"Column11";
			// 
			// Column12
			// 
			this->Column12->HeaderText = L"Золотых";
			this->Column12->Name = L"Column12";
			// 
			// Column13
			// 
			this->Column13->HeaderText = L"Серебряных";
			this->Column13->Name = L"Column13";
			// 
			// Column14
			// 
			this->Column14->HeaderText = L"Бронзовых";
			this->Column14->Name = L"Column14";
			// 
			// Column15
			// 
			this->Column15->HeaderText = L"Общее";
			this->Column15->Name = L"Column15";
			// 
			// Column16
			// 
			this->Column16->HeaderText = L"Очков";
			this->Column16->Name = L"Column16";
			// 
			// dataGridView5
			// 
			this->dataGridView5->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView5->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {
				this->Column5,
					this->Column6, this->Column7, this->Column8, this->Column9, this->Column10
			});
			this->dataGridView5->Location = System::Drawing::Point(227, 62);
			this->dataGridView5->Name = L"dataGridView5";
			this->dataGridView5->Size = System::Drawing::Size(667, 160);
			this->dataGridView5->TabIndex = 4;
			// 
			// Column5
			// 
			this->Column5->HeaderText = L"Страна";
			this->Column5->Name = L"Column5";
			// 
			// Column6
			// 
			this->Column6->HeaderText = L"Золотых";
			this->Column6->Name = L"Column6";
			// 
			// Column7
			// 
			this->Column7->HeaderText = L"Серебряных";
			this->Column7->Name = L"Column7";
			// 
			// Column8
			// 
			this->Column8->HeaderText = L"Бронзовых";
			this->Column8->Name = L"Column8";
			// 
			// Column9
			// 
			this->Column9->HeaderText = L"Общее ";
			this->Column9->Name = L"Column9";
			// 
			// Column10
			// 
			this->Column10->HeaderText = L"Очков";
			this->Column10->Name = L"Column10";
			// 
			// button15
			// 
			this->button15->Location = System::Drawing::Point(3, 91);
			this->button15->Name = L"button15";
			this->button15->Size = System::Drawing::Size(218, 23);
			this->button15->TabIndex = 3;
			this->button15->Text = L"Обработать";
			this->button15->UseVisualStyleBackColor = true;
			this->button15->Click += gcnew System::EventHandler(this, &MyForm::button15_Click);
			// 
			// button14
			// 
			this->button14->Location = System::Drawing::Point(116, 62);
			this->button14->Name = L"button14";
			this->button14->Size = System::Drawing::Size(105, 23);
			this->button14->TabIndex = 2;
			this->button14->Text = L"Сохранить файл";
			this->button14->UseVisualStyleBackColor = true;
			this->button14->Click += gcnew System::EventHandler(this, &MyForm::button14_Click);
			// 
			// button13
			// 
			this->button13->Location = System::Drawing::Point(3, 62);
			this->button13->Name = L"button13";
			this->button13->Size = System::Drawing::Size(107, 23);
			this->button13->TabIndex = 1;
			this->button13->Text = L"Загрузить файл";
			this->button13->UseVisualStyleBackColor = true;
			this->button13->Click += gcnew System::EventHandler(this, &MyForm::button13_Click);
			// 
			// richTextBox2
			// 
			this->richTextBox2->Location = System::Drawing::Point(3, 6);
			this->richTextBox2->Name = L"richTextBox2";
			this->richTextBox2->Size = System::Drawing::Size(934, 50);
			this->richTextBox2->TabIndex = 0;
			this->richTextBox2->Text = resources->GetString(L"richTextBox2.Text");
			// 
			// tabPage4
			// 
			this->tabPage4->Controls->Add(this->button9);
			this->tabPage4->Controls->Add(this->button8);
			this->tabPage4->Controls->Add(this->textBox4);
			this->tabPage4->Controls->Add(this->textBox3);
			this->tabPage4->Controls->Add(this->label13);
			this->tabPage4->Controls->Add(this->label12);
			this->tabPage4->Controls->Add(this->button7);
			this->tabPage4->Controls->Add(this->button6);
			this->tabPage4->Controls->Add(this->label11);
			this->tabPage4->Controls->Add(this->label10);
			this->tabPage4->Controls->Add(this->textBox2);
			this->tabPage4->Controls->Add(this->textBox1);
			this->tabPage4->Controls->Add(this->label9);
			this->tabPage4->Controls->Add(this->label8);
			this->tabPage4->Controls->Add(this->label7);
			this->tabPage4->Controls->Add(this->label6);
			this->tabPage4->Controls->Add(this->label5);
			this->tabPage4->Controls->Add(this->button5);
			this->tabPage4->Controls->Add(this->button4);
			this->tabPage4->Controls->Add(this->button3);
			this->tabPage4->Controls->Add(this->button2);
			this->tabPage4->Controls->Add(this->button1);
			this->tabPage4->Controls->Add(this->label4);
			this->tabPage4->Location = System::Drawing::Point(4, 22);
			this->tabPage4->Name = L"tabPage4";
			this->tabPage4->Padding = System::Windows::Forms::Padding(3);
			this->tabPage4->Size = System::Drawing::Size(943, 408);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Задание 4 (Списки)";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(380, 214);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(176, 23);
			this->button9->TabIndex = 22;
			this->button9->Text = L"Добавить элемент последним";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(216, 214);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(158, 23);
			this->button8->TabIndex = 21;
			this->button8->Text = L"Добавить после текущего";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(420, 176);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 20;
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(93, 176);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(258, 20);
			this->textBox3->TabIndex = 19;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(357, 179);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(57, 13);
			this->label13->TabIndex = 18;
			this->label13->Text = L"Госномер";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(33, 179);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(40, 13);
			this->label12->TabIndex = 17;
			this->label12->Text = L"Марка";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(647, 113);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(142, 23);
			this->button7->TabIndex = 16;
			this->button7->Text = L"Вперёд";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &MyForm::button7_Click);
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(647, 51);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(142, 23);
			this->button6->TabIndex = 15;
			this->button6->Text = L"Назад";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(478, 87);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(57, 13);
			this->label11->TabIndex = 14;
			this->label11->Text = L"Госномер";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(181, 87);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(40, 13);
			this->label10->TabIndex = 13;
			this->label10->Text = L"Марка";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(541, 84);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 12;
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(227, 84);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(245, 20);
			this->textBox1->TabIndex = 11;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(158, 118);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(45, 13);
			this->label9->TabIndex = 10;
			this->label9->Text = L"ПУСТО";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(158, 56);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(45, 13);
			this->label8->TabIndex = 9;
			this->label8->Text = L"ПУСТО";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(40, 118);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(112, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"Следующий элемент";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(33, 56);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(119, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Предыдущий элемент";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(54, 87);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(98, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"Текущий элемент";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(184, 264);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(142, 23);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Сохранить в файл";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(23, 264);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(142, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Загрузить из файла";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(647, 82);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(142, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Сохранить изменения";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(795, 82);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(142, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Удалить элемент";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(23, 214);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(187, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Добавить элемент первым";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(7, 3);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(301, 13);
			this->label4->TabIndex = 0;
			this->label4->Text = L"Работа со списками элементов на примере автомобилей";
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(955, 434);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"Микулич Станислав";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			this->tabPage3->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView5))->EndInit();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	

			 char c;
			 char *N1;
			 char *N2;
			 int lN1;
			 int lN2;

/*
Имя массива, употребленное без индексов, определяет адрес
начала массива, т. е. в рассматриваемом примере
M1 = &М1[].
Адрес k-го элемента массива М определяется по формуле М+ К,
М+ К=&М[к].
Соответственно, доступ к нулевому и к-му элементу массива М
может быть осуществлен в виде *М и *(М+ к).
Последовательный перебор элементов в массиве может быть
осуществлен с помощью циклов трех видов, которые мы проил-
люстрируем на примере обнуления массива М:
int M[5\, i, * р, * plast;
//Вариант 1 — использование индексов:
for (/= 0; /<5; /++);
M[i] = 0. //Вариант 2 — использование индексов и
указателей: for (i= 0; /<5; /'++);
*(M+i) = 0. //Вариант 3 — использование
указателей: for (p-M, plast = М + 4; р <= plast; p
++)
*р = 0; // М+ 4 — адрес последнего элемента массива М.
Для передачи массива в функцию рекомендуется передать в
последнюю адрес начала массива и количество элементов в мас-
сиве, а внутри тела функции работать с элементами массива, ис-
пользуя указатели. Подобный подход обеспечивает возможность
строить функции, которые могут работать с массивами произ-
вольного размера.

*/	

private: System::Int32 mainwork(char *N, int len) {
	Int32 c = 0;
	for (int i = 0; i < len; i++) {
		N[i] == 'a' ? N[i] = '?' : N[i] = N[i];
		c += (int)N[i];
	}
	return c;
}
private: System::Void button10_Click(System::Object^  sender, System::EventArgs^  e) {
// выделить память и сгенерировать массив 1
	lN1 = Convert::ToInt32(textBox6->Text);
	//free(N1);
	N1 = new char[lN1];//(char*)malloc(lN1*sizeof(char));
	srand(time(0));
	textBox5->Text = "";
	for (int i = 0; i < lN1; i++) {
		N1[i] = (char)((rand()%(126-97)  + 97));
		textBox5->Text += Convert::ToChar(N1[i]);
	}
// выделить память и заполнить массив 2
 lN2= textBox7->Text->Length;
  N2 = new char[lN2];
  for (int i = 0; i < lN2; i++) {
	  N2[i] = textBox7->Text[i];
  }
}
private: System::Void button11_Click(System::Object^  sender, System::EventArgs^  e) {	
	Int32 rN1 =  mainwork(N1, lN1);
	Int32 rN2 = mainwork(N2, lN2);
	label19->Text= Convert::ToString(rN1);
	label20->Text = Convert::ToString(rN2);

	textBox8->Text = "";
	for (int i = 0; i < lN1; i++) {
		textBox8->Text += Convert::ToChar(N1[i]);
	}
	textBox9->Text = "";
	for (int i = 0; i < lN2; i++) {
		textBox9->Text += Convert::ToChar(N2[i]);
	}
	free(N1);
	free(N2);
}
private:System::Void transmatrix(int **A,int n) {
	// выделим память под временные массивы
	int *B= new int[n];
	int *C = new int[n];

    // и сохраним в них последнюю строку 
	for (int i = 0; i < n; i++) {
		B[i] = A[n-1][i];
	}
	//и первый столбец
	for (int i = 0; i < n; i++) {
		C[i] = A[i][0];
	}
	// запишем в последнюю строку первый столбец
	// потеряем первый элемент, но его всё равно потом стирать
	for (int i = 0; i < n; i++) {
		A[n-1][i] = A[i][0];
	}
	//Вернем из временного массива назад строку на место столбца
	for (int i = 0; i < n; i++) {
		A[i][0] = B[i];
	}
	// и столбец на место строки
	for (int i = 0; i < n; i++) {
		A[n-1][i] = C[i];
	}
    // всё, освободим временный массив
	free(B);
	free(C);
}
private: System::Void button12_Click(System::Object^  sender, System::EventArgs^  e) {
// по строкам и по столбцам таблицы dataGridView1 заносим её в массив A[i][j]
for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		A[i][j] = Convert::ToInt32(this->dataGridView1->Rows[i]->Cells[j]->Value);
	}
// по строкам и по столбцам таблицы dataGridView2 заносим её в массив B[i][j]
for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	{
		B[i][j] = Convert::ToInt32(this->dataGridView2->Rows[i]->Cells[j]->Value);
	}
// исходные массивы готовы к обработке нашей функцией
transmatrix(A, 4);
transmatrix(B, 3);
// результат обработки переносим в таблицы dataGridView3 и dataGridView4
// по строкам и по столбцам таблицы dataGridView1 заполняем её из массива A[i][j]
for (int i = 0; i < 4; i++)
	for (int j = 0; j < 4; j++)
	{
		this->dataGridView3->Rows[i]->Cells[j]->Value = Convert::ToString(A[i][j]);
	}
// по строкам и по столбцам таблицы dataGridView2 заполняем её из массива B[i][j]
for (int i = 0; i < 3; i++)
	for (int j = 0; j < 3; j++)
	{
		this->dataGridView4->Rows[i]->Cells[j]->Value = Convert::ToString(B[i][j]);
	}

// освобождаем занимаемую память
//free{arr41);
//free{arr42);
//free{arr31);
//free{arr32);

};
/*------------------------------- ЗАДАНИЕ 3 --------------------------------------*/
std::string ConvertToASCII(System::String^ _str)
		 {
			 if (_str == nullptr)
				 return std::string();
			 // Creating ASCII encoding (or smth. else)
			 System::Text::ASCIIEncoding^ enc = gcnew System::Text::ASCIIEncoding;
			 // Encoding source string
			 array<unsigned char>^ encodedBytes = enc->GetBytes(_str);
			 if (encodedBytes->Length == 0)
				 return std::string();
			 // Creating std::string
			 pin_ptr<unsigned char> pin(&encodedBytes[0]);
			 char *cstr(reinterpret_cast<char*>(static_cast<unsigned char*>(pin)));
			 return std::string(cstr, encodedBytes->Length);
		 }
private: System::Void button13_Click(System::Object^  sender, System::EventArgs^  e) {
	olymp country;
	//openFileDialog1->InitialDirectory = "c:\\";
	openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 1;
	openFileDialog1->RestoreDirectory = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		StreamReader^ preader = gcnew StreamReader(openFileDialog1->FileName);
		int i = 0;
			while (preader->Peek() >= 0)
		{
			dataGridView5->RowCount++;
			dataGridView5->Rows[i]->Cells[0]->Value= preader->ReadLine();
			dataGridView5->Rows[i]->Cells[1]->Value = preader->ReadLine();
			dataGridView5->Rows[i]->Cells[2]->Value = preader->ReadLine();
			dataGridView5->Rows[i++]->Cells[3]->Value = preader->ReadLine();			
		}
		preader->Close();
		
		olympn= dataGridView5->RowCount;
		olympa = new olymp[olympn];
		for (int i = 0; i < olympn-1; i++) {			
			olympa[i].country = ConvertToASCII(dataGridView5->Rows[i]->Cells[0]->Value->ToString());// "NO";
			olympa[i].gold = Convert::ToInt32(dataGridView5->Rows[i]->Cells[1]->Value);
			olympa[i].silver = Convert::ToInt32(dataGridView5->Rows[i]->Cells[2]->Value);
			olympa[i].bronze = Convert::ToInt32(dataGridView5->Rows[i]->Cells[3]->Value);
			olympa[i].kolvo = olympa[i].gold + olympa[i].silver + olympa[i].bronze;
			olympa[i].ball= olympa[i].gold*10 + olympa[i].silver*7 + olympa[i].bronze*3;
		}

	}
}//end of func
private: System::Void button14_Click(System::Object^  sender, System::EventArgs^  e) {
	olymp country;
	saveFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	saveFileDialog1->FilterIndex = 1;
	saveFileDialog1->RestoreDirectory = true;
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		StreamWriter^ pwriter = gcnew StreamWriter(saveFileDialog1->FileName);
		for (int i = 0; i < dataGridView5->RowCount-1; i++){
			pwriter->WriteLine(dataGridView5->Rows[i]->Cells[0]->Value->ToString());
			pwriter->WriteLine(dataGridView5->Rows[i]->Cells[1]->Value->ToString());
			pwriter->WriteLine(dataGridView5->Rows[i]->Cells[2]->Value->ToString());
			pwriter->WriteLine(dataGridView5->Rows[i]->Cells[3]->Value->ToString());
	}
	pwriter->Close();
	}	
}
void mswap(olymp a,olymp b) {
			 
		 }
void Sort(olymp* x, int size)
		 {
			 for (int i = 1; i < size-1; ++i)
				 for (int j = size - 2; j >= i; --j)
					 if (x[j - 1].ball < x[j].ball)
					 {
						 olymp tmp = x[j - 1];
						 x[j - 1] = x[j];
						 x[j] = tmp;
					 }
		 }
private: System::Void button15_Click(System::Object^  sender, System::EventArgs^  e) {
	int m, b;
	for (int i = 0; i < dataGridView5->RowCount - 1; i++) {
		m = Convert::ToInt32(dataGridView5->Rows[i]->Cells[1]->Value) +
			Convert::ToInt32(dataGridView5->Rows[i]->Cells[2]->Value) +
			Convert::ToInt32(dataGridView5->Rows[i]->Cells[3]->Value);
		dataGridView5->Rows[i]->Cells[4]->Value= Convert::ToString(m);
		b = Convert::ToInt32(dataGridView5->Rows[i]->Cells[1]->Value)*10 +
			Convert::ToInt32(dataGridView5->Rows[i]->Cells[2]->Value)*7 +
			Convert::ToInt32(dataGridView5->Rows[i]->Cells[3]->Value)*3;
		dataGridView5->Rows[i]->Cells[5]->Value = Convert::ToString(b);
	}// end for
	// sort
	Sort(olympa, olympn);
	//output	
	dataGridView6->RowCount = olympn;
	for (int i = 0; i < olympn-1; i++) {
		dataGridView6->Rows[i]->Cells[0]->Value = gcnew String(olympa[i].country.c_str());
		dataGridView6->Rows[i]->Cells[1]->Value = Convert::ToString(olympa[i].gold);
		dataGridView6->Rows[i]->Cells[2]->Value = Convert::ToString(olympa[i].silver);
		dataGridView6->Rows[i]->Cells[3]->Value = Convert::ToString(olympa[i].bronze);
		dataGridView6->Rows[i]->Cells[4]->Value = Convert::ToString(olympa[i].kolvo);
		dataGridView6->Rows[i]->Cells[5]->Value = Convert::ToString(olympa[i].ball);
	}
}
/*------------------------------- СПИСКИ --------------------------------------*/
list * edel(list *ecur) {// удаление записи
			 list *tmp;

			 if (ecur->ptrnext == NULL) {// конец списка
				 ecur->ptrprev->ptrnext = NULL;
				 tmp = ecur->ptrprev;
				 free(ecur);
				 return tmp;
			 }
			 if (ecur->ptrprev == NULL) {// начало списка
				 ecur->ptrnext->ptrprev = NULL;
				 tmp = ecur->ptrnext;
				 free(ecur);
				 return tmp;
			 }

			 ecur->ptrnext->ptrprev = ecur->ptrprev;
			 ecur->ptrprev->ptrnext = ecur->ptrnext;
			 tmp = ecur->ptrnext;
			 free(ecur);
			 return tmp;
		 };
list * leinsfirst(string name, string nomer) {
	 // начало вставки при загрузке из файла
	 efirst->name = name;
	 efirst->nomer = nomer;
	 return efirst;
 }
list * einsfirst(string name, string nomer) {
	 // вставка первой записи
	 etemp = new list();
	 etemp->ptrprev = NULL;
	 etemp->ptrnext = efirst;
	 etemp->name = name;
	 etemp->nomer = nomer;
	 efirst->ptrprev = etemp;
	 efirst = etemp;
	 return efirst;
 }
list * einslast(string name, string nomer) {
	 // вставка последней записи
	 etemp = new list();
	 etemp->name = name;
	 etemp->nomer = nomer;
	 etemp->ptrnext = NULL;
	 etemp->ptrprev = elast;
	 elast->ptrnext = etemp;
	 elast = etemp;
	 return elast;
 }
list * eins(list *ecur, string name, string nomer) {
	// вставка записи после текущего элемента
			 list *tmp= new list();
			 tmp->name = name;
			 tmp->nomer = nomer;
			 if (ecur->ptrnext == NULL) {// конец списка				
				 ecur->ptrnext = tmp;
				 tmp->ptrprev = ecur;
				 tmp->ptrnext = NULL;
				 elast = tmp;
				 return tmp;
			 }			 
			 // середина списка после ecur
			 tmp->ptrnext = ecur->ptrnext;
			 ecur->ptrnext->ptrprev = tmp;
			 ecur->ptrnext = tmp;
			 tmp->ptrprev = ecur;
			 return tmp;
		 };
void eshow(list *ecur) {
	// отображение текущей записи
			 textBox1->Text = gcnew String(ecur->name.c_str());
			 textBox2->Text = gcnew String(ecur->nomer.c_str());
			 if (ecur->ptrprev != NULL) {
				 label8->Text= gcnew String(ecur->ptrprev->name.c_str());
			 }
			 else
			 {
				 label8->Text = "Достигнуто начало списка";
			 }
			 if (ecur->ptrnext != NULL) {
				 label9->Text = gcnew String(ecur->ptrnext->name.c_str());
			 }
			 else
			 {
				 label9->Text = "Достигнут конец списка";
			 }

		 }
private: System::Void button4_Click(System::Object^  sender, System::EventArgs^  e) {
	// загрузка авто из файла
	list tcar;

	openFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	openFileDialog1->FilterIndex = 1;
	openFileDialog1->RestoreDirectory = true;
	if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		StreamReader^ preader = gcnew StreamReader(openFileDialog1->FileName);
		int i = 0;
		String^ tname;
		String^ tnomer;
		while (preader->Peek() >= 0)
		{			
			tname = preader->ReadLine();
			tnomer = preader->ReadLine();
			tcar.name = ConvertToASCII(tname);
			tcar.nomer = ConvertToASCII(tnomer);
			if (i == 0) { leinsfirst(tcar.name, tcar.nomer); }
			else { einslast(tcar.name, tcar.nomer); }
			i++;
		}
		preader->Close();
		eshow(efirst);	

	}

}
private: System::Void button7_Click(System::Object^  sender, System::EventArgs^  e) {
	//шаг к следующему
	if (ecur->ptrnext != NULL) {
		ecur = ecur->ptrnext;
		eshow(ecur);
	}
}
private: System::Void button6_Click(System::Object^  sender, System::EventArgs^  e) {
	// шаг к предыдущему
	if (ecur->ptrprev != NULL) {
		ecur = ecur->ptrprev;
		eshow(ecur);
	}
}
private: System::Void button3_Click(System::Object^  sender, System::EventArgs^  e) {
// изменить текущий
	ecur->name = ConvertToASCII(textBox1->Text);
	ecur->nomer = ConvertToASCII(textBox2->Text);
}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	// удалить текущий
	ecur = edel(ecur);
	eshow(ecur);
}
private: System::Void button8_Click(System::Object^  sender, System::EventArgs^  e) {
	// после текущего
	ecur = eins(ecur, ConvertToASCII(textBox3->Text), ConvertToASCII(textBox4->Text));
	eshow(ecur);
}
private: System::Void button9_Click(System::Object^  sender, System::EventArgs^  e) {
	// вставить последним
 ecur = einslast(ConvertToASCII(textBox3->Text), ConvertToASCII(textBox4->Text));
 eshow(ecur);
}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	// вставить первым
	ecur = einsfirst(ConvertToASCII(textBox3->Text), ConvertToASCII(textBox4->Text));
	eshow(ecur);
}
private: System::Void button5_Click(System::Object^  sender, System::EventArgs^  e) {
	// сохранить в файл
	saveFileDialog1->Filter = "txt files (*.txt)|*.txt|All files (*.*)|*.*";
	saveFileDialog1->FilterIndex = 1;
	saveFileDialog1->RestoreDirectory = true;
	if (saveFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
	{
		StreamWriter^ pwriter = gcnew StreamWriter(saveFileDialog1->FileName);
		String^ tname;
		String^ tnomer;
		ecur = efirst;
		while (ecur!=NULL)
		{
			pwriter->WriteLine(gcnew System::String(ecur->name.c_str()));
			pwriter->WriteLine(gcnew System::String(ecur->nomer.c_str()));
			ecur = ecur->ptrnext;
		}
		pwriter->Close();
	}
}
};
}
