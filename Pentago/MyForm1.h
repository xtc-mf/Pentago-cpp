#pragma once
#include <iostream>
#include "MyForm3.h"
#include "MyForm6.h"
#include "MyForm.h"

namespace Pentago {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm1
	/// </summary>
	public ref class MyForm1 : public System::Windows::Forms::Form
	{
	public:
		MyForm1(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button_start;

	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;

	protected:

	protected:

	protected:

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
			this->button_start = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// button_start
			// 
			this->button_start->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button_start->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button_start->ForeColor = System::Drawing::SystemColors::InfoText;
			this->button_start->Location = System::Drawing::Point(12, 11);
			this->button_start->Name = L"button_start";
			this->button_start->Size = System::Drawing::Size(350, 131);
			this->button_start->TabIndex = 1;
			this->button_start->Text = L"Правила игры";
			this->button_start->UseVisualStyleBackColor = false;
			this->button_start->Click += gcnew System::EventHandler(this, &MyForm1::button_start_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button2->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->ForeColor = System::Drawing::SystemColors::InfoText;
			this->button2->Location = System::Drawing::Point(12, 163);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(350, 131);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Справка";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm1::button2_Click);
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button3->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::SystemColors::InfoText;
			this->button3->Location = System::Drawing::Point(12, 440);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(350, 102);
			this->button3->TabIndex = 4;
			this->button3->Text = L"Выход";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm1::button3_Click);
			// 
			// MyForm1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 15);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(379, 586);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button_start);
			this->Font = (gcnew System::Drawing::Font(L"Rockwell", 7.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Name = L"MyForm1";
			this->Text = L"О программе:";
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button_start_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		MyForm6().ShowDialog();
	}
	private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		Hide();
		MyForm3().ShowDialog();
	}
	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	};
}
