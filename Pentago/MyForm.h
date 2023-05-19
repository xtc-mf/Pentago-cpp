#pragma once
#include "MyForm1.h"
#include "MyForm2.h"
#include "MyForm3.h"
#include "MyForm4.h"
#include "MutliplayerConnection.h"

namespace Pentago {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm()
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
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^ about;
	private: System::Windows::Forms::Button^ exit;
	private: System::Windows::Forms::Button^ multiplayerBtn;


	protected:

	protected:

	protected:

	protected:

	protected:

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->about = (gcnew System::Windows::Forms::Button());
			this->exit = (gcnew System::Windows::Forms::Button());
			this->multiplayerBtn = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// about
			// 
			this->about->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->about->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->about->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->about->ForeColor = System::Drawing::SystemColors::InfoText;
			this->about->Location = System::Drawing::Point(470, 201);
			this->about->Name = L"about";
			this->about->Size = System::Drawing::Size(291, 118);
			this->about->TabIndex = 1;
			this->about->Text = L"О программе";
			this->about->UseVisualStyleBackColor = false;
			this->about->Click += gcnew System::EventHandler(this, &MyForm::about_Click);
			// 
			// exit
			// 
			this->exit->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->exit->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->exit->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->exit->ForeColor = System::Drawing::SystemColors::InfoText;
			this->exit->Location = System::Drawing::Point(470, 370);
			this->exit->Name = L"exit";
			this->exit->Size = System::Drawing::Size(291, 118);
			this->exit->TabIndex = 2;
			this->exit->Text = L"Выход";
			this->exit->UseVisualStyleBackColor = false;
			this->exit->Click += gcnew System::EventHandler(this, &MyForm::exit_Click);
			// 
			// multiplayerBtn
			// 
			this->multiplayerBtn->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->multiplayerBtn->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->multiplayerBtn->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.8F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->multiplayerBtn->ForeColor = System::Drawing::SystemColors::InfoText;
			this->multiplayerBtn->Location = System::Drawing::Point(470, 32);
			this->multiplayerBtn->Name = L"multiplayerBtn";
			this->multiplayerBtn->Size = System::Drawing::Size(291, 118);
			this->multiplayerBtn->TabIndex = 3;
			this->multiplayerBtn->Text = L"Играть";
			this->multiplayerBtn->UseVisualStyleBackColor = false;
			this->multiplayerBtn->Click += gcnew System::EventHandler(this, &MyForm::multiplayerBtn_Click);
			// 
			// MyForm
			// 
			this->AccessibleRole = System::Windows::Forms::AccessibleRole::IpAddress;
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1182, 553);
			this->Controls->Add(this->multiplayerBtn);
			this->Controls->Add(this->exit);
			this->Controls->Add(this->about);
			this->Name = L"MyForm";
			this->Text = L"Главное меню";
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void about_Click(System::Object^ sender, System::EventArgs^ e)
	{
		MyForm1().ShowDialog();
	}
	private: System::Void exit_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void button_start_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm4().ShowDialog();
	}
	private: System::Void multiplayerBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		Hide();
		MutliplayerConnection().ShowDialog();
	}

};
}