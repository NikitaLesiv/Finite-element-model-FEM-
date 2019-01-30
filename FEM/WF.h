#pragma once
#include <cmath>
#include "Objects.h"
#include "Functions.h"


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
		Pen^ myPen = gcnew Pen(Color::Red, 2);
		g->Clear(Color::White);

		int x_res = 600, y_res = 600, scale = 600; // ���������� � �������

		point^ p1 = gcnew point(230, 100);
		point^ p2 = gcnew point(500, 225);
		point^ p3 = gcnew point(100, 500);

		triangle^ t = gcnew triangle(p1, p2, p3);

		circle^ c = t->circumscribed_circle();
		c->color = "blue";

		t->show(g, x_res, y_res, scale);
		c->show(g, x_res, y_res, scale, 2);
		
	/*
		//g->DrawEllipse(myPen, 0, 0, 560, 560);
	
		array <line^ , 2>^ lines  = gcnew array<line^ , 2>(200, 200);
		
		// double Rc = 280, d = 1, d1;
		double x, y, r; // , alpha;

		int N = 100; // ����� ����� �� �������
		double R = 300; // ������ ����������

		//array <point^, 2>^ points = gcnew array<point^, 2>(N, N);
		array <point^>^ points = gcnew array<point^>(N + 1);

		
		double dr = R / 10;

		for (double r = 0; r <= R; r += dr)
		{
			int n = N * r / R + 1;
			double d_phi = 2 * Pi / n;

			for (int i = 0; i < n; i++)
			{
				x = r * cos(i * d_phi) + R;
				y = r * sin(i * d_phi) + R;

				if (r == R)
				{
					points[i] = gcnew point(x, y, "blue");
					points[i]->border = true;
				}
				else
				{
					points[i] = gcnew point(x, y, "red");
				}
				points[i]->show(g, x_res, y_res, scale, 8);

			}
		}
		
	*/	
		
	/*


		for (int i = 0; i < 60; i++)
		{
			for (int j = 0; j < 60; j++)
			{

				x = 280 - i * 10;
				y = 280 - j * 10;
				r = sqrt(x * x + y * y);
				if (y > 0)
				{
					alpha = acos(x / r);
				}
				else
				{
					alpha = 2 * Pi - acos(x / r);
				}

				d1 = d * (1 + pow(cos(2*(alpha - Pi / 4)),2));

				if (abs(r - Rc) < d1)
				{

					x = Rc * cos(alpha);
					y = Rc * sin(alpha);
					
					points[i, j] = gcnew point(x + Rc, y + Rc);
					points[i, j]->color = "blue";
					points[i, j]->border = true;
					points[i, j]->show(g, 600, 600, 600, 8);
				}

				if (r < Rc-d1)
				{
					points[i, j] = gcnew point(x +Rc, y+Rc);
					points[i, j]->color = "red";
					points[i, j]->border = false;
					points[i, j]->show(g,600,600,600,3);
				}

			}
		}
	*/
	}
};
}
