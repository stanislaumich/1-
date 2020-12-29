#pragma once
#include <string>

using std::string;

namespace MyWork {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>


	struct list
	{
		char* name; // поле данных марка авто
		char* nomer; // поле данных номер авто

		struct list *ptrnext; // указатель на следующий элемент
		struct list *ptrprev; // указатель на предыдущий элемент
	};

	list *ecur, *etemp, *efirst, *elast;


	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:

		list edel(list *ecur) {// проверить начало и конец списка
			list *tmp;

			if (ecur->ptrnext == NULL) {// конец списка
				ecur->ptrprev->ptrnext = NULL;
				tmp = ecur->ptrprev;
				free(ecur);
				return *tmp;
			}
			if (ecur->ptrprev == NULL) {// начало списка
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
			if (ecur->ptrnext == NULL){// конец списка				
				ecur->ptrnext = tmp;
				tmp->ptrprev = ecur;
				tmp->ptrnext = NULL;
				elast = tmp;
				return *tmp;
			}
			if (ecur->ptrprev == NULL) {// начало списка
				ecur->ptrprev = tmp;
				tmp->ptrprev = NULL;
				tmp->ptrnext = ecur;				
				efirst = tmp;
				return *tmp;
			}
			// середина списка после ecur
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
			s = (*ecur).name->ToString();
			textBox1->Text = s.ToString();// tmp->name.c_str();
			//label9->Text = ecur->ptrnext->name;

		}

		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
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
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
         // освободить память


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
			this->tabControl1 = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage2 = (gcnew System::Windows::Forms::TabPage());
			this->tabPage3 = (gcnew System::Windows::Forms::TabPage());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->tabPage4 = (gcnew System::Windows::Forms::TabPage());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
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
			this->tabControl1->Size = System::Drawing::Size(951, 325);
			this->tabControl1->TabIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Location = System::Drawing::Point(4, 22);
			this->tabPage1->Name = L"tabPage1";
			this->tabPage1->Padding = System::Windows::Forms::Padding(3);
			this->tabPage1->Size = System::Drawing::Size(1206, 561);
			this->tabPage1->TabIndex = 0;
			this->tabPage1->Text = L"Задание 1";
			this->tabPage1->UseVisualStyleBackColor = true;
			// 
			// tabPage2
			// 
			this->tabPage2->Controls->Add(this->label2);
			this->tabPage2->Location = System::Drawing::Point(4, 22);
			this->tabPage2->Name = L"tabPage2";
			this->tabPage2->Padding = System::Windows::Forms::Padding(3);
			this->tabPage2->Size = System::Drawing::Size(1206, 561);
			this->tabPage2->TabIndex = 1;
			this->tabPage2->Text = L"Задание 2";
			this->tabPage2->UseVisualStyleBackColor = true;
			// 
			// tabPage3
			// 
			this->tabPage3->Controls->Add(this->label3);
			this->tabPage3->Location = System::Drawing::Point(4, 22);
			this->tabPage3->Name = L"tabPage3";
			this->tabPage3->Padding = System::Windows::Forms::Padding(3);
			this->tabPage3->Size = System::Drawing::Size(1206, 561);
			this->tabPage3->TabIndex = 2;
			this->tabPage3->Text = L"Задание 3";
			this->tabPage3->UseVisualStyleBackColor = true;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(7, 3);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(91, 13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"Текст задания 1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(7, 3);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(91, 13);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Текст задания 2";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(7, 3);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(91, 13);
			this->label3->TabIndex = 0;
			this->label3->Text = L"Текст задания 3";
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
			this->tabPage4->Size = System::Drawing::Size(943, 299);
			this->tabPage4->TabIndex = 3;
			this->tabPage4->Text = L"Задание 4 (Списки)";
			this->tabPage4->UseVisualStyleBackColor = true;
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
			// button2
			// 
			this->button2->Location = System::Drawing::Point(795, 82);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(142, 23);
			this->button2->TabIndex = 2;
			this->button2->Text = L"Удалить элемент";
			this->button2->UseVisualStyleBackColor = true;
			// 
			// button3
			// 
			this->button3->Location = System::Drawing::Point(647, 82);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(142, 23);
			this->button3->TabIndex = 3;
			this->button3->Text = L"Сохранить изменения";
			this->button3->UseVisualStyleBackColor = true;
			// 
			// button4
			// 
			this->button4->Location = System::Drawing::Point(23, 264);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(142, 23);
			this->button4->TabIndex = 4;
			this->button4->Text = L"Загрузить из файла";
			this->button4->UseVisualStyleBackColor = true;
			// 
			// button5
			// 
			this->button5->Location = System::Drawing::Point(184, 264);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(142, 23);
			this->button5->TabIndex = 5;
			this->button5->Text = L"Сохранить в файл";
			this->button5->UseVisualStyleBackColor = true;
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
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(33, 56);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(119, 13);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Предыдущий элемент";
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
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(158, 56);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(35, 13);
			this->label8->TabIndex = 9;
			this->label8->Text = L"label8";
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
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(227, 84);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(245, 20);
			this->textBox1->TabIndex = 11;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(541, 84);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(100, 20);
			this->textBox2->TabIndex = 12;
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
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(478, 87);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(57, 13);
			this->label11->TabIndex = 14;
			this->label11->Text = L"Госномер";
			// 
			// button6
			// 
			this->button6->Location = System::Drawing::Point(647, 51);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(142, 23);
			this->button6->TabIndex = 15;
			this->button6->Text = L"Назад";
			this->button6->UseVisualStyleBackColor = true;
			// 
			// button7
			// 
			this->button7->Location = System::Drawing::Point(647, 113);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(142, 23);
			this->button7->TabIndex = 16;
			this->button7->Text = L"Вперёд";
			this->button7->UseVisualStyleBackColor = true;
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
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(357, 179);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(57, 13);
			this->label13->TabIndex = 18;
			this->label13->Text = L"Госномер";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(93, 176);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(258, 20);
			this->textBox3->TabIndex = 19;
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(420, 176);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(100, 20);
			this->textBox4->TabIndex = 20;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(216, 214);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(158, 23);
			this->button8->TabIndex = 21;
			this->button8->Text = L"Добавить после текущего";
			this->button8->UseVisualStyleBackColor = true;
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(380, 214);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(176, 23);
			this->button9->TabIndex = 22;
			this->button9->Text = L"Добавить элемент последним";
			this->button9->UseVisualStyleBackColor = true;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(955, 325);
			this->Controls->Add(this->tabControl1);
			this->Name = L"MyForm";
			this->Text = L"Микулич Станислав";
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

	
};
}
