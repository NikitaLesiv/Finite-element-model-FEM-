#pragma once

namespace FEM
{

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� WF
	/// </summary>
	public ref class WF : public System::Windows::Forms::Form
	{
	public:
		WF(void)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~WF()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::PictureBox^  pictureBox1;


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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(704, 97);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(128, 38);
			this->button1->TabIndex = 1;
			this->button1->Text = L"Jmi menya";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &WF::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(707, 27);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(18, 13);
			this->label1->TabIndex = 2;
			this->label1->Text = L"dx";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(704, 43);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(37, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"0.01";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(779, 43);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(53, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"5000";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(781, 27);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(15, 13);
			this->label2->TabIndex = 4;
			this->label2->Text = L"N";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(12, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 600);
			this->pictureBox1->TabIndex = 6;
			this->pictureBox1->TabStop = false;
			// 
			// WF
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1042, 620);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button1);
			this->Name = L"WF";
			this->Text = L"WF";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		
////////////////////////////////////////////////////////////////////////////////////////////////////

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		Graphics^ g = pictureBox1->CreateGraphics();
		SolidBrush^ myBrush = gcnew SolidBrush(Color::Yellow);
		Pen^ myPen = gcnew Pen(Color::Red, 2);
		Pen^ myPen2 = gcnew Pen(Color::Blue, 2);

		g->Clear(Color::White);
		array <Point>^ points = { Point(100,200), Point(200,300), Point(300,100) }; //������ �������������� ������ point

		g->DrawEllipse(myPen, 0, 0, 600, 600);

		point^ p1 = gcnew point(3, 3, "Green");
		point^ p2 = gcnew point(5, 5, "Blue");
		point^ p3 = gcnew point(1, 2, "Yellow");
		
		line^ l1 = gcnew line(p1, p2, "Red");
		line^ l2 = gcnew line(p1, p3, "Red");
		line^ l3 = gcnew line(p2, p3, "Red");

		triangle^ t = gcnew triangle(p1, p2, p3, "Cyan");

		p1->show(g, 600, 600, 6, 10);
		p2->show(g, 600, 600, 6, 10);
		p3->show(g, 600, 600, 6, 10);

		l1->show(g, 600, 600, 6, 2);
		l2->show(g, 600, 600, 6, 2);
		l3->show(g, 600, 600, 6, 2);
		
		t->show(g, 600, 600, 6);
		
		
/*
		double x, y, r;
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 30; j++)
			{

				x = 300 - i * 20;
				y = 300 - j * 20;
				r = sqrt(x * x + y * y);

				if (r <= 300)
				{
					g->DrawEllipse(myPen, i * 20, j * 20, 1, 1);
					if (i % 1 == 0)
					{
						g->DrawLine(myPen2, i * 20, j * 20, i * 20 + 20, j * 20 + 20);
						g->DrawLine(myPen2, i * 20, j * 20, i * 20, j * 20 + 20);
						g->DrawLine(myPen2, i * 20, j * 20, i * 20 + 20, j * 20);
						g->DrawLine(myPen2, i * 20, j * 20, i * 20 - 20, j * 20 - 20);
						g->DrawLine(myPen2, i * 20, j * 20, i * 20, j * 20 - 20);
						g->DrawLine(myPen2, i * 20, j * 20, i * 20 - 20, j * 20);
					}


				}

			}
		}*/
	}
};
}
