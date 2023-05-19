#pragma once
#include <vector>
#include <random>
#include <fstream>
#include <string>
#include "MyForm.h"
#pragma comment(lib, "ws2_32.lib")
#include <winsock2.h>
#include <iostream>
#include "Game.h"

namespace Pentago {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� MyForm4
	/// </summary>
	public ref class MyForm4 : public System::Windows::Forms::Form
	{
	public:
		MyForm4(void) : MyForm4(gcnew Game(4, 3))
		{
		}

		MyForm4(Game^ game)
		{
			this->game = game;
			this->game->addFillHandler(gcnew System::EventHandler(this, &MyForm4::fillHandler));
			InitializeComponent();
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~MyForm4()
		{
			if (components)
			{
				delete components;
				delete game;
			}
		}

	protected:

	private: System::Windows::Forms::Button^ rotate1;
	private: System::Windows::Forms::Button^ rotate2;
	private: System::Windows::Forms::Button^ rotate3;
	private: System::Windows::Forms::Button^ rotate4;
	private: System::Windows::Forms::TableLayoutPanel^ gameContainer;
	private: bool isWhiteMove = true;






	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;
	private: System::Windows::Forms::Label^ movePlayerInfoLabel;
	private: System::Windows::Forms::Button^ button1;
		   Game^ game;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm4::typeid));
			this->rotate1 = (gcnew System::Windows::Forms::Button());
			this->rotate2 = (gcnew System::Windows::Forms::Button());
			this->rotate3 = (gcnew System::Windows::Forms::Button());
			this->rotate4 = (gcnew System::Windows::Forms::Button());
			this->gameContainer = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->movePlayerInfoLabel = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// rotate1
			// 
			this->rotate1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->rotate1->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rotate1->Location = System::Drawing::Point(10, 17);
			this->rotate1->Name = L"rotate1";
			this->rotate1->Size = System::Drawing::Size(91, 30);
			this->rotate1->TabIndex = 15;
			this->rotate1->Text = L"Rotate 1";
			this->rotate1->UseVisualStyleBackColor = false;
			this->rotate1->Click += gcnew System::EventHandler(this, &MyForm4::rotate1_Click);
			// 
			// rotate2
			// 
			this->rotate2->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->rotate2->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rotate2->Location = System::Drawing::Point(531, 17);
			this->rotate2->Name = L"rotate2";
			this->rotate2->Size = System::Drawing::Size(91, 30);
			this->rotate2->TabIndex = 16;
			this->rotate2->Text = L"Rotate 2";
			this->rotate2->UseVisualStyleBackColor = false;
			this->rotate2->Click += gcnew System::EventHandler(this, &MyForm4::rotate2_Click);
			// 
			// rotate3
			// 
			this->rotate3->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->rotate3->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rotate3->Location = System::Drawing::Point(12, 653);
			this->rotate3->Name = L"rotate3";
			this->rotate3->Size = System::Drawing::Size(89, 30);
			this->rotate3->TabIndex = 17;
			this->rotate3->Text = L"Rotate 3";
			this->rotate3->UseVisualStyleBackColor = false;
			this->rotate3->Click += gcnew System::EventHandler(this, &MyForm4::rotate3_Click);
			// 
			// rotate4
			// 
			this->rotate4->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->rotate4->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->rotate4->Location = System::Drawing::Point(533, 653);
			this->rotate4->Name = L"rotate4";
			this->rotate4->Size = System::Drawing::Size(89, 30);
			this->rotate4->TabIndex = 18;
			this->rotate4->Text = L"Rotate 4";
			this->rotate4->UseVisualStyleBackColor = false;
			this->rotate4->Click += gcnew System::EventHandler(this, &MyForm4::rotate4_Click);
			// 
			// gameContainer
			// 
			this->gameContainer->BackColor = System::Drawing::SystemColors::ActiveCaptionText;
			this->gameContainer->ColumnCount = 2;
			this->gameContainer->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->gameContainer->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->gameContainer->Location = System::Drawing::Point(10, 43);
			this->gameContainer->Name = L"gameContainer";
			this->gameContainer->RowCount = 2;
			this->gameContainer->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->gameContainer->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->gameContainer->Size = System::Drawing::Size(612, 612);
			this->gameContainer->TabIndex = 19;
			this->gameContainer->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm4::gameContainer_Paint);
			// 
			// movePlayerInfoLabel
			// 
			this->movePlayerInfoLabel->AutoSize = true;
			this->movePlayerInfoLabel->BackColor = System::Drawing::Color::Transparent;
			this->movePlayerInfoLabel->Font = (gcnew System::Drawing::Font(L"Comic Sans MS", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->movePlayerInfoLabel->ForeColor = System::Drawing::SystemColors::ControlLightLight;
			this->movePlayerInfoLabel->Location = System::Drawing::Point(652, 23);
			this->movePlayerInfoLabel->Name = L"movePlayerInfoLabel";
			this->movePlayerInfoLabel->Size = System::Drawing::Size(202, 28);
			this->movePlayerInfoLabel->TabIndex = 21;
			this->movePlayerInfoLabel->Text = L"����� ����� �����";
			this->movePlayerInfoLabel->Click += gcnew System::EventHandler(this, &MyForm4::movePlayerInfoLabel_Click);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button1->Font = (gcnew System::Drawing::Font(L"Rockwell", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(847, 569);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(172, 107);
			this->button1->TabIndex = 22;
			this->button1->Text = L"�����";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm4::button1_Click);
			// 
			// MyForm4
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1031, 695);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->rotate1);
			this->Controls->Add(this->movePlayerInfoLabel);
			this->Controls->Add(this->rotate2);
			this->Controls->Add(this->rotate4);
			this->Controls->Add(this->gameContainer);
			this->Controls->Add(this->rotate3);
			this->Name = L"MyForm4";
			this->Text = L"���������� ���� \"�������\"";
			this->Load += gcnew System::EventHandler(this, &MyForm4::MyForm4_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private: System::Drawing::Image^ getImageByIndex(int i) {
		if (i == 1) return Image::FromFile("Assets/player1.png"); // ���������� ����������� ��� 1-�� ������(������)
		if (i == 2) return Image::FromFile("Assets/player2.png"); // ���������� ����������� ��� 2-�� ������(�������)

		return Image::FromFile("Assets/empty.png"); // ���������� ����������� ��� ������� ����

	}

	public: System::Void fillField() { // �������, ������� ��������� ������� ������� ����� �� ����
		this->movePlayerInfoLabel->Text = ((this->game->whiteMove()) ? "�����" : "������") + " ����� �����";
		
		auto field = this->game->getField();

		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					gameContainer->Controls[i]->Controls[j * 3 + k]->BackgroundImage = getImageByIndex(field[i][j][k]);
				}
			}
		}

		winCheck();
	}

	private: System::Void winCheck() {
		auto status = this->game->checkGame();
		if (status == 0) return; // ���� �� � ���� ���� 5 �����, �� �������� ������������ � ��������, ���� ���-�� �� ������� �� ��������

		if (status == 1)
			MessageBox::Show(L"����� ����� �������"); // ��������� ��������� �� ����� ����������, ����� ����� 1 �������
		if (status == 2)
			MessageBox::Show(L"׸���� ����� �������"); // ��������� ��������� �� ����� ����������, ����� ����� 2 �������
		if (status == 3)
			MessageBox::Show(L"�����"); // ��������� ��������� �� ����� ����������, ����� ����� �� �������


		Close();
	}

	private: System::Void RotatePanel(bool visible) {
		rotate1->Visible = visible;
		rotate2->Visible = visible;
		rotate3->Visible = visible;
		rotate4->Visible = visible;
	}

	private: System::Void CellClick(System::Object^ sender, System::EventArgs^ e) {
		if (rotate1->Visible) return;

		auto button = (Button^)sender;
		auto points = button->Name->Split(' ');

		int i = Convert::ToInt32(points[0]);
		int j = Convert::ToInt32(points[1]);
		int k = Convert::ToInt32(points[2]);

		if (!this->game->move(i, j, k, false)) return;

		RotatePanel(true);
	}

	private:  System::Windows::Forms::Button^ CreateCell(int i, int j, int k) { // ������� ��� �������� ������
		auto button = gcnew Button();

		button->Size = System::Drawing::Size(100, 100);
		button->BackgroundImageLayout = ImageLayout::Stretch;
		button->Margin = System::Windows::Forms::Padding(0);
		button->FlatStyle = FlatStyle::Flat;
		button->Name = Convert::ToString(i) + " " + Convert::ToString(j) + " " + Convert::ToString(k);
		button->Click += gcnew System::EventHandler(this, &MyForm4::CellClick);

		return button;
	}

	private: System::Windows::Forms::TableLayoutPanel^ CreateInnerTable() {
		auto innerTable = gcnew TableLayoutPanel();
		// innerTable - ��� ���������, �� �������� ������� �������� ������� ���� (�� ���� ���� ��������� �� 4 ���������)
		innerTable->ColumnCount = 3;
		innerTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50))); // �������� ������ ��������	
		innerTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
		innerTable->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent, 50)));
		innerTable->Location = System::Drawing::Point(10, 10);
		innerTable->RowCount = 3;
		innerTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
		innerTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
		innerTable->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
		innerTable->Size = System::Drawing::Size(300, 300);

		return innerTable;
	}

	private: System::Void MyForm4_Load(System::Object^ sender, System::EventArgs^ e) { // �������, ������� ��������� ��� ���� ������� �������� (0, � �� 1 ��� 2, ��� ��� 0 - ��� ������ ������, � 1 ��� 2 - �����)
		for (int i = 0; i < 4; i++) {
			auto innerTable = CreateInnerTable();
			gameContainer->Controls->Add(innerTable);
			for (int j = 0; j < 3; j++) {
				for (int k = 0; k < 3; k++) {
					auto cell = CreateCell(i, j, k);
					gameContainer->Controls[i]->Controls->Add(cell);
				}
			}
		}
		RotatePanel(false);
	fillField();
	}

	private: System::Void fillHandler(System::Object^ sender, System::EventArgs^ e) {
		fillField();
	}

	private: System::Void afterRotate() {
		RotatePanel(false); // ��������� ������ ��������(������, ������� ��������� � ���� ������ �������� �� ��������)

		winCheck();
	}

	private: System::Void rotate1_Click(System::Object^ sender, System::EventArgs^ e) { // ������� �������� ������ ������� ���������
		if (!this->game->rotate(0, true, false)) return;

		afterRotate();
	}
	private: System::Void rotate2_Click(System::Object^ sender, System::EventArgs^ e) { // ������� �������� ������ ������� ���������
		if (!this->game->rotate(1, true, false)) return;

		afterRotate();
	}
	private: System::Void rotate3_Click(System::Object^ sender, System::EventArgs^ e) { // ������� �������� ������� ������� ���������
		if (!this->game->rotate(2, true, false)) return;

		afterRotate();
	}
	private: System::Void rotate4_Click(System::Object^ sender, System::EventArgs^ e) { // ������� �������� ��������� ������� ���������
		if (!this->game->rotate(3, true, false)) return;

		afterRotate();
	}
private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Close();
	/*MyForm tt;
	tt.ShowDialog();*/
}
private: System::Void gameContainer_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void movePlayerInfoLabel_Click(System::Object^ sender, System::EventArgs^ e) {
}
};
}