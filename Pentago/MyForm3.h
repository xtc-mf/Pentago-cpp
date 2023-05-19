#pragma once

namespace Pentago {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm3
	/// </summary>
	public ref class MyForm3 : public System::Windows::Forms::Form
	{
	public:
		MyForm3(void)
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
		~MyForm3()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:





	private: System::Windows::Forms::Label^ label4;


	private: System::Windows::Forms::Button^ rotate2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button3;


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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm3::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->rotate2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(348, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(415, 32);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Кнопка \"Повернуть (Rotate)\"";
			this->label1->Click += gcnew System::EventHandler(this, &MyForm3::label1_Click_1);
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(610, 41);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(0, 20);
			this->label4->TabIndex = 4;
			// 
			// rotate2
			// 
			this->rotate2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->rotate2->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rotate2->Location = System::Drawing::Point(506, 44);
			this->rotate2->Name = L"rotate2";
			this->rotate2->Size = System::Drawing::Size(91, 30);
			this->rotate2->TabIndex = 17;
			this->rotate2->Text = L"Rotate 2";
			this->rotate2->UseVisualStyleBackColor = false;
			this->rotate2->Click += gcnew System::EventHandler(this, &MyForm3::rotate2_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(479, 457);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(190, 93);
			this->button1->TabIndex = 18;
			this->button1->Text = L"Я прочитал(а)";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm3::button1_Click_1);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(430, 119);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(239, 32);
			this->label2->TabIndex = 19;
			this->label2->Text = L"Алгоритм ходов\r\n";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm3::label2_Click_1);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button2->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(506, 154);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(91, 30);
			this->button2->TabIndex = 20;
			this->button2->Text = L"Ходы";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm3::button2_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(379, 228);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(344, 32);
			this->label3->TabIndex = 21;
			this->label3->Text = L"Кнопка \"Правила игры\"";
			// 
			// button3
			// 
			this->button3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button3->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->Location = System::Drawing::Point(499, 263);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(106, 30);
			this->button3->TabIndex = 22;
			this->button3->Text = L"Правила";
			this->button3->UseVisualStyleBackColor = false;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm3::button3_Click);
			// 
			// MyForm3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1099, 562);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->rotate2);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm3";
			this->Text = L"Справка";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void label1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void rotate2_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(L"Данная кнопка позволяет повернуть платформу вправо на 90 градусов.");
}
private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(L"Нажмите на любое свободное место на платформах, после чего поверните платформу с помощью кнопки.");
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
	MessageBox::Show(L"Данная кнопка поможет узнать правила");
}
};
}
