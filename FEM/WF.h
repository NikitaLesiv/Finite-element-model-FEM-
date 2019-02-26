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
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для WF
	/// </summary>
	public ref class WF : public System::Windows::Forms::Form
	{
	public:
		WF(void)
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
	private: System::Windows::Forms::TextBox^ textBox3;

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
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(854, 96);
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
			this->textBox1->Size = System::Drawing::Size(219, 20);
			this->textBox1->TabIndex = 3;
			this->textBox1->Text = L"0.01";
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(929, 43);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(53, 20);
			this->textBox2->TabIndex = 5;
			this->textBox2->Text = L"5000";
			this->textBox2->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(931, 27);
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
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(704, 170);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(599, 415);
			this->textBox3->TabIndex = 7;
			// 
			// WF
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1351, 620);
			this->Controls->Add(this->textBox3);
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
		Graphics ^g = pictureBox1->CreateGraphics();
		g->Clear(Color::White);		
		const int x_res = 600, y_res = 600, scale = 600; // Разрешение и масштаб

		int N = 15;
		polygon ^pol = gcnew polygon(); 
		List <point^>^ points = gcnew List <point^>;
		
		double df = 2 * Pi / N, x, y, x0 = 300, y0 = 300, R = 300;

		for (int i = 0; i < N; i++) 
		{
			x = R * cos(i * df) + x0;
			y = R * sin(i * df) + y0;
			points->Add(gcnew point(x, y));
		}

		pol->points->AddRange(points);
		List <polygon ^> ^polygons = gcnew List <polygon ^>;
		polygons->Add(pol);			
		List <triangle^>^ triangles = to_triangle(triangulation(polygons, 300));
		
		textBox1->Text = Convert::ToString(triangles->Count);
		mesh^ mesh1 = gcnew mesh();
		mesh1->set(triangles);

		String^ varstr;
		
/*
		circle^ circ = triangles[10]->circumscribed_circle();
		circ->color = "black";
		circ->show(g, x_res, y_res, scale, 2);

		for each (triangle ^tr in triangles) // Отображение списка треугольников (отображает список triangles)
		{
			List <line ^> ^lines = tr->list_of_border_lines();
		
			if (!true)
			{
				circle^ c = tr->circumscribed_circle();
				c->color = "green";
				c->show(g, x_res, y_res, scale, 2);
			}
			
			point^ t_point = tr->get_center();

			if (circ->the_point_enters_the_circle(t_point))
			{
				t_point->color = "red";
			}
			else
			{
				t_point->color = "orange";
			}
			
			t_point->show(g, x_res, y_res, scale, 8);	
		
			for each (line ^l in lines)
			{
				l->color = "Blue";
				l->p_s->color = "Green";
				l->p_f->color = "Green";
				l->p_s->show(g, x_res, y_res, scale, 8);
				l->p_f->show(g, x_res, y_res, scale, 8);
				l->show(g, x_res, y_res, scale, 2);
			}


		}
*/

		for each (array <Int32>^ tmpar in mesh1->rules)
		{
			varstr = Convert::ToString(tmpar[0]+ " " + tmpar[1] + " "+tmpar[2]);
			textBox3->AppendText(varstr + "\n");
		}

/*	for each (point^ t in mesh1->points)
		{
			varstr = "";
			for each (Int32 ^ N1 in t->Triangles_Numbers)
			{
				varstr += Convert::ToString(N1+" ");
			}
						
			textBox3->AppendText(varstr + "\n");
		}

*/
		
		for each (triangle ^ tr in triangles) // Отображение списка треугольников (отображает список triangles)
		{
			List <line^>^ lines = tr->list_of_border_lines();
			String^ value = Convert::ToString(triangles->IndexOf(tr)+"\n");
			textBox3->AppendText(value);
			for each (line ^ l in lines)
			{
				l->color = "Red";
				l->p_s->color = "Red";
				l->p_f->color = "Red";
				l->p_s->show(g, x_res, y_res, scale, 8);
				l->p_f->show(g, x_res, y_res, scale, 8);
				l->show(g, x_res, y_res, scale, 2);
			}
		}
/*		textBox3->AppendText("--------------------------------------------\n");
		for each (String^ value in mesh1->values)
		{
			textBox3->AppendText(value + "\n"+"---------------------------"+"\n");
		}
*/
	}

};
}
