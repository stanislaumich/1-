#pragma once
#include <string>
#include<malloc.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

using std::string;

namespace MyWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm
	/// </summary>


	struct list
	{
		char* name; // ���� ������ ����� ����
		char* nomer; // ���� ������ ����� ����

		struct list *ptrnext; // ��������� �� ��������� �������
		struct list *ptrprev; // ��������� �� ���������� �������
	};

	list *ecur, *etemp, *efirst, *elast;


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		list edel(list *ecur) {// ��������� ������ � ����� ������
			list *tmp;

			if (ecur->ptrnext == NULL) {// ����� ������
				ecur->ptrprev->ptrnext = NULL;
				tmp = ecur->ptrprev;
				free(ecur);
				return *tmp;
			}
			if (ecur->ptrprev == NULL) {// ������ ������
				ecur->ptrnext->ptrprev = NULL;
				tmp = ecur->ptrnext;
				free(ecur);
				return *tmp;
			}

			ecur->ptrnext->ptrprev = ecur->ptrprev;
			ecur->ptrprev->ptrnext = ecur->ptrnext;
			tmp = ecur->ptrnext;
			free(ecur);
			return *tmp;
		};

		list eins(list *ecur, char* name, char* nomer) {
			list *tmp;
			tmp = (struct list*)malloc(sizeof(struct list));
			tmp->name = name;
			tmp->nomer = nomer;
			if (ecur->ptrnext == NULL){// ����� ������				
				ecur->ptrnext = tmp;
				tmp->ptrprev = ecur;
				tmp->ptrnext = NULL;
				elast = tmp;
				return *tmp;
			}
			if (ecur->ptrprev == NULL) {// ������ ������
				ecur->ptrprev = tmp;
				tmp->ptrprev = NULL;
				tmp->ptrnext = ecur;				
				efirst = tmp;
				return *tmp;
			}
			// �������� ������ ����� ecur
			tmp->ptrnext = ecur->ptrnext;
			ecur->ptrnext->ptrprev = tmp;
			ecur->ptrnext = tmp;
			tmp->ptrprev = ecur;
			return *tmp;
		};

		void eshow(list *ecur) {
			list tmp;
			tmp = *ecur;
			char* s;
			//label8->Text = ecur->ptrprev->name;
			//textBox1->Text = "2";// ecur->name;// ->ToString();
			//.s = (*ecur).name->ToString();
			//..textBox1->Text = s.ToString();// tmp->name.c_str();
			//label9->Text = ecur->ptrnext->name;

		}

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			efirst = (struct list*)malloc(sizeof(struct list));
			efirst->ptrprev = NULL;
			elast = (struct list*)malloc(sizeof(struct list));
			elast->ptrnext = NULL;
			efirst->ptrnext = elast;
			elast->ptrprev = efirst;
			//ecur = (struct list*)malloc(sizeof(struct list));
			ecur = efirst;
			efirst->name = "EMPTY";
			efirst->nomer = "EMPTY";
			elast->name = "EMPTY";
			elast->nomer = "EMPTY";
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm()
		{
         // ���������� ������


			free(elast);
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
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TabPage^  tabPage3;
	private: System::Windows::Forms::Label^  label3;
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

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
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
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label3 = (gcnew System::Windows::Forms::Label());
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
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->tabControl1->SuspendLayout();
			this->tabPage1->SuspendLayout();
			this->tabPage2->SuspendLayout();
			this->tabPage3->SuspendLayout();
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
			this->tabPage1->Text = L"������� 1";
			this->tabPage1->UseVisualStyleBackColor = true;
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
			this->label18->Text = L"����� �����:";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(496, 194);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(77, 13);
			this->label17->TabIndex = 10;
			this->label17->Text = L"����� �����:";
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(744, 28);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(149, 13);
			this->label16->TabIndex = 9;
			this->label16->Text = L"��������� ��� � ���������";
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(10, 147);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(205, 23);
			this->button11->TabIndex = 8;
			this->button11->Text = L"��������� ������� ��� ��������";
			this->button11->UseVisualStyleBackColor = true;
			this->button11->Click += gcnew System::EventHandler(this, &MyForm::button11_Click);
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(10, 108);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(480, 20);
			this->textBox7->TabIndex = 7;
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(7, 92);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(102, 13);
			this->label15->TabIndex = 6;
			this->label15->Text = L"�������� ������:";
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
			this->label14->Text = L"���������:";
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
			this->button10->Text = L"������������� ������";
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
			this->label1->Text = L"�������� �������, ������� ��� ��������� � �������� ��������� ������� ���� char ��"
				L"�������� ����� ����� ��� ��������� � �������� ��� ��������� ����� � �� ���� �\?�";
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(943, 408);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"������� 2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"����� ������� 2";
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label3);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(943, 408);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"������� 3";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"����� ������� 3";
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
			this->tabPage4->Text = L"������� 4 (������)";
			this->tabPage4->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(380, 214);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(176, 23);
			this->button9->TabIndex = 22;
			this->button9->Text = L"�������� ������� ���������";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(216, 214);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(158, 23);
			this->button8->TabIndex = 21;
			this->button8->Text = L"�������� ����� ��������";
			this->button8->UseVisualStyleBackColor = true;
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
			this->label13->Text = L"��������";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(33, 179);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(40, 13);
			this->label12->TabIndex = 17;
			this->label12->Text = L"�����";
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(647, 113);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(142, 23);
			this->button7->TabIndex = 16;
			this->button7->Text = L"�����";
			this->button7->UseVisualStyleBackColor = true;
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(647, 51);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(142, 23);
			this->button6->TabIndex = 15;
			this->button6->Text = L"�����";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(478, 87);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(57, 13);
			this->label11->TabIndex = 14;
			this->label11->Text = L"��������";
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(181, 87);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(40, 13);
			this->label10->TabIndex = 13;
			this->label10->Text = L"�����";
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
			this->label9->Size = System::Drawing::Size(35, 13);
			this->label9->TabIndex = 10;
			this->label9->Text = L"label9";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(158, 56);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 9;
			this->label8->Text = L"label8";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(40, 118);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(112, 13);
			this->label7->TabIndex = 8;
			this->label7->Text = L"��������� �������";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(33, 56);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(119, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"���������� �������";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(54, 87);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(98, 13);
			this->label5->TabIndex = 6;
			this->label5->Text = L"������� �������";
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(184, 264);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(142, 23);
			this->button5->TabIndex = 5;
			this->button5->Text = L"��������� � ����";
			this->button5->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(23, 264);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(142, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"��������� �� �����";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(647, 82);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(142, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"��������� ���������";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(795, 82);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(142, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"������� �������";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(23, 214);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(187, 23);
			this->button1->TabIndex = 1;
			this->button1->Text = L"�������� ������� ������";
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
			this->label4->Text = L"������ �� �������� ��������� �� ������� �����������";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(10, 191);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(480, 20);
			this->textBox8->TabIndex = 14;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(10, 226);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(480, 20);
			this->textBox9->TabIndex = 15;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(955, 434);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"������� ���������";
			this->tabControl1->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			this->tabPage2->ResumeLayout(false);
			this->tabPage2->PerformLayout();
			this->tabPage3->ResumeLayout(false);
			this->tabPage3->PerformLayout();
			this->tabPage4->ResumeLayout(false);
			this->tabPage4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	}

			 char c;
			 char *N1;
			 char *N2;
			 int lN1;
			 int lN2;

/*
��� �������, ������������� ��� ��������, ���������� �����
������ �������, �. �. � ��������������� �������
M1 = &�1[].
����� k-�� �������� ������� � ������������ �� ������� �+ �,
�+ �=&�[�].
��������������, ������ � �������� � �-�� �������� ������� �
����� ���� ����������� � ���� *� � *(�+ �).
���������������� ������� ��������� � ������� ����� ����
����������� � ������� ������ ���� �����, ������� �� �����-
���������� �� ������� ��������� ������� �:
int M[5\, i, * �, * plast;
//������� 1 � ������������� ��������:
for (/= 0; /<5; /++);
M[i] = 0. //������� 2 � ������������� �������� �
����������: for (i= 0; /<5; /'++);
*(M+i) = 0. //������� 3 � �������������
����������: for (p-M, plast = � + 4; � <= plast; p
++)
*� = 0; // �+ 4 � ����� ���������� �������� ������� �.
��� �������� ������� � ������� ������������� �������� �
��������� ����� ������ ������� � ���������� ��������� � ���-
����, � ������ ���� ������� �������� � ���������� �������, ��-
������� ���������. �������� ������ ������������ �����������
������� �������, ������� ����� �������� � ��������� �����-
�������� �������.



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
// �������� ������ � ������������� ������ 1
	lN1 = Convert::ToInt32(textBox6->Text);
	free(N1);
	N1 = (char*)malloc(lN1*sizeof(char));
	srand(time(0));
	textBox5->Text = "";
	for (int i = 0; i < lN1; i++) {
		N1[i] = (char)((rand()%93  + 33));
		textBox5->Text += Convert::ToChar(N1[i]);
	}
// �������� ������ � ��������� ������ 2
 lN2= textBox7->Text->Length;
  free(N2);
  N2 = (char*)malloc(lN2 * sizeof(char));
  for (int i = 0; i < lN2; i++) {
	  N2[i] = Convert::ToChar(textBox7->Text[i]);
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


};
}
