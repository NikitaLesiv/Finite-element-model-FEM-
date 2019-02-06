#pragma once
#include <cmath>
#include <string>
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




		Graphics ^g = pictureBox1->CreateGraphics();
		g->Clear(Color::White);	
		
		const int x_res = 600, y_res = 600, scale = 600; // Разрешение и масштаб

		int N = 30;

		polygon ^pol = gcnew polygon(); 
		pol->points->Clear();

		

		double df = 2 * Pi / N, x, y, x0 = 300, y0 = 300, R = 250,r,x1,y1;
		int N1, N2, N3, N4, Ncount,row;

		for (int i = 0; i < N; i++) 
		{
			x = R * cos(i * df) + x0;
			y = R * sin(i * df) + y0;
			pol->points->Add(gcnew point(x, y, "red"));
		}
	/*	
		pol->points->Add(gcnew point(50, 50, "red"));
		pol->points->Add(gcnew point(50, 100, "red"));
		pol->points->Add(gcnew point(50, 200, "red"));
		pol->points->Add(gcnew point(100, 150, "red"));
		pol->points->Add(gcnew point(100, 100, "red"));
		pol->points->Add(gcnew point(80, 80, "red"));
		
*/
		List <polygon ^> ^polygons = gcnew List <polygon ^>;
		array <point ^,2> ^points1 = gcnew array <point ^,2>(50,50);
		array <line ^,2> ^line1 = gcnew array <line ^,2>(50,50);
		array <line ^, 2> ^line2 = gcnew array <line ^, 2>(50, 50);
		array <line ^, 2> ^line3 = gcnew array <line ^, 2>(50, 50);

		Ncount = 50;
		for (int i=0; i< Ncount; i++)
		{
			for (int j = 0; j < Ncount; j++)
			{
				x = 5 + i * 12;
				y = 5 + j * 12;
				x1 = x - x0;
				y1 = y - y0;
				r = sqrt(x1 * x1 + y1 * y1);
				
				points1[i,j] = gcnew point(x, y);
				points1[i, j]->N = -1;
				if (r < R) 
				{
				points1[i, j]->show(g, 600, 600, 600, 5);
				points1[i, j]->N = 1;
				}
				
			}

		}
		for (int i = 0; i < Ncount-1; i++)
		{
			for (int j = 0; j < Ncount-1; j++)
			{
				int n = i*row + j;

				N1 = points1[i, j]->N;
				N2 = points1[i+1, j]->N;
				N3 = points1[i, j+1]->N;
				N4 = points1[i+1, j+1]->N;
				
				if (N1>0 && N2>0)
				{
				line1[i, j] = gcnew line(points1[i,j], points1[i+1,j]);
				line1[i, j]->show(g, 600, 600, 600, 2);
				}
				if (N1 > 0 && N3 > 0)
				{
					line2[i, j] = gcnew line(points1[i, j], points1[i, j+1]);
					line2[i, j]->show(g, 600, 600, 600, 2);
				}
				if (N1 > 0 && N4 > 0)
				{
					line3[i, j] = gcnew line(points1[i, j], points1[i + 1, j+1]);
					line3[i, j]->show(g, 600, 600, 600, 2);
				}
				//
				//if (N1>0 && N3>0)	
				//{ 
				 //   line1->Add(gcnew line(points1[n], points1[n + Ncount]));
				//}
				//if (N1 > 0 && N4 > 0) 
				//{
				//line1->Add(gcnew line(points1[n], points1[n + Ncount+1]));
				//}

			}

		}


		
		polygons->Add(pol);

		List <polygon ^> ^pols = polygons;//triangulation(polygons, 150);
/*
		polygon ^p1 = ((polygons[0]->bisection(10))[0]->bisection(10))[0];
		polygon ^p2 = ((polygons[0]->bisection(10))[0]->bisection(10))[1];
		polygon ^p3 = ((polygons[0]->bisection(10))[1]->bisection(10))[0];
		polygon ^p4 = ((polygons[0]->bisection(10))[1]->bisection(10))[1];
*/
		

	

		textBox1->Text = Convert::ToString(pols->Count);

		for each (polygon ^p in pols)
		{
			List <line ^> ^lines = p->list_of_border_lines();

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

         

/*
		point^ p1 = gcnew point(5, 5, "red");
		point^ p2 = gcnew point(400, 400, "red");
		point^ p3 = gcnew point(5, 100, "red");
		point^ p4 = gcnew point(5, 400, "red");

		line^ l1 = gcnew line(p1, p2, "blue");
		line^ l2 = gcnew line(p3, p4, "red");

		if (l1->intersect(l2)) 
		{
			point^ p5 = l1->intersection_point(l2);
			l1->show(g, x_res, y_res, scale, 5);
			l2->show(g, x_res, y_res, scale, 5);
			p5->show(g, x_res, y_res, scale, 8);
		}
*/
		/*
		point^ p1 = gcnew point(50, 150, "red");
		point^ p2 = gcnew point(100, 200, "red");
		point^ p3 = gcnew point(300, 200, "red");
		triangle^ t = gcnew triangle(p1, p2, p3, "blue");
		t->show(g,x_res, y_res, scale);
		p1->show(g, x_res, y_res, scale, 8);
		p2->show(g, x_res, y_res, scale, 8);
		p3->show(g, x_res, y_res, scale, 8);
		circle^ c1 = t->circumscribed_circle();
		c1->show(g, x_res, y_res, scale, 8);
		*/
		/*
		double x, y, r; // , alpha;

		int N = 100; // Число точек на границе
		double R = 300; // Радиус окружности
		
		array <point ^> ^points = gcnew array<point ^>(N + 2);
		array <line  ^> ^lines  = gcnew array<line  ^>(N + 2);
		
		double dr = R / 10;

		for (double r = 0; r <= R; r += dr)
		{
			int n = N * r / R + 1;
			double d_phi = 2 * Pi / n;

			for (int i = 0; i <= n; i++)
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

				if (i != 0)
				{
					lines[i] = gcnew line(points[i - 1], points[i], "green");
					lines[i]->show(g, x_res, y_res, scale, 2);
				}

				points[i]->show(g, x_res, y_res, scale, 8);	
			}
		}
	*/	
	/*
		Pen^ myPen = gcnew Pen(Color::Red, 2);
		g->DrawEllipse(myPen, 0, 0, 560, 560);
		array <line^ , 2>^ lines  = gcnew array<line^ , 2>(200, 200);
		//array <point ^, 2> ^points = gcnew array<point ^, 2>(N, N);
		double Rc = 280, d = 1, d1;

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
