#pragma once
#include "MyForm4.h"
#include "Client.h"
#include "Server.h"
#include "MyForm.h"

namespace Pentago {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Threading;

	/// <summary>
	/// Сводка для MutliplayerConnection
	/// </summary>
	public ref class MutliplayerConnection : public System::Windows::Forms::Form
	{
	public:
		MutliplayerConnection(void)
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
		~MutliplayerConnection()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ clientBtn;
	private: System::Windows::Forms::Button^ serverBtn;
	private: System::Windows::Forms::Button^ botBtn;
	private: System::Windows::Forms::Button^ button1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Label^ ipLabel;
	private: System::Windows::Forms::TextBox^ ipTextBox;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;


	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MutliplayerConnection::typeid));
			this->clientBtn = (gcnew System::Windows::Forms::Button());
			this->serverBtn = (gcnew System::Windows::Forms::Button());
			this->botBtn = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->ipLabel = (gcnew System::Windows::Forms::Label());
			this->ipTextBox = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// clientBtn
			// 
			this->clientBtn->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->clientBtn->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->clientBtn->Location = System::Drawing::Point(-7, 299);
			this->clientBtn->Name = L"clientBtn";
			this->clientBtn->Size = System::Drawing::Size(105, 50);
			this->clientBtn->TabIndex = 0;
			this->clientBtn->Text = L"Клиент";
			this->clientBtn->UseVisualStyleBackColor = false;
			this->clientBtn->Click += gcnew System::EventHandler(this, &MutliplayerConnection::clientBtn_Click);
			// 
			// serverBtn
			// 
			this->serverBtn->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->serverBtn->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->serverBtn->Location = System::Drawing::Point(104, 299);
			this->serverBtn->Name = L"serverBtn";
			this->serverBtn->Size = System::Drawing::Size(108, 50);
			this->serverBtn->TabIndex = 1;
			this->serverBtn->Text = L"Сервер";
			this->serverBtn->UseVisualStyleBackColor = false;
			this->serverBtn->Click += gcnew System::EventHandler(this, &MutliplayerConnection::serverBtn_Click);
			// 
			// botBtn
			// 
			this->botBtn->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->botBtn->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->botBtn->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->botBtn->Location = System::Drawing::Point(834, 121);
			this->botBtn->Name = L"botBtn";
			this->botBtn->Size = System::Drawing::Size(177, 87);
			this->botBtn->TabIndex = 2;
			this->botBtn->Text = L"Игра с компьютером";
			this->botBtn->UseVisualStyleBackColor = false;
			this->botBtn->Click += gcnew System::EventHandler(this, &MutliplayerConnection::botBtn_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->button1->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(36, 40);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(144, 87);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Игра на одном устройстве";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MutliplayerConnection::button1_Click);
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(842, 98);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(159, 20);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Одиночная игра";
			this->label2->Click += gcnew System::EventHandler(this, &MutliplayerConnection::label2_Click);
			// 
			// button2
			// 
			this->button2->Anchor = System::Windows::Forms::AnchorStyles::None;
			this->button2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button2->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(434, 448);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(179, 91);
			this->button2->TabIndex = 6;
			this->button2->Text = L"Выход";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MutliplayerConnection::button2_Click);
			// 
			// ipLabel
			// 
			this->ipLabel->AutoSize = true;
			this->ipLabel->Location = System::Drawing::Point(165, 219);
			this->ipLabel->Name = L"ipLabel";
			this->ipLabel->Size = System::Drawing::Size(0, 16);
			this->ipLabel->TabIndex = 7;
			// 
			// ipTextBox
			// 
			this->ipTextBox->BackColor = System::Drawing::SystemColors::Info;
			this->ipTextBox->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->ipTextBox->Location = System::Drawing::Point(214, 151);
			this->ipTextBox->Name = L"ipTextBox";
			this->ipTextBox->Size = System::Drawing::Size(289, 27);
			this->ipTextBox->TabIndex = 8;
			this->ipTextBox->Text = L"\r\n\r\n";
			this->ipTextBox->TextChanged += gcnew System::EventHandler(this, &MutliplayerConnection::ipTextBox_TextChanged);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->label3->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(212, 121);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(254, 20);
			this->label3->TabIndex = 9;
			this->label3->Text = L"Введите IP-адрес сервера";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label4->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(25, 276);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(155, 20);
			this->label4->TabIndex = 10;
			this->label4->Text = L"Локальная игра";
			this->label4->Click += gcnew System::EventHandler(this, &MutliplayerConnection::label4_Click);
			// 
			// MutliplayerConnection
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ClientSize = System::Drawing::Size(1023, 551);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->ipTextBox);
			this->Controls->Add(this->ipLabel);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->botBtn);
			this->Controls->Add(this->serverBtn);
			this->Controls->Add(this->clientBtn);
			this->Name = L"MutliplayerConnection";
			this->Text = L"Выбрать режим";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

		private:
			System::String^ ip;

	private: System::Void clientBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		auto game = gcnew Game(4, 3);
		game->initClient(this->ipTextBox->Text); // инициализация клиента

		MyForm4(game).ShowDialog(); // открытие клиенту игры
	}

	private: System::Void initServer() {
		auto game = gcnew Game(4, 3);
		game->initServer(this->ip);

		Hide();
		MyForm4(game).ShowDialog();
	}

	private: System::Void botBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		auto game = gcnew Game(4, 3);
		game->initBot(); // игра с ботом

		Hide();
		MyForm4(game).ShowDialog();
	}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		MyForm4 MyForm4;
		MyForm4.ShowDialog();
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
		/*MyForm^ f = gcnew MyForm();
		f->ShowDialog();*/
	}
	private: System::Void serverBtn_Click(System::Object^ sender, System::EventArgs^ e) {
		// сетевая игра
		this->ip = getIp();
		ipLabel->Text = ip;
		ipTextBox->Text = ip;
		Thread(gcnew ThreadStart(this, &MutliplayerConnection::initServer)).Start();
	}
	private: System::Void ipTextBox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}
