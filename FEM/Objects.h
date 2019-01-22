#pragma once
#include <string>

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

public ref class point
{
public:
	double x = 0, y = 0;
	String^ color = "Black";

	point() // Конструктор
	{

	}
	point(double x_, double y_) // Конструктор
	{
		x = x_;
		y = y_;
	}
	point(double x_, double y_, String^ color_) // Конструктор
	{
		x = x_;
		y = y_;
		color = color_;
	}

	void show(Graphics^ g, int resolutions_x, int resolutions_y, double scale, int diameter)
	{
		SolidBrush^ brush = gcnew SolidBrush(Color::FromName(color));
		
		int x_px = (int)(x * resolutions_x / scale) - diameter / 2;
		int y_px = (int)(y * resolutions_y / scale) - diameter / 2;

		g->FillEllipse(brush, x_px, y_px, diameter, diameter);
	}

	point^ operator= (point^ p)
	{
		point^ tmp;
		tmp->x = p->x;
		tmp->y = p->y;
		color = p->color;

		return tmp;
	}

	~point() // Деструктор
	{

	}
};

public ref class line
{
public:
	point^ p_s = gcnew point(0, 0);
	point^ p_f = gcnew point(1, 1);
	String^ color = "Black";

	line() // Конструктор
	{
	
	}
	line(point^ p_s_, point^ p_f_) // Конструктор
	{
		p_s = p_s_;
		p_f = p_f_;
	}
	line(point^ p_s_, point^ p_f_, String^ color_) // Конструктор
	{
		p_s = p_s_;
		p_f = p_f_;
		color = color_;
	}

	void show(Graphics^ g, int resolutions_x, int resolutions_y, double scale, float width)
	{
		Pen^ pen = gcnew Pen(Color::FromName(color), width);

		int x_s_px = (int)(p_s->x * resolutions_x / scale);
		int y_s_px = (int)(p_s->y * resolutions_y / scale);
		int x_f_px = (int)(p_f->x * resolutions_x / scale);
		int y_f_px = (int)(p_f->y * resolutions_y / scale);

		g->DrawLine(pen, x_s_px, y_s_px, x_f_px, y_f_px);
	}

	line^ operator= (line^ l)
	{
		line^ tmp;

		tmp->p_s = l->p_s;
		tmp->p_f = l->p_f;
		tmp->color = l->color;

		return tmp;
	}

	~line() // Деструктор
	{

	} 
};

public ref class triangle
{
public:
	point^ p_1 = gcnew point(1, 1);
	point^ p_2 = gcnew point(2, 2);
	point^ p_3 = gcnew point(3, 4);
	String^ color = "Black";

	triangle() // Конструктор
	{

	}
	triangle(point^ p_1_, point^ p_2_, point^ p_3_) // Конструктор
	{
		p_1 = p_1_;
		p_2 = p_2_;
		p_3 = p_3_;
	}
	triangle(point^ p_1_, point^ p_2_, point^ p_3_, String^ color_) // Конструктор
	{
		p_1 = p_1_;
		p_2 = p_2_;
		p_3 = p_3_;
		color = color_;
	}

	void show(Graphics^ g, int resolutions_x, int resolutions_y, double scale)
	{
		SolidBrush^ brush = gcnew SolidBrush(Color::FromName(color));

		int x_1_px = (int)(p_1->x * resolutions_x / scale);
		int y_1_px = (int)(p_1->y * resolutions_y / scale);
		int x_2_px = (int)(p_2->x * resolutions_x / scale);
		int y_2_px = (int)(p_2->y * resolutions_y / scale);
		int x_3_px = (int)(p_3->x * resolutions_x / scale);
		int y_3_px = (int)(p_3->y * resolutions_y / scale);

		array <Point>^ points = { Point(x_1_px, y_1_px), Point(x_2_px, y_2_px), Point(x_3_px, y_3_px) };

		g->FillPolygon(brush, points);
	}

	~triangle() // Деструктор
	{

	}
};
